#include<bits/stdc++.h>
using namespace std;
const int MAXN=100111;
const int INF=(int)1e9+69;
int ilosc[MAXN];
int ilosc1[MAXN];
int access[MAXN];
main(){
	int test;scanf("%d",&test);
	while(test--){
		int m,k;scanf("%d%d",&m,&k);
		for(int i=1;i<=k;i++) scanf("%d",&ilosc[i]);
		int pierwr=0;
		int zera=0;
		int zera1=0;
		for(int i=1;i<m;i++){
			int t,r;scanf("%d%d",&t,&r);
			if(pierwr==0&&r==0){
				if(t==0) zera++;
				else ilosc[t]--;
				continue;
			}
			if(pierwr==0&&r==1){
				pierwr=1;
				zera1=zera;
				//printf("nowy %d %d:: ",i,zera);
				for(int j=1;j<=k;j++){
					ilosc1[j]=ilosc[j];
					if(ilosc1[j]<=zera1) access[j]=1;
					//printf("%d %d %d;; ",j,ilosc1[j],access[j]);
				}
				access[t]=0;
				if(t==0)zera++;
				else ilosc[t]--;
				continue;
			}
			if(pierwr==1){
				access[t]=0;
				if(t==0)zera++;
				else ilosc[t]--;
			}
		}
		int minw=INF;
		for(int i=1;i<=k;i++){
			if(access[i]) minw=min(minw,ilosc1[i]);
		}
		if(pierwr==0) minw=0;
		//printf("%d::\n",minw);
		//for(int i=1;i<=k;i++) printf("%d %d %d\n",i,access[i],ilosc[i]);
		for(int i=1;i<=k;i++){
			if(access[i]){printf("Y");continue;}
			if(zera-minw>=ilosc[i]) printf("Y");
			else printf("N");
		}
		puts("");
		for(int i=1;i<=k;i++)
			ilosc[i]=ilosc1[i]=access[i]=0;
	}
	return 0;
}