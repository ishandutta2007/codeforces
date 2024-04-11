#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
using namespace std;
const long long INF=100000000000000LL;
const long long mod1=10000139LL;
const long long mod2=10002059LL;
const long long mod3=100001399LL;
const long long baza=10003193LL;
long long v[55];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m,pz,add=1,k=0,i,j,mn=1e9,mnc,mnc1,mx=-1,tot,obj,cnt=0,cnti=0,b2,a3,b3,ok=0,valm,s=0,pzx=0,my=-1,pzy=0,rz=0,mnf=1e9;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        mn=min(mn,v[i]);
    }
    for(i=1;i<=n;++i)
        if(v[i]==mn)
            ++cnt;
    if(cnt<=n/2)
        cout<<"Alice";
    else
        cout<<"Bob";
    return 0;
}