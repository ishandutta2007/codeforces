#include<bits/stdc++.h>
using namespace std;
const int nmax=3e3+42;
int n,a[nmax],b[nmax];
long long dp[nmax][nmax];
int main()
{
cin>>n;
for(int i=1;i<=n;i++)
{
cin>>a[i];
a[i]=a[i]-i;
b[i]=a[i];
}
sort(b+1,b+n+1);
dp[0][0]=0;
for(int j=1;j<=n;j++)
    dp[j][0]=1e18;
for(int pos=1;pos<=n;pos++)
    for(int maximum=1;maximum<=n;maximum++)
    {
    dp[pos][maximum]=min(dp[pos][maximum-1],dp[pos-1][maximum]+abs(a[pos]-b[maximum]));
    }
cout<<dp[n][n]<<endl;
return 0;
}