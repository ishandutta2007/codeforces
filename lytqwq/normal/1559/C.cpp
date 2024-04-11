#include<bits/stdc++.h>
using namespace std;
const int N=40010;
int t,n,a[N];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int ok=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(i>=2&&ok==0){
				if(a[i]==1&&a[i-1]==0){
					ok=1;
					for(int v=1;v<=i-1;v++){
						printf("%d ",v);
					}
					printf("%d ",n+1);
					for(int v=i;v<=n;v++){
						printf("%d ",v);
					}
					printf("\n");
				}
			}
		}
		if(ok==1)continue;
		if(a[1]==1){
			printf("%d ",n+1);
			for(int v=1;v<=n;v++){
				printf("%d ",v);
			}
			printf("\n");
			continue;
		}
		if(a[n]==0){
			for(int v=1;v<=n;v++){
				printf("%d ",v);
			}
			printf("%d \n",n+1);
			continue;
		}
		printf("-1\n");
	}
}