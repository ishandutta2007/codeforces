#include<cstdio>
#define ri register int
int n,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(ri i=1;i<n;++i){
			ri j=i+1;
			if(!(n&1)&&(i&1))++j,printf("0 ");
			for(;j<=n;++j)
				printf("%d ",(j-i)&1?-1:1);
		}	
		putchar(10);
	}
	return 0;
}