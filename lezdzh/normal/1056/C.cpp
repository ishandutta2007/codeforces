#include<cstdio>

using namespace std;

int p[2001],w[2001],z[2001];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=2*n;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		w[u]=v;
		w[v]=u;
	}
	int t;
	scanf("%d",&t);
	for(int i=1;i<=n;i++)
		if(t==1){
			int o=0;
			for(int i=1;i<=2*n;i++)
				if(!z[i]&&(w[i]&&!w[o]||!w[i]==!w[o]&&p[i]>p[o]))
					o=i;
			printf("%d\n",o);
			z[o]=1;
			fflush(stdout);
			scanf("%d",&o);
			z[o]=1;
		}
		else{
			int o;
			scanf("%d",&o);
			z[o]=1;
			if(w[o]&&!z[w[o]]){
				printf("%d\n",w[o]);
				z[w[o]]=1;
				fflush(stdout);
				continue;
			}
			o=0;
			for(int i=1;i<=2*n;i++)
				if(!z[i]&&(w[i]&&!w[o]||!w[i]==!w[o]&&p[i]>p[o]))
					o=i;
			printf("%d\n",o);
			z[o]=1;
			fflush(stdout);
		}
}