#include<iostream>
#include<cstdio>
using namespace std;
int h[201000],nxt[401000],to[401000],K=1;
void ins(int u,int v){nxt[++K]=h[u];h[u]=K;to[K]=v;}
int u[201000],v[201000];long long c[201000],s[201000];
bool used[201000];
void dfs(int x)
{
	used[x]=1;
	for(int i=h[x];i;i=nxt[i])
	{
		if(!used[to[i]])
		{
			dfs(to[i]);s[x]+=s[to[i]];
			if(u[i>>1]==x&&v[i>>1]==to[i])c[i>>1]=s[to[i]];
			else c[i>>1]=-s[to[i]];
		}
	}
}
int main()
{
	int n;long long sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&s[i]),sum+=s[i];
	if(sum)return 0*puts("Impossible");
	puts("Possible");
	int m;scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%d%d",&u[i],&v[i]),ins(u[i],v[i]),ins(v[i],u[i]);
	dfs(1);
	for(int i=1;i<=m;i++)printf("%lld\n",c[i]);
	return 0;
}
//0