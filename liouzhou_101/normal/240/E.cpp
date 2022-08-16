#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

const int MaxN=400010;

int n,m;

int tot;
struct node
{
	int way,flag,index;
	node *next;
}edge[MaxN],*vec[MaxN],*w[MaxN];

void addedge(node **vec,int x,int y,int c,int p)
{
	++tot;
	edge[tot].way=y;
	edge[tot].flag=c;
	edge[tot].index=p;
	edge[tot].next=vec[x];
	vec[x]=&edge[tot];
}

int Time;
int used[MaxN],DFN[MaxN],LOW[MaxN];
int belong[MaxN],get[MaxN];
vector<int> have[MaxN];

int top,head,tail,Q[MaxN];

void tarjan(int x)
{
	used[x]=DFN[x]=LOW[x]=++Time;
	Q[++top]=x;
	for (node *it=vec[x];it;it=it->next)
		if (!it->flag)
		{
			if (!DFN[it->way])
			{
				tarjan(it->way);
				LOW[x]=min(LOW[x],LOW[it->way]);
			}
			else if (used[it->way])
				LOW[x]=min(LOW[x],DFN[it->way]);
		}
	if (LOW[x]==DFN[x])
	{
		get[x]=1;
		while (1)
		{
			int p=Q[top--];
			belong[p]=x;
			used[p]=0;
			have[x].push_back(p);
			if (p==x) break;
		}
	}
}

int degree[MaxN];
int ans,list[MaxN];

void solve()
{
	used[Q[head=tail=1]=belong[1]]=1;
	while (head<=tail)
	{
		int x=Q[head++];
		for (vector<int>::iterator p=have[x].begin();p!=have[x].end();++p)
		{
			int now=*p;
			for (node *it=vec[now];it;it=it->next)
			{
				if (belong[now]==belong[it->way]) continue;
				if (!it->flag)
				{	
					if (!used[belong[it->way]])
						used[Q[++tail]=belong[it->way]]=1;
				}
				else
				{
					if (!degree[belong[it->way]])
					{
						++degree[belong[it->way]];
						used[Q[++tail]=belong[it->way]]=1;
						list[++ans]=it->index;
						addedge(w,belong[now],belong[it->way],1,it->index);
					}
				}
			}
		}
	}
}

void check()
{
	used[Q[head=tail=1]=belong[1]]=1;
	while (head<=tail)
	{
		int now=Q[head++];
		for (node *it=w[now];it;it=it->next)
			if (!used[it->way])
				used[Q[++tail]=it->way]=1;
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=m;++i)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		addedge(vec,x,y,c,i);
	}
	for (int i=1;i<=n;++i)
		if (!DFN[i]) tarjan(i);
	for (int i=1;i<=n;++i)
		for (node *it=vec[i];it;it=it->next)
			if (!it->flag)
			{
				if (belong[i]!=belong[it->way])
				{
					++degree[belong[it->way]];
					addedge(w,belong[i],belong[it->way],0,it->index);
				}
			}
	++degree[belong[1]];
	solve();
	check();
	int flag=0;
	for (int i=1;i<=n;++i)
		if (get[i]&&!used[i]) flag=1;
	if (flag)
		puts("-1");
	else
	{
		cout<<ans<<endl;
		for (int i=1;i<=ans;++i)
			printf("%d\n",list[i]);
	}
	return 0;
}