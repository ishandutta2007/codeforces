#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MaxN=1<<18;
const int MOD=1000000007;

int n,m;
vector<int> v[MaxN];

int Time;
int DFN[MaxN],LOW[MaxN];

void tarjan(int x,int pre)
{
	DFN[x]=LOW[x]=++Time;
	for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it)
		if (!DFN[*it])
		{
			tarjan(*it,x);
			LOW[x]=min(LOW[x],LOW[*it]);
		}
		else if (*it!=pre)
			LOW[x]=min(LOW[x],DFN[*it]);
}

int used[MaxN],dis[MaxN],first[MaxN],have[MaxN],size[MaxN];
int LOG[MaxN];
int head,tail,Q[MaxN];

vector<pair<int,int> > son[MaxN];

int len;
int LCA[MaxN<<1];

int LCA_min(int x,int y)
{
	return (dis[x]<dis[y])?x:y;
}

void LCA_add(int x,int v)
{
	int k=x+MaxN-1;
	LCA[k]=v;
	for (k>>=1;k;k>>=1)
		LCA[k]=LCA_min(LCA[k<<1],LCA[k<<1|1]);
}

int LCA_get(int k,int L,int R,int x,int y)
{
	if (L==x&&R==y)
		return LCA[k];
	int mid=(L+R)>>1;
	if (y<=mid)
		return LCA_get(k<<1,L,mid,x,y);
	if (x>mid)
		return LCA_get(k<<1|1,mid+1,R,x,y);
	return LCA_min(LCA_get(k<<1,L,mid,x,mid),LCA_get(k<<1|1,mid+1,R,mid+1,y));
}

void build(int x)
{
	used[Q[head=tail=1]=x]=x;
	while (head<=tail)
	{
		int now=Q[head++];
		for (vector<int>::iterator it=v[now].begin();it!=v[now].end();++it)
		{
			if (used[*it]) continue;
			if (DFN[now]<LOW[*it]) continue;
			used[Q[++tail]=*it]=x;
		}
	}
	for (int k=1;k<=tail;++k)
	{
		int now=Q[k];
		for (vector<int>::iterator it=v[now].begin();it!=v[now].end();++it)
		{
			if (used[*it]) continue;
			if (DFN[now]<LOW[*it])
				son[x].push_back(make_pair(now,*it));
		}
	}
	size[x]=tail;
	LCA_add(first[x]=++len,x);
	for (vector<pair<int,int> >::iterator it=son[x].begin();it!=son[x].end();++it)
	{
		dis[it->second]=dis[x]+1;
		have[it->second]=have[x]+(size[x]>1);
		build(it->second);
		LCA_add(++len,x);
	}
}

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
	tarjan(1,0);
	build(1);
	for (int i=2;i<=n;++i)
		LOG[i]=LOG[i>>1]+1;
}

long long power(long long x,long long p)
{
	if (!p) return 1;
	long long t=power(x,p>>1);
	t=t*t%MOD;
	if (p&1) t=t*x%MOD;
	return t;
}

void work()
{
	int T;
	cin>>T;
	while (T--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int fx=used[x],fy=used[y];
		if (fx==fy)
		{
			puts("2");
			continue;
		}
		int p=LCA_get(1,1,MaxN,min(first[fx],first[fy]),max(first[fx],first[fy]));
		if (p==fy)
		{
			swap(x,y);
			swap(fx,fy);
		}
		if (p==fx)
		{
			int get=have[fy]-have[p];
			if (size[fy]>1) get++;
			printf("%I64d\n",power(2,get));
			continue;
		}
		int get=have[fx]-have[p]+have[fy]-have[p];
		if (size[fx]>1) get++;
		if (size[fy]>1) get++;
		if (size[p]>1) --get;
		printf("%I64d\n",power(2,get));
	}
}

int main()
{
	init();
	work();
	return 0;
}