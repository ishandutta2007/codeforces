#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

vector<int> g[100005];
int nc[100005];
bool vis[100005];

int res[100005];
int ft[100005];
int dis[100005][32];
int dt[100005];
int n,m;

int dfs(int v, int f){
	if(vis[v])return 0;
	nc[v]=1;
	for(int i=0;i<g[v].size();++i){
		int s=g[v][i];
		if(s==f)continue;
		nc[v]+=dfs(s,v);
	}
	return nc[v];
}

int centroid(int v){
	int m=nc[v],f=-1;
	while(1){
		int s=-1;
		for(int i=0;s<0&&i<g[v].size();++i){
			if(g[v][i]==f||vis[g[v][i]])continue;
			if(2*nc[g[v][i]]>=m)s=g[v][i];
		}
		if(s<0)break;
		f=v;
		v=s;
	}
	return v;
}

void dfs2(int v, int f, int d){
	for(int i=0;i<g[v].size();++i){
		int s=g[v][i];
		if(s==f||vis[s])continue;
		dis[s][d]=dis[v][d]+1;
		dfs2(s,v,d);
	}
}

void build(int v, int f, int d){
	dfs(v,-1);
	int k=centroid(v);
	dis[k][d]=0;
	dfs2(k,-1,d);
	ft[k]=f;
	dt[k]=d;
	vis[k]=true;
	for(int i=0;i<g[k].size();++i){
		int s=g[k][i];
		if(!vis[s])build(s,k,d+1);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n-1;++i){
		int a,b;
		scanf("%d%d",&a,&b);a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	build(0,-1,0);
	memset(res,1,sizeof(res));
	int w=0;
	while(w>=0){
		res[w]=min(res[w],dis[0][dt[w]]);
		w=ft[w];
	}
	while(m--){
		int t,v;
		scanf("%d%d",&t,&v);v--;
		if(t==1){
			int w=v;
			while(w>=0){
				res[w]=min(res[w],dis[v][dt[w]]);
				w=ft[w];
			}
		}
		else if(t==2){
			int r=1<<25;
			int w=v;
			while(w>=0){
				r=min(r,dis[v][dt[w]]+res[w]);
				w=ft[w];
			}
			printf("%d\n",r);
		}
		else {
		    int w;scanf("%d",&w);w--;
            printf("%d\n",dis[v][dt[w]]);
		}
	}
	return 0;
}