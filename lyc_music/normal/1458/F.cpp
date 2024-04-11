//~~
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int tr[N],P[N],siz[N];
int s[N];
int sdp[N];
int lson[N],rson[N];
#define isroot(x) (lson[fa[x]]!=x&&rson[fa[x]]!=x)
int son[N];
int sum1[N];
int sum[N],a[N];
int fa[N];
int f[N];
int dep[N];
vector<int>G[N];
int n,m;
int st[N][25];
vector<pa>Qr[N];
int sr[N];
int ans;
inline void ad(int x,int y)
{
	G[x].push_back(y);
}
void dfs(int k,int fa)
{
	dep[k]=dep[fa]+1;
	siz[k]=1;
	st[k][0]=fa;
	for (int i=1;i<=20;i++)
		st[k][i]=st[st[k][i-1]][i-1];
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k),siz[k]+=siz[u];
		if (siz[u]>siz[son[k]])son[k]=u;
	}
}
int lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=20;i>=0;i--)
		if (dep[st[x][i]]>=dep[y]) x=st[x][i];
	if (x==y) return x;
	for (int i=20;i>=0;i--)
		if (st[x][i]!=st[y][i]) x=st[x][i],y=st[y][i];
	return st[x][0];
}
inline void pushup(int x)
{
	sum[x]=sum[lson[x]]+sum[rson[x]]+a[x]*tr[x]+sum1[x];
}
int work(int l,int r)
{
	if (l>r) return 0;
	if (l==r)
	{
		tr[P[l]]=1;
		return P[l];
	}
	int nowl=l,nowr=r,now=l;
	while (nowl<=nowr)
	{
		int mid=nowl+(nowr-nowl)/2;
		if (2*(s[mid]-s[l-1])<=s[r]-s[l-1])
		{
			now=mid;
			nowl=mid+1;
		} else nowr=mid-1;
	}
	lson[P[now]]=work(l,now-1);
	rson[P[now]]=work(now+1,r);
	if (lson[P[now]]) fa[lson[P[now]]]=P[now];
	if (rson[P[now]]) fa[rson[P[now]]]=P[now];
	tr[P[now]]=r-l+1;
	return P[now];
}
int build(int x)
{
	int now=x;
	vector<int>p;
	while (1)
	{
		p.push_back(now);
		if (!son[now]) break;
		for (auto u:G[now])
			if (u!=son[now]&&u!=st[now][0])
				fa[build(u)]=now;
		now=son[now];
	}
	for (int i=1;i<=p.size();i++)
		P[i]=p[i-1],s[i]=s[i-1]+siz[P[i]]-siz[son[P[i]]];
	return work(1,p.size());
}
inline void add(int x,int y)
{
	int lst=0,now=x;
	while (x)
	{
		if (dep[x]<=dep[now])
		{
			sum1[x]+=y;
			if (lson[x]&&lst!=lson[x])
			{
				a[lson[x]]+=y;
			}
			pushup(lson[x]);
		}
		pushup(x);
		lst=x;
		if (isroot(x)) now=fa[x];
		x=fa[x];
	}
}
inline int query(int x)
{
	int res=0;
	int now=x;
	int nowtt=0;
	int lst=0;
	while (x)
	{
		if (dep[x]<=dep[now])
		{
			if (lson[x]&&lson[x]!=lst)
			{
				res+=sum1[x]+sum[lson[x]];
				nowtt+=tr[lson[x]]+1;
			}
			else 
			{
				res+=sum1[x];
				nowtt+=1;
			}	
		}
		res+=a[x]*nowtt;
		lst=x;
		if (isroot(x)) nowtt=0,now=fa[x];
		x=fa[x];
	}
	return res;
}
int walk(int x,int y,int len)
{
	int z=lca(x,y);
	if (dep[x]-len>=dep[z])
	{
		for (int i=20;i>=0;i--)
			if ((len>>i)&1) x=st[x][i];
		return x;
	}
	len-=(dep[x]-dep[z]);
	len=(dep[y]-dep[z]-len);
	for (int i=20;i>=0;i--)
		if ((len>>i)&1) y=st[y][i];
	return y;
}
struct circ
{
	int po,r;
	circ(int a=0,int b=0){po=a,r=b;}
}C[N];
int dis(int x,int y)
{
	int z=lca(x,y);
	return dep[x]+dep[y]-dep[z]*2;
}
void ins(circ &c,int u)
{
	int nowds=dis(c.po,u);
	if (nowds<=c.r) return;
	c=circ(walk(c.po,u,(nowds-c.r)/2),(nowds+c.r)/2);
}
bool in(circ x,circ y)
{
	// if (x.r<y.r) return 0;
	if (dis(x.po,y.po)+y.r<=x.r) return 1;
	return 0;
}
void solve(int l,int r)
{
	// cout<<l<<" "<<r<<endl;
	if (l==r) return;
	int mid=l+(r-l)/2;
	solve(l,mid);
	solve(mid+1,r);
	C[mid]=circ(mid,0);
	C[mid+1]=circ(mid+1,0);
	for (int i=mid-1;i>=l;i--)
	{
		C[i]=C[i+1];
		ins(C[i],i);
		// cout<<mid<<","<<i<<" "<<C[i].r<<" "<<C[i].po<<endl;
	}
	sr[mid]=0;
	sr[mid+1]=0;
	sdp[mid]=0;
	for (int i=mid+2;i<=r;i++)
	{
		C[i]=C[i-1];     
		ins(C[i],i);
		// cout<<mid+1<<","<<i<<" "<<C[i].r<<" "<<C[i].po<<" "<<endl;
		sr[i]=sr[i-1]+C[i].r;
	}
	for (int i=mid+1;i<=r;i++) sdp[i]=sdp[i-1]+dep[C[i].po];
	int r1=mid,r2=mid;
	// cnt=0;
	int ans1=0;
	for (int i=mid;i>=l;i--)
	{
		while(r1+1<=r&&in(C[i],C[r1+1])) r1++;
		while(r2+1<=r&&!in(C[r2+1],C[i])) r2++;
		r2=max(r2,r1);
		ans+=2*(C[i].r)*(r1-mid)+(sr[r]-sr[r2])*2;
		// f[i]=0;
		// cout<<i<<" "<<r1<<"   "<<r2<<" "<<in(C[r],C[i])<<endl;
		ans1+=sdp[r2]-sdp[r1]+dep[C[i].po]*(r2-r1)+C[i].r*(r2-r1)+(sr[r2]-sr[r1]);
		
		// cout<<ans1<<".."<<dep[C[r2].po]<<" "<<C[r2].po<<" "<<C[i].r*(r2-r1)+(sr[r2]-sr[r1])<<endl;
		// cout<<"??"<<sdp[r2]-sdp[r1-1]<<" "<<dep[i]*(r2-r1+1)<<endl;
		// cout<<C[i].
		if (r2>=mid+1) Qr[r2].push_back(mp(C[i].po,1));
		if (r1>=mid+1)
			Qr[r1].push_back(mp(C[i].po,-1));
	}
	// cout<<"cpt "<<l<<" "<<r<<" "<<ans<<" "<<ans1<<endl;
	for (int i=mid+1;i<=r;i++)
	{
		add(C[i].po,1);
		// cout<<"ad "<<i<<" "<<1<<endl;
		for (auto u:Qr[i])
		{
			ans1+=-2*u.se*query(u.fi);
			// cout<<"qry "<<u.fi<<" "<<query(u.fi)<<endl;
		}
		Qr[i].clear();
	}
	ans+=ans1;
	// cout<<"cpt "<<l<<" "<<r<<" "<<ans<<" "<<ans1<<endl;
	for (int i=mid+1;i<=r;i++) add(C[i].po,-1);
}
void BellaKira()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		ad(x,n+i);
		ad(n+i,x);
		ad(y,n+i);
		ad(n+i,y);
	}
	dfs(1,0);
	for (int i=1;i<=n;i++)
		sdp[i]=sdp[i-1]+dep[i];
	build(1);
	// return;
	solve(1,n);
	writeln(ans>>1);
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/