#include<cstdio>
#include<vector>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
constexpr int N=2e5+10;
int tt,n,m,f[N],u[N],v[N],eu[10],ev[10],ei[10],ex,sp[N],ff[N],dep[N];
bool ans[N];
vector<int> adj[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void dfs(int x,int fa)
{
	for(int y:adj[x])if(y!=fa)
	{
		ff[y]=x;
		dep[y]=dep[x]+1;
		dfs(y,x);
	}
}
int main()
{
	read(tt);
	while(tt--)
	{
		read(n,m);
		F(i,0,n)f[i]=i;
		F(i,0,m)ans[i]=false;
		ex=0;
		F(i,0,m)
		{
			read(u[i],v[i]);--u[i],--v[i];
			if(find(u[i])==find(v[i]))
			{
				eu[ex]=u[i],ev[ex]=v[i];
				ei[ex]=i;
				++ex;
			}
			else
			{
				f[find(u[i])]=find(v[i]);
				adj[u[i]].emplace_back(v[i]);
				adj[v[i]].emplace_back(u[i]);
			}
		}
		if(m-n<2)
		{
			F(i,0,ex)ans[ei[i]]=true;
		}
		else
		{
			int re=0;
			F(i,0,n)sp[i]=false;
			F(i,0,3)sp[eu[i]]=sp[ev[i]]=true;
			F(i,0,n)re+=sp[i];
			if(re>3)
			{
				F(i,0,ex)ans[ei[i]]=true;
			}
			else
			{
				ans[ei[0]]=ans[ei[1]]=true;
				dfs(0,0);
				int xx,yy;
				if(dep[eu[2]]>dep[ev[2]])xx=eu[2],yy=ff[xx];
				else xx=ev[2],yy=ff[xx];
				F(i,0,m)if((u[i]==xx&&v[i]==yy)||(u[i]==yy&&v[i]==xx))ans[i]=true;
			}
		}
		F(i,0,m)putchar(ans[i]?'1':'0');
		puts("");
		F(i,0,n)adj[i].clear(),adj[i].shrink_to_fit();
	}
	return 0;
}