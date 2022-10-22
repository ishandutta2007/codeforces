#include<bits/stdc++.h>
using namespace std;
const int N=10020;
int T,n,a[N],q[N],ovo[N],sum;
int main(){
//	srand(time(NULL));
//	srand(rand());
//	srand(rand());
//	srand(rand());
//	srand(rand());
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);

//n=rand()%100+3;
//if(n%2==0)continue;
		int ok=1;
		
//		for(int i=1;i<=n;i++)a[i]=i;
//		for(int i=1;i<=n-1;i++){
//			int k=rand()%n+1,k2=rand()%n+1;
//			if(k%2==(k2%2))swap(a[k],a[k2]);
//		}
		
		for(int i=1;i<=n;i++){
//			ovo[i]=a[i];
			scanf("%d",&a[i]);
			if((a[i]%2)!=(i%2)){
				ok=0;
			}
		}
		
		if(ok==0){
			printf("-1\n");
			continue;
		}
		sum=0;
		
		for(int i=n;i>1;i-=2){
			int vi,vi0;
			for(int io=1;io<=n;io++){
				if(a[io]==i){
					vi=io;
				}
				if(a[io]==i-1){
					vi0=io;
				}
			}
			if(vi0!=vi+1){
				q[++sum]=vi;	
			for(int io=1;io<=vi;io++){
				if(io==vi-io+1)break;
				swap(a[io],a[vi-io+1]);
			}
			vi=1;
			for(int io=1;io<=n;io++){
				if(a[io]==i){
					vi=io;
				}
				if(a[io]==i-1){
					vi0=io;
				}
			}
			q[++sum]=vi0-1;	
			for(int io=1;io<=vi0-1;io++){
				if(io==vi0-1-io+1)break;
				swap(a[io],a[vi0-1-io+1]);
			}
			vi=vi0-1;	
			
			for(int io=1;io<=n;io++){
				if(a[io]==i){
					vi=io;
				}
				if(a[io]==i-1){
					vi0=io;
				}
			}
			}
			if(vi0==vi+1){
				q[++sum]=vi0+1;
				
			for(int io=1;io<=vi0+1;io++){
				if(io==vi0+1-io+1)break;
				swap(a[io],a[vi0+1-io+1]);
			}
			for(int io=1;io<=n;io++){
				if(a[io]==i){
					vi=io;
				}
				if(a[io]==i-1){
					vi0=io;
				}
			}
			}
			if(vi0!=vi-1){
				ok=0;
				break;
			}
			q[++sum]=vi;	
			for(int io=1;io<=vi;io++){
				if(io==vi-io+1)break;
				swap(a[io],a[vi-io+1]);
			}
			
			for(int io=1;io<=n;io++){
				if(a[io]==i){
					vi=io;
				}
				if(a[io]==i-1){
					vi0=io;
				}
			}
			q[++sum]=i;
			for(int io=1;io<=i;io++){
				if(io==i-io+1)break;
				swap(a[io],a[i-io+1]);
			}
			
		}
		
		if(ok==0){
			printf("-1\n");
			continue;
		}
		
		printf("%d\n",sum);
//		for(int i=1;i<=n;i++){
//			if(i!=a[i]){
//				printf("ERROR\n");
//				for(int v=1;v<=n;v++)printf("%d ",ovo[v]);
//				
//				return 0;
//			}
//		}
		for(int i=1;i<=sum;i++)printf("%d ",q[i]);
		printf("\n");
	}
}
/*
1
9
1 2 3 6 9 8 7 4 5
7 8 9 6 3 2 1
9 8 7 6 3 2 1

*/