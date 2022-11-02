#include<bits/stdc++.h>
using namespace std;
struct edge{int to,nxt;}e[900005];
int n,m,f[300005],tot,head[300005];
inline void adde(int x,int y) {e[++tot]=(edge){y,head[x]},head[x]=tot;}
inline void dfs(int x)
{
	int cnt=0;
	for(int i=head[x];i;i=e[i].nxt) if(f[e[i].to]==f[x]) cnt++;
	if(cnt>=2) {f[x]^=1;for(int i=head[x];i;i=e[i].nxt) if(f[e[i].to]==f[x]) dfs(e[i].to);}
}
int main()
{
	scanf("%d%d",&n,&m),memset(f,0,sizeof(f));
	for(int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y),adde(x,y),adde(y,x);
	for(int i=1;i<=n;i++) dfs(i);
	for(int i=1;i<=n;i++) printf("%d",f[i]);
	return puts(""),0;
}