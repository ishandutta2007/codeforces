#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=1000000+5,Infinity=((1<<30)-1);
int a[MaxN],b[MaxN],d[MaxN],k[MaxN],y[MaxN];
queue<int> que;
inline void Trace(const int n,const int u)
{
	if(u==n) return;
	Trace(n,k[u]);
	cout<<y[u]<<' ';
}
struct Connection_Set
{
	int fa[MaxN];
	inline void Initalize(const int n)
	{
		rep(i,1,n) fa[i]=i;
	}
	inline int getf(const int u)
	{
		if(u!=fa[u])
			fa[u]=getf(fa[u]);
		return fa[u];
	}
	inline void Merge(const int u,const int v)
	{
		const int fu=getf(u),fv=getf(v);
		if(fu!=fv) fa[fv]=fu;
	}
};
Connection_Set Con;
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int n;
	cin>>n,Con.Initalize(n+1);
	rep(i,1,n) cin>>a[i];
	rep(i,1,n) cin>>b[i];
	rep(i,1,n-1) d[i]=Infinity;
	que.push(n);
	Con.Merge(n+1,n);
	int u;
	bool Flag=false;
	while(!que.empty())
	{
		u=que.front(),que.pop();
		if(u<=a[u])
		{
			cout<<(d[u]+1)<<endl;
			Trace(n,u),cout<<0<<endl,Flag=true;
			break;
		}
		for(int i=(u-a[u]);i<=u;i=Con.getf(i))
		{
			int v=(i+b[i]);
			if(d[v]==Infinity)
			{
				d[v]=(d[u]+1);
				k[v]=u,y[v]=i;
				que.push(v);
			}
			Con.Merge(i+1,i);
		}
	}
	if(!Flag) cout<<(-1)<<endl;
	return 0;
}