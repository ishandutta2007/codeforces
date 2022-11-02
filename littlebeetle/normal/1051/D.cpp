#include<cstdio>
const int N=1003,M=998244353;
int n,k,i,j,a,b,f[N][N*2][4];
long long ans;
int abs(int x){
	return x>0?x:-x;
}
int main(){
	scanf("%d%d",&n,&k);
	f[1][0][0]=f[1][0][1]=f[1][0][2]=f[1][0][3]=1;
	for(i=1;i<=n;i++)
		for(j=0;j<=i*2&&j<=k;j++)
			for(a=0;a<4;a++)
				for(b=0;b<4;b++)
					f[i+1][j+((a^b)&1)+((a^b)>>1)-((abs(a-b)==3)|((a>>1)==(a&1)&&(b>>1)!=(b&1)))][b]=(f[i+1][j+((a^b)&1)+((a^b)>>1)-((abs(a-b)==3)|((a>>1)==(a&1)&&(b>>1)!=(b&1)))][b]+f[i][j][a])%M;
	ans+=f[n][k-1][0]+f[n][k-1][3];
	if(k>1)
		ans+=f[n][k-2][1]+f[n][k-2][2];
	printf("%d",(int)(ans%M));
}