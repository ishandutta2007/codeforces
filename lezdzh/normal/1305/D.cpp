#include<cstdio>
#include<set>
using namespace std;

set<int>g[1001];
int z[1001];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].insert(v);
		g[v].insert(u);
	}
	for(;;){
		z[0]=0;
		for(int i=1;i<=n;i++)
			if(g[i].size()==1)
				z[++z[0]]=i;
		printf("? %d %d\n",z[1],z[2]);
		fflush(stdout);
		int o;
		scanf("%d",&o);
		if(o==z[1]||o==z[2]){
			printf("! %d\n",o);
			return 0;
		}
		g[*g[z[1]].begin()].erase(z[1]);
		g[z[1]].clear();
		g[*g[z[2]].begin()].erase(z[2]);
		g[z[2]].clear();
		if(g[o].empty()){
			printf("! %d\n",o);
			return 0;
		}
	}
}