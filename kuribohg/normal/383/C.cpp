#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=400010;
int n,m,x,y,a[MAXN],dep[MAXN];
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
int L[MAXN],R[MAXN],dfs_clock;
inline void adde(int f,int t)
{
	cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
	cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
void DFS(int x,int fa)
{
	L[x]=++dfs_clock;
	for(int i=head[x];i;i=next[i])
		if(to[i]!=fa) dep[to[i]]=dep[x]+1,DFS(to[i],x);
	R[x]=dfs_clock;
}
LL BIT[MAXN];
void Change(int x,LL tar)
{
	for(int i=x;i<=n;i+=(i&(-i)))
		BIT[i]+=tar;
}
LL Query(int x)
{
	LL con=0;
	for(int i=x;i>0;i^=(i&(-i)))
		con+=BIT[i];
	return con;
}
int op,pos,tar;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<n;i++) scanf("%d%d",&x,&y),adde(x,y);
	DFS(1,-1);
	for(int i=1;i<=n;i++)
		if(dep[i]&1) Change(L[i],a[i]),Change(L[i]+1,-a[i]);
		else Change(L[i],-a[i]),Change(L[i]+1,a[i]);
	while(m--)
	{
		scanf("%d%d",&op,&pos);
		if(op==1) scanf("%d",&tar);
		if(op==1)
		{
			if(dep[pos]&1) Change(L[pos],tar),Change(R[pos]+1,-tar);
			else Change(L[pos],-tar),Change(R[pos]+1,tar);
		}
		else
		{
			LL con=Query(L[pos]);
			if(dep[pos]&1) printf("%I64d\n",con);
			else printf("%I64d\n",-con);
		}
	}
	return 0;
}