#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define N 55
#define mod 1000000007
using namespace std;

int n,m,dp[N][N][2],cbn[N][N];
int ksm(int x,int y){
	int t=1; for (; y; y>>=1,x=(ll)x*x%mod) if (y&1) t=(ll)t*x%mod;
	return t;
}
int main(){
	scanf("%d%d",&n,&m);
	int i,j,k,l,x,y,z,t;
	for (i=0; i<=n; i++){
		cbn[i][0]=1;
		for (j=1; j<=i; j++) cbn[i][j]=(cbn[i-1][j]+cbn[i-1][j-1])%mod;
	}
	dp[0][0][1]=dp[1][0][0]=1;
	for (i=2; i<=n; i++)
		for (j=1; j<i; j++){
			t=(ll)cbn[i-2][j-1]*i%mod;
			for (k=0; k<=(j>>1); k++)
				for (l=0; l<=(i-1-j>>1); l++)
					for (x=0; x<2; x++)
						for (y=0; y<2; y++){
							z=!(x&y);
							dp[i][k+l+z][z]=(dp[i][k+l+z][z]+(ll)dp[j][k][x]*dp[i-1-j][l][y]%mod*t)%mod;
						}
		}
	printf("%d\n",(ll)(dp[n][m][0]+dp[n][m][1])*ksm(n,mod-2)%mod);
	return 0;
}