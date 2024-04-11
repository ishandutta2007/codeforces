#include<stdio.h>
#include<string.h>
int a[1024],b[1024],x;
int main(){
	int n,t,k;
	scanf("%d%d%d",&n,&k,&x);
	for(int i=0; i<n; i++){
		scanf("%d",&t);
		a[t]++;
	}
	while(k--){
		memset(b,0,sizeof(b));
		bool f = true;
		for(int i=0; i<1024; i++)
			if(a[i] % 2 == 0){
				b[i] += a[i]/2;
				b[i^x] += a[i]/2;
			}else{
				if(f){
					b[i^x] += a[i]/2+1;
					b[i] += a[i]/2;
				}else{
					b[i^x] += a[i]/2;
					b[i] += a[i]/2+1;
				}
				f = !f;
			}
		memcpy(a,b,sizeof(b));
	}
	for(int X = 1023; X >= 0; X--)
		if(a[X]){printf("%d ",X);break;}
	for(int X = 0; X <= 1023; X++)
		if(a[X]){printf("%d\n",X);break;}
	return 0;
}