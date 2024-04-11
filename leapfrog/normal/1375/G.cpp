#include<bits/stdc++.h>
using namespace std;
struct edge{int to,nxt;}e[400005];
int n,et,head[200005],tot[2];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x,int col,int fa)
{
	tot[col]++;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs(e[i].to,col^1,x);
}
int main()
{
	scanf("%d",&n),et=0,memset(head,0,sizeof(head)),tot[0]=tot[1]=0;
	for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),adde(x,y),adde(y,x);
	return dfs(1,0,0),printf("%d\n",min(tot[1],tot[0])-1),0;
}