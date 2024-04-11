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
vector <int> v[100003];
long long hsh[100003];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m,pz,add=1,k=0,i,j,mn=1e9,mnc,mnc1,mx=-1,tot,obj,cnt=0,cnti=0,b2,a3,b3,ok=0,valm,s=0,pzx=0,my=-1,pzy=0,rz=0,mnf=1e9;
    cin>>n>>m;
    for(i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        if(b>a)
        {
            v[a].push_back(b-a);
            a+=n;
            v[b].push_back(a-b);
        }
        else
        {
            v[b].push_back(a-b);
            b+=n;
            v[a].push_back(b-a);
        }
    }
    for(i=1;i<=n;++i)
    {
        sort(v[i].begin(),v[i].end());
        s=0;
        for(j=0;j<v[i].size();++j)
            s=(s*391027LL+v[i][j])%mod1;
        s=(s*102949LL+v[i].size())%mod2;
        hsh[i]=s;
    }
    long long put=1;
    for(i=1;i<n;++i)
        put=(put*1LL*baza)%mod3;
    s=0;
    for(i=1;i<=n;++i)
        s=(s*1LL*baza%mod3+hsh[i])%mod3;
    long long model=s;
    for(i=1;i<n;++i)
    {
        s=(s-(put*1LL*hsh[i])%mod3+mod3)%mod3;
        s=(s*1LL*baza%mod3+hsh[i])%mod3;
        if(s==model)
        {
            ok=1;
            break;
        }
    }
    if(ok)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}