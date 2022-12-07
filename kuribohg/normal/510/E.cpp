#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=100010;
const int MAXM=1000010;
const int INF=1000000000;
int S,T,d[MAXN];
int q[MAXN],l,r;
int head[MAXN],to[MAXM],next[MAXM],w[MAXM],cnt=1;
inline void adde(int f,int t,int ww)
{
	cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt,w[cnt]=ww;
	cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt,w[cnt]=0;
}
bool BFS()
{
	for(int i=1;i<=T;i++) d[i]=-1;
	q[l=r=1]=S,d[S]=1;
	while(l<=r)
	{
		int x=q[l++];
		for(int i=head[x];i;i=next[i])
			if(w[i]>0&&d[to[i]]==-1) d[to[i]]=d[x]+1,q[++r]=to[i];
	}
	return d[T]!=-1;
}
int DFS(int x,int a)
{
	if(x==T) return a;
	int flow=a,f;
	for(int i=head[x];i;i=next[i])
		if(d[to[i]]==d[x]+1&&w[i]>0)
		{
			f=DFS(to[i],min(w[i],a));
			w[i]-=f,w[i^1]+=f,a-=f;
			if(a<=0) return flow;
		}
	if(a!=0) d[x]=-1;
	return flow-a;
}
int Dinic()
{
	int flow=0,f;
	while(BFS())
		while((f=DFS(S,INF))!=0)
			flow+=f;
	return flow;
}
int n,a[MAXN],Ans,odd,tot;
vector<int> ans[310];
bool used[MAXN];
bool is_prime(int n)
{
	if(n==1) return false;
	for(int i=2;i*i<=n;i++)
		if(n%i==0) return false;
	return true;
}
void dfs(int x)
{
	used[x]=true;
	ans[tot].push_back(x);
	for(int i=head[x];i;i=next[i])
		if(!used[to[i]]&&w[i]%2!=a[x]%2) dfs(to[i]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	S=n+1,T=n+2;
	for(int i=1;i<=n;i++)
		if(a[i]&1) adde(S,i,2),odd++;
		else adde(i,T,2);
	if(odd!=n-odd) {puts("Impossible");return 0;}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(is_prime(a[i]+a[j]))
			{
				if(a[i]&1) adde(i,j,1);
				else adde(j,i,1);
			}
	Ans=Dinic();
	if(Ans!=n) {puts("Impossible");return 0;}
	used[S]=used[T]=true;
	for(int i=1;i<=n;i++)
		if((a[i]&1)&&!used[i]) ++tot,dfs(i);
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++)
	{
		int Len=ans[i].size();
		printf("%d ",Len);
		for(int j=0;j<Len;j++) printf("%d ",ans[i][j]);
		puts("");
	}
	return 0;
}