#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define N 100010
using namespace std;
int s[N],fir[N],nxt[N<<1],to[N<<1],cnt;
void add(int u,int v){nxt[++cnt]=fir[u];fir[u]=cnt;to[cnt]=v;}
void dfs(int x,int fa)
{
	int flg=1,i;
	for (i=fir[x];i;i=nxt[i]) if (to[i]!=fa) {flg=0;dfs(to[i],x);s[x]+=s[to[i]];}
	if (flg) s[x]=1;
}
int main()
{
	int n,i,t;cin>>n;
	for (i=2;i<=n;i++) scanf("%d",&t),add(i,t),add(t,i);
	dfs(1,0);sort(s+1,s+n+1);
	for (i=1;i<=n;i++) printf("%d ",s[i]);
}