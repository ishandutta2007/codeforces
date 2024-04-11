#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define maxn 205						//
#define maxm 205						//
#define rever(x) (mem+((x-mem)^1))
struct edge
{
	int s,t,v;
	edge* next;
}mem[maxm*2],*head[maxn];
int cnt=-1;
void add_edge(int s,int t,int v)
{
	mem[++cnt].s=s;mem[cnt].t=t;mem[cnt].v=v;mem[cnt].next=head[s];head[s]=mem+cnt;
	mem[++cnt].s=t;mem[cnt].t=s;mem[cnt].v=0;mem[cnt].next=head[t];head[t]=mem+cnt;
}
int n,m;

int S,T;
int numbs[maxn];
int d[maxn];					
edge* cur[maxn],*revpath[maxn];	

void bfs()
{
	queue<int> q;
	while(!q.empty()) q.pop();
	for (int i=0;i<=n;i++) d[i]=maxn-1;				//01
	d[T]=0;q.push(T);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for (edge* it=head[u];it;it=it->next)
		{
			edge *now=rever(it);
			if (now->v==0||d[now->s]<n) continue;
			d[now->s]=d[u]+1;
			q.push(now->s);
		}
	}
	memset(numbs,0,sizeof(numbs));
	for (int i=0;i<=n;i++) numbs[d[i]]++;			//01			
}

int isap()
{
	int flow=0;
	for (int i=0;i<=n;i++) cur[i]=head[i];			//01
	int u=S;
	while(d[S]<n)
	{
		if (u==T) 
		{
			int augflow=2147483647;
			for (int i=S;i!=T;i=cur[i]->t)
				augflow=min(augflow,cur[i]->v);
			for (int i=S;i!=T;i=cur[i]->t)
			{
				cur[i]->v-=augflow;
				rever(cur[i])->v+=augflow;
			}
			flow+=augflow;u=S;
		}
		edge *e;
		for (e=cur[u];e;e=e->next)
			if (e->v&&d[u]==(d[e->t]+1)) break;
		if (e)
		{
			cur[u]=e;
			revpath[e->t]=rever(e);
			u=e->t;
		}
		else
		{
			numbs[d[u]]--;
			if (numbs[d[u]]==0) break;
			cur[u]=head[u];
			int mindist=n;
			for (edge* it=head[u];it;it=it->next)
				if (it->v) mindist=min(mindist,d[it->t]);
			d[u]=mindist+1;
			numbs[d[u]]++;
			if (u!=S) u=revpath[u]->t;
		}
	}
	return flow;
}

int N;
char tmp[20];
int prov[10],need[20];
int tpe[100005];
char lst[6][5]={"S","M","L","XL","XXL","XXXL"};
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	for (int i=1;i<=6;i++) scanf("%d",&prov[i]);
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		scanf("%s",tmp);
		if (strcmp(tmp,"S")==0) tpe[i]=1;
		else if (strcmp(tmp,"M")==0) tpe[i]=2;
		else if (strcmp(tmp,"L")==0) tpe[i]=3;
		else if (strcmp(tmp,"XL")==0) tpe[i]=4;
		else if (strcmp(tmp,"XXL")==0) tpe[i]=5;
		else if (strcmp(tmp,"XXXL")==0) tpe[i]=6;
		else if (strcmp(tmp,"S,M")==0) tpe[i]=7;
		else if (strcmp(tmp,"M,L")==0) tpe[i]=8;
		else if (strcmp(tmp,"L,XL")==0) tpe[i]=9;
		else if (strcmp(tmp,"XL,XXL")==0) tpe[i]=10;
		else tpe[i]=11;
	}
	for (int i=1;i<=N;i++) need[tpe[i]]++;
	cnt=-1;S=0;T=18;n=T;
	for (int i=1;i<=6;i++) add_edge(S,i,prov[i]);
	for (int i=1;i<=11;i++) add_edge(i+6,T,need[i]);
	for (int i=1;i<=6;i++) 
	{
		add_edge(i,i+6,100000);
		if (i!=1) add_edge(i,i+11,100000);
		if (i!=6) add_edge(i,i+12,100000);
	}
	bfs();
	if (isap()!=N) {printf("NO\n");return 0;}
	else printf("YES\n");
	edge* it;
	for (int i=1;i<=N;i++)
	{
		for (it=head[tpe[i]+6];it->t==T||it->v==0;it=it->next);
		it->v--;
		printf("%s\n",lst[it->t-1]);
	}
	return 0;
}