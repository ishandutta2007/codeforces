#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

const int MaxN=1000010;
const int INF=1000000000;

int n,m;
int S,T;
int a[MaxN],b[MaxN];

int tot;
struct node
{
	int from,way,cap,cost;
	node *next,*rev;
}edge[MaxN],*vec[MaxN];

void addedge(int x,int y,int c,int w)
{
	++tot;
	edge[tot].from=x;
	edge[tot].way=y;
	edge[tot].cap=c;
	edge[tot].cost=w;
	edge[tot].next=vec[x];
	edge[tot].rev=&edge[tot+1];
	vec[x]=&edge[tot];
	++tot;
	edge[tot].from=y;
	edge[tot].way=x;
	edge[tot].cap=0;
	edge[tot].cost=-w;
	edge[tot].next=vec[y];
	edge[tot].rev=&edge[tot-1];
	vec[y]=&edge[tot];
}

void init()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
	{
		cin>>a[i];
		for (int j=0;j<=30;++j)
			if (a[i]&(1<<j)) ++b[i];
	}
	S=n*2+1;
	T=S+1;
	addedge(S,0,m,0);
	for (int i=1;i<=n;++i)
	{
		addedge(S,i,1,0);
		addedge(n+i,T,1,0);
		addedge(0,n+i,1,b[i]);
		for (int j=i+1;j<=n;++j)
			addedge(i,n+j,1,(a[i]==a[j])?0:b[j]);
	}
}

priority_queue<pair<int,int> > H;
int dis[MaxN];
node *pre[MaxN];
int ans;

bool SPFA()
{
	for (int i=0;i<=T;++i)
		dis[i]=INF;
	H.push(make_pair(dis[S]=0,S));
	while (!H.empty())
	{
		int nowx=H.top().second,nowd=-H.top().first;
		H.pop();
		if (dis[nowx]!=nowd) continue;
		for (node *it=vec[nowx];it;it=it->next)
			if (it->cap>0&&dis[it->way]>nowd+it->cost)
			{
				H.push(make_pair(-(dis[it->way]=nowd+it->cost),it->way));
				pre[it->way]=it;
			}
	}
	if (dis[T]==INF) return false;
	ans+=dis[T];
	for (int i=T;i!=S;i=pre[i]->from)
	{
		--pre[i]->cap;
		++pre[i]->rev->cap;
	}
	return true;
}

int len,use;
int get[MaxN],mark[MaxN];

void work()
{
	while (SPFA());
	for (int i=1;i<=n;++i)
		for (node *it=vec[n+i];it;it=it->next)
			if (it->way<=n&&it->cap>0)
			{
				get[i]=it->way;
				break;
			}
	for (int i=1;i<=n;++i)
	{
		if (a[get[i]]!=a[i]) ++len;
		++len;
	}
	cout<<len<<" "<<ans<<endl;
	for (int i=1;i<=n;++i)
	{
		if (get[i])
			mark[i]=mark[get[i]];
		else
			mark[i]=use++;
		if (a[i]!=a[get[i]])
			printf("%c=%d\n",mark[i]+'a',a[i]);
		printf("print(%c)\n",mark[i]+'a');
	}
}

int main()
{
	init();
	work();
	return 0;
}