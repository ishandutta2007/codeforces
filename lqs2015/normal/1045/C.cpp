#include<bits/stdc++.h>
using namespace std;
int bccnt,n,m,q,x,y,z,dfn[111111],low[111111],cnt,bccno[111111],val[222222],wson[222222],sub[222222],beg[222222],ct,dep[222222];
int numchain,pos[222222],head[222222],w[444444],tree[1111111],pa[222222],sx,an[222222][22];
vector<int> ng[222222];
vector<int> g[111111];
bool iscut[111111];
stack<pair<int,int> > st;
multiset<int> s[222222];
char c[11];
void dfs(int i,int fa)
{
	int child=0;
	dfn[i]=low[i]=++cnt;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		if (!dfn[to])
		{
			st.push(make_pair(i,to)); 
			dfs(to,i);
			child++;
			if (low[to]>=dfn[i])
			{
				iscut[i]=1;bccnt++;
				while(!st.empty())
				{
					pair<int,int> e=st.top();st.pop();
					if (bccno[e.first]!=bccnt) 
					{
						ng[bccnt].push_back(e.first);
						ng[e.first].push_back(bccnt);  
						bccno[e.first]=bccnt; 
					}
					if (bccno[e.second]!=bccnt) 
					{
						ng[bccnt].push_back(e.second);
						ng[e.second].push_back(bccnt);  
						bccno[e.second]=bccnt; 
					}
					if (e.first==i && e.second==to) break;
				}
			}
			low[i]=min(low[i],low[to]);
		}
		else if (dfn[to]<low[i])
		{
			low[i]=dfn[to];
			st.push(make_pair(i,to)); 
		}
	}
	if (!fa && child==1) iscut[i]=0;
}
int lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=19;i>=0;i--)
	{
		if (dep[an[x][i]]>=dep[y]) x=an[x][i];
	}
	for (int i=19;i>=0;i--)
	{
		if (an[x][i]!=an[y][i])
		{
			x=an[x][i];
			y=an[y][i];
		}
	}
	if (x!=y) return an[x][0];
	return x;
}
void dft(int i,int fa)
{
	dep[i]=dep[fa]+1;an[i][0]=fa;
	for (int j=1;j<=19;j++) an[i][j]=an[an[i][j-1]][j-1];
	for (int j=0;j<ng[i].size();j++)
	{
		int to=ng[i][j];
		if (to==fa) continue;
		dft(to,i);
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	bccnt=n;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);  
	}
	dfs(1,0);
	dft(1,0);
	while(q--)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",(dep[x]+dep[y]-2*dep[lca(x,y)])/2);
	}
	return 0;
}