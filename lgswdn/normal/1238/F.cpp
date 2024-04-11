#include<bits/stdc++.h>
using namespace std;
const int N=3e5+9;

struct edge {int to,nxt;}e[N*2]; int hd[N],tot;
void add(int u,int v) {e[++tot]=(edge){v,hd[u]};hd[u]=tot;}

int n,g[N],h[N][2],ans;

void clear() {
	ans=0;
	for(int i=1;i<=n;i++) h[i][0]=h[i][1]=g[i]=0, hd[i]=0;
	for(int i=1;i<=tot;i++) e[i]=(edge){0,0};
	tot=0;
}

void dfs(int u,int fa) {
	int num=0;
	for(int i=hd[u],v;i;i=e[i].nxt) {
		num++;
		if((v=e[i].to)==fa) continue;
		dfs(v,u);
		if(g[v]>h[u][1]) h[u][1]=g[v];
		if(h[u][0]<h[u][1]) swap(h[u][0],h[u][1]);
	}
	num--;
	g[u]=1+h[u][0]+max(0,num-1);
	ans=max(ans,h[u][0]+h[u][1]+1+max(0,num-1));
	//cout<<u<<" "<<h[u][0]<<" "<<h[u][1]<<" "<<num<<" "<<h[u][0]+h[u][1]+1+max(0,num-1)<<endl;
}

int main() {
	int T; scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		clear();
		for(int i=1,u,v;i<n;i++)
			scanf("%d%d",&u,&v), add(u,v), add(v,u);
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}