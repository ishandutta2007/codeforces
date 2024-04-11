#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
int n,a[N];ll dp[N][3][2][2];
void W(ll &x,ll y) {x=max(x,y);}
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	if(n==1) {printf("%d\n",a[1]);return 0;} 
	for(int i=1;i<=n;++i) for(int j=0;j<3;++j) for(int k=0;k<2;++k)
		for(int k1=0;k1<2;++k1) dp[i][j][k][k1]=-1e18;
	dp[1][0][0][0]=a[1];dp[1][1][0][1]=-a[1];
	for(int i=2;i<=n;++i) for(int j=0;j<3;++j) for(int k=0;k<2;++k)
		for(int k1=0;k1<2;++k1) for(int k2=0;k2<2;++k2)
			W(dp[i][(j+k2)%3][k|(k1==k2)][k2],dp[i-1][j][k][k1]+(k2?-a[i]:a[i]));
	printf("%lld\n",max(dp[n][(4-n%3)%3][1][0],dp[n][(4-n%3)%3][1][1]));return 0;
}