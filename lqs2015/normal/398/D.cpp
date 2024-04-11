#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
#include<cstring>
using namespace std;
const int lim=200;
set<pair<int,int> > s;
vector<int> g[55555],b[55555],gg[55555],v;
int n,m,q,x,y,k,cnt,num[55555],ans[55555],res;
bool on[55555],big[55555],used[55555];
pair<int,pair<int,int> >que[444444];
char tp;
void add(int from,int to)
{
	if (!big[from] || (big[from] && big[to])) g[from].push_back(to);
	if (big[from] && on[to]) ans[from]++; 
}
void del(int from,int to)
{
	if (big[from])
	{
		if (on[to]) ans[from]--;
	}
	if (!big[from] || big[to])
	{
		for (int i=0;i<g[from].size();i++)
		{
			if (g[from][i]==to)
			{
				g[from].erase(g[from].begin()+i);
				break;
			}
		}
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&q,&k);
	for (int i=1;i<=k;i++)
	{
		scanf("%d",&x);
		on[x]=1;
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		que[++cnt]=make_pair(3,make_pair(x,y));
	}
	for (int i=1;i<=q;i++)
	{
		getchar();
		scanf("%c",&tp);
		if (tp=='O')
		{
			scanf("%d",&x);
			que[++cnt]=make_pair(1,make_pair(x,-1));
		}
		else if (tp=='F')
		{
			scanf("%d",&x);
			que[++cnt]=make_pair(2,make_pair(x,-1));
		}
		else if (tp=='A')
		{
			scanf("%d%d",&x,&y);
			que[++cnt]=make_pair(3,make_pair(x,y));
		}
		else if (tp=='D')
		{
			scanf("%d%d",&x,&y);
			que[++cnt]=make_pair(4,make_pair(x,y));
		}
		else 
		{
			scanf("%d",&x);
			que[++cnt]=make_pair(5,make_pair(x,-1));
		}
	}
	for (int i=cnt;i>=1;i--)
	{
		if (que[i].first==3)
		{
			x=que[i].second.first;y=que[i].second.second;
			if (x>y) swap(x,y);
			gg[x].push_back(y);
			gg[y].push_back(x);  
			if (s.find(make_pair(x,y))!=s.end()) continue;
			g[x].push_back(y);
			g[y].push_back(x);   
		}
		else if (que[i].first==4)
		{
			x=que[i].second.first;y=que[i].second.second;
			if (x>y) swap(x,y);
			s.insert(make_pair(x,y)); 
		}
	}
	for (int i=1;i<=n;i++)
	{
		num[i]=g[i].size();
		if (num[i]>=lim) big[i]=1;
	}
	for (int i=1;i<=n;i++) g[i].clear();
	for (int i=1;i<=cnt;i++)
	{
		x=que[i].second.first;y=que[i].second.second;
		if (que[i].first==1)
		{
			on[x]=1;
			if (big[x])
			{
				for (int j=0;j<g[x].size();j++)
				{
					ans[g[x][j]]++;
				}
			}
			else
			{
				for (int j=0;j<g[x].size();j++)
				{
					if (big[g[x][j]]) ans[g[x][j]]++;
				}
			}
		}
		else if (que[i].first==2)
		{
			on[x]=0;
			if (big[x])
			{
				for (int j=0;j<g[x].size();j++)
				{
					ans[g[x][j]]--;
				}
			}
			else
			{
				for (int j=0;j<g[x].size();j++)
				{
					if (big[g[x][j]]) ans[g[x][j]]--;
				}
			}
		}
		else if (que[i].first==3)
		{
			add(x,y);
			add(y,x);
		}
		else if (que[i].first==4)
		{
			del(x,y);
			del(y,x);
		}
		else 
		{
			if (big[x]) printf("%d\n",ans[x]);
			else
			{
				res=0;
				for (int j=0;j<g[x].size();j++)
				{
					if (on[g[x][j]]) res++;
				}
				printf("%d\n",res);
			}
		}
	}
	return 0;
}