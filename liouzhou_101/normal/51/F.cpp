#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>

using namespace std;

const int MaxN=2010;

int n,m;
vector<int> v[MaxN];

void init()
{
	cin>>n>>m;
	for (int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
}

int ans,Time;

int DFN[MaxN],LOW[MaxN];

void tarjan(int x,int p)
{
	DFN[x]=LOW[x]=++Time;
	for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it)
		if (!DFN[*it])
		{
			tarjan(*it,x);
			LOW[x]=min(LOW[x],LOW[*it]);
		}
		else if (*it!=p)
			LOW[x]=min(LOW[x],DFN[*it]);
}

int head,tail,Q[MaxN];
int used[MaxN],belong[MaxN],on[MaxN];

void build(int x)
{
	on[x]=1;
	used[Q[head=tail=1]=x]=1;
	while (head<=tail)
	{
		int now=Q[head++];
		belong[now]=x;
		for (vector<int>::iterator it=v[now].begin();it!=v[now].end();++it)
		{
			if (used[*it]) continue;
			int a=now,b=*it;
			if (DFN[a]>DFN[b]) swap(a,b);
			if (DFN[a]<LOW[b]) continue;
			used[Q[++tail]=*it]=1;
		}
	}
	ans+=tail-1;
}

vector<int> w[MaxN],son[MaxN];
int have,get;
int F[MaxN],G[MaxN],size[MaxN];

void BFS(int x)
{
	used[Q[head=tail=1]=x]=1;
	while (head<=tail)
	{
		int now=Q[head++];
		for (vector<int>::iterator it=w[now].begin();it!=w[now].end();++it)
			if (!used[*it]) used[Q[++tail]=*it]=1;
	}
	have=tail;
	for (int i=1;i<=tail;++i)
		used[Q[i]]=0;
}

void solve(int x)
{
	used[x]=1;
	size[x]=1;
	int leaf=0,sum=0;
	for (vector<int>::iterator it=w[x].begin();it!=w[x].end();++it)
		if (!used[*it])
		{
			son[x].push_back(*it);
			solve(*it);
			size[x]+=size[*it];
			if (size[*it]==1) ++leaf;
			sum+=G[*it]+(size[*it]!=1);
		}
	if (size[x]==1)
		F[x]=G[x]=0;
	else
	{
		F[x]=MaxN;
		G[x]=sum;
		for (vector<int>::iterator it=son[x].begin();it!=son[x].end();++it)
			F[x]=min(F[x],F[*it]+sum-G[*it]-(size[*it]!=1));
	}
	if (size[x]==have)
	{
		get=min(get,F[x]);
		for (int i=0;i<son[x].size();++i)
			for (int j=i+1;j<son[x].size();++j)
				get=min(get,F[son[x][i]]+F[son[x][j]]+sum-G[son[x][i]]-(size[son[x][i]]!=1)-G[son[x][j]]-(size[son[x][j]]!=1));
	}
}

void work()
{
	for (int i=1;i<=n;++i)
		if (!DFN[i]) tarjan(i,0);
	for (int i=1;i<=n;++i)
		if (!used[i]) build(i);
	for (int i=1;i<=n;++i)
		for (vector<int>::iterator it=v[i].begin();it!=v[i].end();++it)
			if (belong[i]!=belong[*it])
			{
				int x=belong[i],y=belong[*it];
				w[x].push_back(y);
				w[y].push_back(x);
			}
	memset(used,0,sizeof(used));
	for (int i=1;i<=n;++i)
		if (!used[i]&&on[i])
		{
			BFS(i);
			get=MaxN;
			for (int k=1;k<=tail;++k)
			{
				for (int p=1;p<=tail;++p)
				{
					son[Q[p]].clear();
					used[Q[p]]=0;
				}
				solve(Q[k]);
			}
			ans+=get+1;
		}
	cout<<ans-1<<endl;
}

int main()
{
	init();
	work();
	return 0;
}