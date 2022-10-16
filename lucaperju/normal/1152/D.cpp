#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
using namespace std;
const long long INF=100000000000000LL;
const long long mod=1000000007;
long long d[2003][2003][2];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long pz,add=1,t,i,j,mn=(1LL<<62)-1+(1LL<<62),k=0,mx=-999999999999LL,tot,n,m,obj,cnt=0,cnti=0,b2,a3,b3,ok=0,val;
    long long ra,rb,dv=-1,dv1=-1;
    long long a,b;
    cin>>n;
    for(j=1;j<=n*2;++j)
    {
        d[0][j][0]=d[1][j-1][1];
        d[0][j][1]=(1+d[1][j-1][0])%mod;
        for(i=1;i<j;++i)
        {
            if((i+j)%2)
                continue;
            if(i>j)
                continue;
            d[i][j][0]=(d[i+1][j-1][1]+d[i-1][j-1][1])%mod;
            d[i][j][1]=(1+max(d[i+1][j-1][1]+d[i-1][j-1][0],d[i+1][j-1][0]+d[i-1][j-1][1])%mod)%mod;
        }
        d[i][j][1]=(1+d[i-1][j-1][0])%mod;
        d[i][j][0]=d[i-1][j-1][1];
    }
    cout<<max(1+d[1][2*n-1][0],d[1][2*n-1][1])%mod;
    return 0;
}