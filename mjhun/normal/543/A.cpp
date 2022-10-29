#include <cstdio>
typedef unsigned int uint;
uint n,m,b,MOD;
uint w[512][512];
uint a[512];

int main(){
	scanf("%d%d%d%d",&n,&m,&b,&MOD);
	for(int i=0;i<n;++i)
		scanf("%d",a+i);
	for(int k=0;k<=b;++k)
		w[0][k]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			for(int k=0;k<=b;++k)
				if(a[i-1]<=k)
					w[j][k]=(w[j][k]+w[j-1][k-a[i-1]])%MOD;

	printf("%d\n",w[m][b]);
	return 0;
}