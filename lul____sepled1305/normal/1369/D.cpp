#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int N = 2e6+10;
int i,n,a;
int dp_fi[N];
int dp[N][4];

int addi(int a,int b)
{
    long long cur =0LL+a+b;
    cur%=MOD;
    return (int) cur;
}

int multi(int a,int b)
{
    long long cur =1LL*a*b;
    cur%=MOD;
    return (int) cur;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    dp[0][3] = 1;
    dp_fi[0] = 1;
    for(i=1;i<N;i++)
    {
        dp[i][0]= addi(dp[i-1][0],dp[i-1][1]);
        dp[i][1]= dp[i-1][2];
        dp[i][2]= dp[i-1][3];
        dp[i][3]= addi(multi(2,dp[i-1][2]),dp[i-1][3]);
        if(i-3>=0)
            dp_fi[i] = addi(dp_fi[i-3], dp[i][3]);
        else
            dp_fi[i] = dp[i][3]%MOD;
    }
    cin>>n;
    for(i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(a<=2)
            cout<<"0\n";
        else if(a<=4)
            cout<<"4\n";
        else
            cout<<multi(4,dp_fi[a-3])<<"\n";
    }
}