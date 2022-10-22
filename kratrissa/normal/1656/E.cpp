#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,hd[N],nxt[N<<1],to[N<<1],tot,deg[N],col[N];
void add(int x,int y){to[++tot]=y,nxt[tot]=hd[x],hd[x]=tot;}
void dfs(int x,int c){
	if(col[x])return;
	col[x]=c;
	for(int i=hd[x];i;i=nxt[i])dfs(to[i],c^3);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),fill(hd,hd+n+1,0),tot=0,fill(deg,deg+n+1,0),fill(col,col+n+1,0);
		for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x),deg[x]++,deg[y]++;
		dfs(1,1);
		for(int i=1;i<=n;i++)printf("%d%c",col[i]==1?deg[i]:-deg[i],i==n?'\n':' ');
	}
	return 0;
}