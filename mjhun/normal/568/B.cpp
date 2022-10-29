#include <cstdio>
#define MOD 1000000007

typedef unsigned int uint;

inline uint summod(uint a,uint b){
	uint r=a+b;
	if(r>=MOD)r-=MOD;
	return r;
}

uint c[4096][4096];
uint b[4096][4096];
int n;

int main(){
	for(int i=0;i<=4000;++i){
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;++j)c[i][j]=summod(c[i-1][j-1],c[i-1][j]);
	}
	b[0][0]=1;
	for(int i=1;i<=4000;++i){
		b[i][0]=b[i-1][i-1];
		for(int j=1;j<=i;++j){
			b[i][j]=summod(b[i-1][j-1],b[i][j-1]);
		}
	}
	scanf("%d",&n);
	uint r=0;
	for(int i=1;i<=n;++i){
		r=summod(r,(1LL*c[n][i]*b[n-i][0])%MOD);
	}
	printf("%u\n",r);
	return 0;
}