#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[501],dp[501][501];
main(){
    int n,m,b,p;
    cin>>n>>m>>b>>p;
    for(int x=1;x<=n;x++)
    cin>>a[x];
    dp[0][0]=1;
    for(int x=1;x<=n;x++)
    for(int y=1;y<=m;y++)
    for(int t=a[x];t<=b;t++)
    dp[y][t]=(dp[y][t]+dp[y-1][t-a[x]])%p;
	int ans=0;
    for(int x=0;x<=b;x++)
    ans+=dp[m][x];
    cout<<ans%p<<endl;
}