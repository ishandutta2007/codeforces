#pragma GCC optimize("Ofast")
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<deque>
using std::min;
using std::sort;
using std::vector;
using std::deque;
const int inf=0x3f3f3f3f;
namespace mf
{
	const int N=1e5+5;
	int n,s,t,ans;
	struct edge
	{
		int v,w,inv;
		bool ex;
	};
	vector<edge> e[N];
	bool bk[N];
	inline edge &inv(edge ed)
	{
		return e[ed.v][ed.inv];
	}
	inline void add_edge(int u,int v,int w)
	{
		e[u].push_back(edge{v,w,(int)e[v].size(),1});
		e[v].push_back(edge{u,0,(int)e[u].size()-1,1});
		return;
	}
	int dfs(int x,int f)
	{
		if(x==t)
			return f;
		int tot=0,d;
		bk[x]=1;
		for(edge &ed:e[x])
			if(ed.ex&&ed.w&&!bk[ed.v]&&(d=dfs(ed.v,min(f-tot,ed.w))))
			{
				ed.w-=d;inv(ed).w+=d;
				if((tot+=d)==f)
					break;
			}
		return tot;
	}
	int idfs(int x,int f,int y)
	{
		if(x==s)
			return f;
		int tot=0,d;
		bk[x]=1;
		for(edge &ed:e[x])
			if(ed.ex&&ed.w&&!bk[ed.v]&&(x!=t||ed.v==y)&&(d=idfs(ed.v,min(f-tot,ed.w),y)))
			{
				ed.w-=d;inv(ed).w+=d;
				if((tot+=d)==f)
					break;
			}
		return tot;
	}
	inline void shrink(int x)
	{
		int f;
		while(memset(bk+1,0,sizeof(bool)*n),f=idfs(t,inf,x))
			ans-=f;
		for(edge &ed:e[x])
			if(ed.v==t)
				ed.ex=0,inv(ed).ex=0;
		add_edge(s,x,inf);
		while(memset(bk+1,0,sizeof(bool)*n),f=dfs(s,inf))
			ans+=f;
		return;
	}
}
const int N=205;
int n,cur;
long long ans;
int a[N][N],b[N*N];
vector<int> V;
inline int id(int x,int y)
{
	return (x-1)*n+y;
}
inline bool cmp(int x,int y)
{
	return b[x]<b[y];
}
signed main()
{
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]),b[id(i,j)]=a[i][j];
	mf::n=n*n+2;mf::s=n*n+1;mf::t=n*n+2;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(a[i][j]>0)
				V.push_back(id(i,j));
	sort(V.begin(),V.end(),cmp);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(a[i][j]>0)
				mf::add_edge(id(i,j),mf::t,inf);
	for(i=1;i<=n;i++)
		for(j=1;j<n;j++)
			if((~a[i][j])&&(~a[i][j+1]))
			{
				mf::add_edge(id(i,j),id(i,j+1),1);
				mf::add_edge(id(i,j+1),id(i,j),1);
			}
	for(i=1;i<n;i++)
		for(j=1;j<=n;j++)
			if((~a[i][j])&&(~a[i+1][j]))
			{
				mf::add_edge(id(i,j),id(i+1,j),1);
				mf::add_edge(id(i+1,j),id(i,j),1);
			}
	for(int x:V)
	{
		ans+=(long long)(b[x]-cur)*mf::ans;
		mf::shrink(x);cur=b[x];
	}
	printf("%lld\n",ans);
	return 0;
}