#include <bits/stdc++.h>

using namespace std;
char v[100005];
const int mod=1000000007;
long long d[100005];
int main()
{
    int t,n,i,j;
    long long rz=1;
    cin>>v;
    n=strlen(v);
    for(i=0;i<n;++i)
    {
        if(v[i]=='m' || v[i]=='w')
        {
            cout<<0;
            return 0;
        }
    }
    d[1]=1;
    d[2]=2;
    for(i=3;i<=n;++i)
        d[i]=(d[i-1]+d[i-2])%mod;
    for(i=0;i<n;++i)
    {
        if(v[i]=='n' && i<n-1 && v[i+1]=='n')
        {
            int cnt=0;
            for(j=i;j<n && v[j]=='n';++j)
                ++cnt;
            rz=(rz*1LL*d[cnt])%mod;
            i=j-1;
        }
        else
        if(v[i]=='u' && i<n-1 && v[i+1]=='u')
        {
            int cnt=0;
            for(j=i;j<n && v[j]=='u';++j)
                ++cnt;
            rz=(rz*1LL*d[cnt])%mod;
            i=j-1;
        }
    }
    cout<<rz;
    return 0;
}