#include<cstdio>
#include<vector>
#include<map>
using namespace std;

vector<int>g[300001];
map<int,int>e[300001];
int a[300001],b[300001],c[300001];
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n,m;
		scanf("%d%d",&n,&m);
		n*=3;
		for(int i=1;i<=n;i++){
			g[i].clear();
			e[i].clear();
			a[i]=b[i]=c[i]=0;
		}
		a[0]=b[0]=c[0]=0;
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
			e[u][v]=e[v][u]=i;
		}
		for(int u=1;u<=n;u++){
			for(int i=0;i<g[u].size();i++)
				if(a[g[u][i]]){
					b[++b[0]]=g[u][i];
					c[++c[0]]=u;
					a[0]--;
					a[g[u][i]]=0;
					goto ed;
				}
			a[0]++;
			a[u]=1;
			ed:;
			if(a[0]>=n/3){
				printf("IndSet\n");
				for(int i=1,f=0;i<=n;i++)
					if(a[i])printf(f++?" %d":"%d",i);
				printf("\n");
				break;
			}
			if(b[0]>=n/3){
				printf("Matching\n");
				for(int i=1,f=0;i<=b[0];i++)
					printf(f++?" %d":"%d",e[b[i]][c[i]]);
				printf("\n");
				break;
			}
		}
	}
}