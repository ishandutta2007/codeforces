#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000007];
long long dp[2][10][10];
long long inf=1;
int main()
{
	int b;
	for(int i=1;i<=18;i++) inf=inf*10;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) {
		scanf("%d",&b);
		a[b]++;
	}
	int t;
	int g=0;
	for(int i=0;i<5;i++) {
		for(int j=0;j<5;j++) dp[1][i][j]=-inf;
	}
	dp[1][0][0]=0;
	for(int i=1;i<=m;i++) {
		for(int j=0;j<3;j++) {
			for(int k=0;k<=min(a[i],4);k++) {
				dp[g][j][k]=-inf;
				for(int p=0;p<3;p++) {
					for(int q=j;q<5;q++) {
						t=min(a[i]-k,min(p,q-j));
						dp[g][j][k]=max(dp[g][j][k],dp[g^1][p][q]+t+(a[i]-k-t)/3);
						//cout<<i<<" "<<j<<" "<<k<<" "<<t<<" "<<dp[g][j][k]<<endl;
					}
				}
			}
			for(int k=a[i]+1;k<5;k++) dp[g][j][k]=-inf;
		}
		g=g^1;
	}
	g=g^1;
	long long r=0;
	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) r=max(r,dp[g][i][j]);
	}
	printf("%lld",r);
	return 0;
}