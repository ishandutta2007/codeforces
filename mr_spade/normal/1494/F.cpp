#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<stack>
#define next Mr_Spade
using std::swap;
using std::vector;
using std::stack;
const int N=6005;
int n,m,sum,tot;
int v[N],first[N],next[N];
int deg[N];
int bk[N];
struct cell
{
	int v,id;
};
vector<int> ans;
int iter[N];
vector<cell> e[N];
int vis[N];
inline void add_edge(int x,int y)
{
	tot+=2;deg[x]++;deg[y]++;
	v[tot+1]=x;v[tot]=y;
	next[tot]=first[x];first[x]=tot;
	next[tot+1]=first[y];first[y]=tot+1;
	return;
}
int size;
int dis[N],rank[N];
stack<int> st,st2;
inline int find(int x)
{
	while(dis[x]!=x)
		x=dis[x];
	return x;
}
inline void merge(int x,int y)
{
	x=find(x);y=find(y);
	if(x==y)
		return;
	if(rank[x]>rank[y])
		swap(x,y);
	st.push(x);
	st2.push((rank[x]==1)+(rank[y]==1));
	size+=(rank[x]==1)+(rank[y]==1);
	dis[x]=y;size--;
	rank[y]+=rank[x];
	return;
}
inline void undo(int t)
{
	int x,y;
	for(;(int)st.size()>t;st.pop(),st2.pop())
	{
		x=st.top();y=st2.top();
		rank[dis[x]]-=rank[x];size++;
		dis[x]=x;size-=y;
	}
	return;
}
void dfs(int x)
{
	cell c;
	for(int &i=iter[x];i<(int)e[x].size();)
	{
		c=e[x][i];i++;
		if(!vis[c.id])
		{
			vis[c.id]=1;
			dfs(c.v);
		}
	}
	ans.push_back(x);
	return;
}
inline void run(int x,int y)
{
	int idx=0;
	register int i,j;
	if(rank[find(x)]==1||rank[find(y)]==1)
		return;
	for(i=1;i<=n;i++)
		for(j=first[i];j;j=next[j])
			if(i<v[j]&&(i!=x||(v[j]==y||!(deg[v[j]]&1)))&&(v[j]!=x||(i==y||!(deg[i]&1))))
				e[i].push_back(cell{v[j],++idx}),e[v[j]].push_back(cell{i,idx});
	dfs(x);
	ans.push_back(-1);
	for(i=1;i<=n;i++)
		if((deg[i]&1)&&i!=x&&i!=y)
			ans.push_back(i),ans.push_back(x);
	printf("%d\n",(int)ans.size());
	for(int t:ans)
		printf("%d ",t);
	putchar('\n');
	exit(0);
}
signed main()
{
	int x,y;
	register int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		add_edge(x,y);
	}
	for(i=1;i<=n;i++)
		if(deg[i]&1)
		{
			sum++;
			for(j=first[i];j;j=next[j])
				bk[v[j]]++;
		}
	if(sum==0)
	{
		y=0;
		for(i=1;i<=n;i++)
			for(j=first[i];j;j=next[j])
				if(i<v[j])
					e[i].push_back(cell{v[j],++y}),e[v[j]].push_back(cell{i,y});
		dfs(1);
		printf("%d\n",(int)ans.size());
		for(int t:ans)
			printf("%d ",t);
		putchar('\n');
		return 0;
	}
	for(i=1;i<=n;i++)
		if(bk[i]>=sum-1-(deg[i]&1))
		{
			for(j=1;j<=n;j++)
				dis[j]=j,rank[j]=1;
			size=0;
			for(j=1;j<=n;j++)
				for(k=first[j];k;k=next[k])
					if((j!=i||!(deg[v[k]]&1))&&(!(deg[j]&1)||v[k]!=i))
						merge(j,v[k]);
			if(bk[i]==sum-1-(deg[i]&1))
			{
				if(size<=1)
				{
					for(j=1;j<=n;j++)
						if((deg[j]&1)&&i!=j)
						{
							for(k=first[j];k;k=next[k])
								if(v[k]==i)
									goto end1;
							run(i,j);
							end1:;
						}
				}
			}
			else
			{
				x=(int)st.size();
				for(j=1;j<=n;j++)
					if((deg[j]&1)&&(i!=j))
					{
						merge(i,j);
						if(size<=1)
							run(i,j);
						undo(x);
					}
			}
			while(!st.empty())
				st.pop();
		}
	puts("0");
	return 0;
}