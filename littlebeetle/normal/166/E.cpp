#include<cstdio>
const int M=1000000007;
int n;
unsigned f[4],g[4],i;
int main(){
	scanf("%d",&n);
	f[0]=1;
	while(n--){
		for(i=0;i<4;i++)
			g[i]=(f[i+1&3]+f[i+2&3]+f[i+3&3])%M;
		for(i=0;i<4;i++)
			f[i]=g[i],g[i]=0;
	}
	printf("%d",f[0]);
	//while(1);
}