#include<cstdio>

using namespace std;

int p[100001],z[100001];
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int o;
			scanf("%d",&o);
			p[o]=i;
		}
		for(int i=1;i<=n;i++)
			z[i]=0;
		for(int i=1;i<=n;i++){
			z[p[i]]=1;
			while(p[i]!=n&&z[p[i]+1]!=1)
				if(p[i+1]==p[i]+1){
					z[p[i]+1]=1;
					i++;
				}
				else{
					printf("No\n");
					goto ed;
				}
		}
		printf("Yes\n");
		ed:;
	}
}