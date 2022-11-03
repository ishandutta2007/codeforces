#include<bits/stdc++.h>
using namespace std;
const int maxn=1e2+10;
int dp[maxn];
int a[maxn];
int main()
{
    int sum=0;
    int n;
    cin>>n;
    int max1=-1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==1)
            dp[i]=max(dp[i-1]-1,-1);
        else
            dp[i]=max(1,dp[i-1]+1);
    }
    cout<<*max_element(dp,dp+n)+sum;
}