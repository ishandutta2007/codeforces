#include <bits/stdc++.h>
using namespace std;
#define N 5005
#define ll long long
int n,a[N],b[N];ll dp[N];
int min(int x,int y) {return x<y?x:y;}
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i) scanf("%d",&a[i]),b[i]=a[i];sort(b+1,b+n+1);
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) dp[j]=j==1?dp[j]+abs(a[i]-b[j]):min(dp[j-1],dp[j]+abs(a[i]-b[j]));
	printf("%lld\n",dp[n]);
}