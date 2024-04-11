#include <bits/stdc++.h>

using namespace std;

long long dp[1000006];
const int mod=1000000007;
long long tot=1;
char v[1000006];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>(v+1);
    int i;
    long long rz=1;
    int n=strlen(v+1);
    for(i=1;i<=n;++i)
        if(v[i]=='1')
            break;
    int p1=i;
    if(i==n+1)
    {
        cout<<n;
        return 0;
    }
    rz=rz*i;
    for(i=n;i>=1;--i)
        if(v[i]=='1')
            break;
    int p2=i;
    rz=rz*1LL*(n-i+1)%mod;
    i=p1+1;
    while(i<=p2)
    {
        int cnt=0;
        while(v[i]=='0')
        {
            ++i;
            ++cnt;
        }
        //cout<<cnt<<' ';
        ++i;
        long long ctot=tot;
        for(int j=0;j<=cnt;++j)
        {
            tot=(tot+ctot-dp[j]+mod)%mod;
            dp[j]=ctot;
        }
    }
    cout<<tot*1LL*rz%mod;
    return 0;
}