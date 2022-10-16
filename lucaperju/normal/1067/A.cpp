#include <bits/stdc++.h>

using namespace std;
int d[100005][201][3],spj[100005][201],v[100005],sps[100005][201];
const long long mod=998244353;
int main()
{
    long long p,add=1,t,h,n,i,j,mn=100003LL*100003LL,k,mx=0,tot,m,obj,cnt=0,cnti=0,s=0,nri=0,b=0,a2,b2,a3,b3;
    char c;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=1;i<=200;++i)
    {
        d[1][i][0]=1;
        if(v[1]!=-1 && v[1]!=i)
            d[1][i][0]=0;
        spj[1][i]=(d[1][i-1][0]+spj[1][i-1])%mod;
    }
    for(i=2;i<=n;++i)
    {
        for(int val=1;val<=200;++val)
        {
            if(val!=v[i] && v[i]!=-1)
            {
                spj[i][val]=(((spj[i][val-1]+d[i][val-1][0])%mod+d[i][val-1][1])%mod+d[i][val-1][2])%mod;
                continue;
            }
            d[i][val][0]=spj[i-1][val];
            d[i][val][1]=((d[i-1][val][0]+d[i-1][val][1])%mod+d[i-1][val][2])%mod;
            d[i][val][2]=sps[i-1][val];
            spj[i][val]=(((spj[i][val-1]+d[i][val-1][0])%mod+d[i][val-1][1])%mod+d[i][val-1][2])%mod;
        }
        for(int val=199;val>=1;--val)
            sps[i][val]=((sps[i][val+1]+d[i][val+1][1])%mod+d[i][val+1][2])%mod;
    }
    for(int val=1;val<=200;++val)
    {
        s=(s+d[n][val][1])%mod;
        s=(s+d[n][val][2])%mod;
    }
    cout<<s;
    return 0;
}