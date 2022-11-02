#include<cstdio>
#include<cstring>
const int N=50002;
int T,n,i,k,p[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(p,0,sizeof(p));
		for(i=2;i*(i-1)/2<=n;i++);
		i--;
		k=i;
		p[k]=1;
		n-=i*(i-1)/2;
		while(i>=2){
			while(n>=i*(i-1)/2){
				p[i]++;
				n-=i*(i-1)/2;
			}
			i--;
		}
		printf("1");
		for(i=1;i<=k;i++){
			printf("3");
			while(p[i]--)
				printf("7");
		}
		printf("\n");
	}
	return 0;
}