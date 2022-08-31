#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MaxN=210;
const int MaxM=50010;
const int INF=2000000010;

int n,m;
long long G,S;

struct node
{
	int x,y,g,s;
}p[MaxM];

bool cmp_g(node A,node B)
{
	return A.g<B.g;
}

vector<node*> edge;
vector<pair<int,int> > v[MaxN];

int F[MaxN],used[MaxN],pre[MaxN],cost[MaxN];

int father(int x)
{
	return (F[x]==x)?x:F[x]=father(F[x]);
}

void DFS(int x)
{
	used[x]=1;
	for (vector<pair<int,int> >::iterator it=v[x].begin();it!=v[x].end();++it)
		if (!used[it->first])
		{
			DFS(it->first);
			pre[it->first]=x;
			cost[it->first]=it->second;
		}
}

void rebuild()
{
	for (int i=1;i<=n;++i)
		v[i].clear();
	for (int k=0;k<edge.size();++k)
	{
		v[edge[k]->x].push_back(make_pair(edge[k]->y,edge[k]->s));
		v[edge[k]->y].push_back(make_pair(edge[k]->x,edge[k]->s));
	}
	memset(used,0,sizeof(used));
	for (int i=1;i<=n;++i)
		if (!used[i])
		{
			pre[i]=0;
			DFS(i);
		}
}

void init()
{
	cin>>n>>m>>G>>S;
	for (int i=1;i<=m;++i)
	{
		scanf("%d%d%d%d",&p[i].x,&p[i].y,&p[i].g,&p[i].s);
		if (p[i].x>p[i].y) swap(p[i].x,p[i].y);
	}
	sort(p+1,p+m+1,cmp_g);
}

void work()
{
	for (int i=1;i<=n;++i)
		F[i]=i;
	long long ans=(long long)INF*INF;
	for (int i=1;i<=m;++i)
	{
		if (p[i].x==p[i].y) continue;
		int fx=father(p[i].x);
		int fy=father(p[i].y);
		if (fx==fy)
		{
			int px,py,ps=0;
			int x;
			memset(used,0,sizeof(used));
			for (x=p[i].x;x;x=pre[x]) used[x]=1;
			for (x=p[i].y;x;x=pre[x]) if (used[x]) break;
			for (int k=p[i].x;k!=x;k=pre[k])
				if (ps<cost[k])
				{
					px=k;
					py=pre[k];
					ps=cost[k];
				}
			for (int k=p[i].y;k!=x;k=pre[k])
				if (ps<cost[k])
				{
					px=k;
					py=pre[k];
					ps=cost[k];
				}
			if (px>py) swap(px,py);
			if (ps>p[i].s)
			{
				for (int k=0;k<edge.size();++k)
					if (edge[k]->x==px&&edge[k]->y==py)
					{
						edge[k]=&p[i];
						break;
					}
				rebuild();
			}
		}
		else
		{
			F[fx]=fy;
			edge.push_back(&p[i]);
			rebuild();
		}
		if (edge.size()==n-1)
		{
			int get=0;
			for (int k=0;k<edge.size();++k)
				get=max(get,edge[k]->s);
			ans=min(ans,G*p[i].g+S*get);
		}
	}
	if (ans==(long long)INF*INF) ans=-1;
	cout<<ans<<endl;
}

int main()
{
	init();
	work();
	return 0;
}