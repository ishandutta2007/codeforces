//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 1000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,ans;
pa tr[N<<2];
int tag[N<<2];
int x[N],y[N],val[N];
vector<int>g,G[N];
int m;
int ansx,ansy;
void pushup(int k)
{
	tr[k]=max(tr[k<<1],tr[k<<1|1]);
}
void pushdown(int k)
{
	if (!tag[k]) return;
	tr[k<<1].fi+=tag[k];
	tr[k<<1|1].fi+=tag[k];
	tag[k<<1]+=tag[k];
	tag[k<<1|1]+=tag[k];
	tag[k]=0;
}
void build(int k,int l,int r)
{
	tag[k]=0;
	if (l==r)
	{
		tr[k]={0,l};
		return;
	}
	int mid=l+(r-l)/2;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
void update(int k,int l,int r,int L,int R,int val)
{
//	cout<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
	if (L>R) return;
	if (L<=l&&r<=R)
	{
		tr[k].fi+=val;
		tag[k]+=val;
		return;
	}
	int mid=l+(r-l)/2;
	pushdown(k);
	if (L<=mid) update(k<<1,l,mid,L,R,val);
	if (R>mid) update(k<<1|1,mid+1,r,L,R,val);
	pushup(k);
}
pa query(int k,int l,int r,int L,int R)
{
	if (L>R) return {-inf,0};
	if (L<=l&&r<=R) return tr[k];
	pushdown(k);
	int mid=l+(r-l)/2;
	pa res={-inf,0};
	if (L<=mid) res=max(res,query(k<<1,l,mid,L,R));
	if (R>mid) res=max(res,query(k<<1|1,mid+1,r,L,R));
	return res;
}
signed main()
{
	ans=-inf;
	n=read();
	for (int i=1;i<=n;i++)
	{
		x[i]=read(),y[i]=read();
		val[i]=read();
		g.push_back(x[i]);
		g.push_back(y[i]);
	}
	sort(g.begin(),g.end());
	g.erase(unique(g.begin(),g.end()),g.end());
	g.push_back(g[g.size()-1]+1);
	for (int i=1;i<=n;i++)
	{
		x[i]=lower_bound(g.begin(),g.end(),x[i])-g.begin()+1;
		y[i]=lower_bound(g.begin(),g.end(),y[i])-g.begin()+1;
		G[max(x[i],y[i])].push_back(i);
	}
	m=g.size();
	build(1,1,m);
//	return 0;
	for (int i=1;i<=m;i++)
	{
		update(1,1,m,1,i-1,-(g[i-1]-((i==1)?0ll:g[i-2])));
		for (auto u:G[i])
		{
			update(1,1,m,1,min(x[u],y[u]),val[u]);
//			cout<<"ad gongxian"<<u<<endl;
		}
		pa u=query(1,1,m,1,i);
//		cout<<"?"<<u.fi<<" "<<g[i-1]<<endl;
		if (u.fi>ans)
		{
			ans=u.fi;
			ansx=g[u.se-1],ansy=g[i-1];
		}
	}
	writeln(ans);
	writesp(ansx),writesp(ansx);
	writesp(ansy),writesp(ansy);
}
/*

*/