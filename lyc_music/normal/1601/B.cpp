//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
//#define int ll
#define N 2000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
priority_queue<pa>q;
int dep[N],nod1[N],nod[N];
int mxnod;
int lst[N];
int dis[N];
vector<pa>G[N];
int now,ans1;
int n;
int a[N],b[N];
vector<int>ans;
void ad(int x,int y,int w)
{
	G[x].push_back({y,w});
}
void build(int k,int l,int r)
{
	dep[k]=-1;
	if (l==r)
	{
		mxnod=max(mxnod,k);
		nod[l]=k;
		dep[k]=l;
		return;
	}
	int mid=l+(r-l)/2;
	ad(k,k<<1,0);
	ad(k,k<<1|1,0);
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
void update(int k,int l,int r,int L,int R,int nd)
{
//	cout<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
	if (L<=l&&r<=R)
	{
		ad(nd,k,1);
		return;
	}
	int mid=l+(r-l)/2;
	if (L<=mid) update(k<<1,l,mid,L,R,nd);
	if (R>mid) update(k<<1|1,mid+1,r,L,R,nd);
}
void dijk()
{
	memset(dis,0x3f,sizeof(dis));
	dis[nod1[n]]=0;
	q.push({0,nod1[n]});
	while (!q.empty())
	{
		int u=q.top().se;
//		cout<<u<<" "<<dis[u]<<endl;
		q.pop();
		for (auto U:G[u])
		{
			int v=U.fi,w=U.se;
			if (dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				lst[v]=u;
				q.push({-dis[v],v});
			}
		}
	}
}
signed main()
{
	n=read();
	ans1=inf;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	build(1,1,n);
//	return 0;
	for (int i=1;i<=n;i++) nod1[i]=mxnod+i,dep[mxnod+i]=-1;
	for (int i=1;i<=n;i++)
		if (i-a[i]>0&&i-a[i]<i) update(1,1,n,i-a[i],i-1,nod1[i]);
	for (int i=1;i<=n;i++) ad(nod[i],nod1[i+b[i]],0);
//	return 0;
	dijk();
	for (int i=1;i<=n;i++)
		if (i-a[i]<=0)
		{
//			cout<<dis[nod1[i]]<<endl;
			if (dis[nod1[i]]<ans1)
			{
				ans1=dis[nod1[i]];
				now=nod1[i];
			}
		}
	if (ans1==inf) return puts("-1"),0;
	while (now!=nod1[n])
	{
//		cout<<now<<","<<dep[now]<<endl;
		if (~dep[now]) ans.push_back(dep[now]);
		now=lst[now];
	}
//	ans.push_back(n);
	reverse(ans.begin(),ans.end());
	ans.push_back(0);
	writeln(ans.size());
	for (auto u:ans) writesp(u);	
}
/*

*/