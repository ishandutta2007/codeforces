#include<cstdio>
#include<iostream>

using namespace std;

const int MaxN=2000010;

int n,m;

int tot;
struct node
{
	int way;
	node *next;
}edge[MaxN],*vec[MaxN];

inline void addedge(int x,int y)
{
	++tot;
	edge[tot].way=y;
	edge[tot].next=vec[x];
	vec[x]=&edge[tot];
}

int d[MaxN];
int used[MaxN];

void init()
{
	cin>>n>>m;
	for (int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
		d[x]++;
		d[y]++;
	}
	for (int i=1;i<=n;++i)
		if (!d[i]) used[i]=1;
	used[1]=0;
}

int head,tail,Q[MaxN];

void work()
{
	int ans=0;
	int have=0,not_need=0;
	for (int i=1;i<=n;++i)
	{
		if (used[i]) continue;
		++have;
		used[Q[head=tail=1]=i]=1;
		while (head<=tail)
		{
			int now=Q[head++];
			for (node *it=vec[now];it;it=it->next)
				if (!used[it->way])
					used[Q[++tail]=it->way]=1;
		}
		int p=0;
		for (int k=1;k<=tail;++k)
			if (d[Q[k]]&1) ++p;
		if (!p) ++not_need;
		else ans+=p/2-1;
	}
	if (have==1)
		cout<<ans+1-not_need<<endl;
	else
		cout<<ans+have<<endl;
}

int main()
{
	init();
	work();
	return 0;
}