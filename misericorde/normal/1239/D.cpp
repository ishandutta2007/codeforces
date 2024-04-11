#include <bits/stdc++.h>
#define maxn 1000005
int head[maxn],vis[maxn]={0}, sccsize[maxn], lowdex[maxn],sccno[maxn],idx=0,cnt=0,n,m;
std::stack<int>stk;
 
struct edge {
    int v, next;
} edges[2*maxn]; int tail;
int add_edge(int u, int v) {
    edges[++tail].v=v;
    edges[tail].next=head[u];
    head[u]=tail;
}
 
int dfs(int u, int fa) {
    int ch = 0;
    stk.push(u);
    vis[u]=++idx;
    lowdex[u]=idx;
    for (int i = head[u]; i; i=edges[i].next) {
        if (!vis[edges[i].v]) {
            dfs(edges[i].v, u);
            lowdex[u]=std::min(lowdex[u],  lowdex[edges[i].v]);
        } else if (!sccno[edges[i].v]) {
            lowdex[u]=std::min(lowdex[u],  lowdex[edges[i].v]);
        }
    }if (vis[u]==lowdex[u]) {
        int size=0; cnt++;
        while (stk.top()!=u) {
        	if (!sccno[stk.top()]) {
	            sccno[stk.top()]=cnt;
	            size+=1;
	        }
            stk.pop();
        }sccno[u]=cnt;
        sccsize[cnt]=size+1;
    }
}
 
 
void solve(){
	scanf("%d%d",&n,&m);
	if (n==1){printf("NO\n");return;}
	for(int i=1;i<=n;++i)lowdex[i]=sccsize[i]=head[i]=sccno[i]=vis[i]=0;
	while (!stk.empty())stk.pop();
	cnt=0;tail=0;idx=0;
	for(int i=1;i<=m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		if (u!=v)add_edge(u,v);
	}for (int i=1;i<=n;i++){
        if(!vis[i]) dfs(i,-1);
    }
	if (cnt==1){printf("No\n");return;}
	else {
		printf("Yes\n");
		printf("%d %d\n",sccsize[1],n-sccsize[1]);
		for(int i=1;i<=n;++i){if (sccno[i]==1)printf("%d ",i);}printf("\n");
		for(int i=1;i<=n;++i){if (sccno[i]!=1)printf("%d ",i);}printf("\n");
	}
}
	
		
 
int main(){
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}