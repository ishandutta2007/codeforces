#include<cstdio>
const int N=6;
int n,a,b,c,f[N][N];
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&a,&b);
		f[a][b]=f[b][a]=1;
	}
	for(a=1;a<=5;a++)
		for(b=a+1;b<=5;b++)
			for(c=b+1;c<=5;c++)
				if((f[a][b]+f[a][c]+f[b][c])%3==0){
					printf("WIN");
					return 0;
				}
	printf("FAIL");
}