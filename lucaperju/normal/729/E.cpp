#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
using namespace std;
const long long INF=100000000000000LL;
int v[200005],fv[200005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long pz,add=1,t,i,j,mn=10000030LL*10000030LL,k=0,mx=-999999999999LL,tot,n,m,obj,cnt=0,cnti=0,b2,a3,b3,ok=0,rz=0,val;
    long long ra,rb,dv=-1,dv1=-1;
    cin>>n>>m;
    for(i=1;i<=n;++i)
        cin>>v[i];
    rz=0;
    for(i=1;i<=n;++i)
    {
        if(i!=m)
        {
            if(v[i]==0)
                ++rz;
        }
        else
            if(v[i]!=0)
                ++rz,v[i]=0,ok=1;
        ++fv[v[i]];
    }
    int ned=-rz+ok;
    for(i=1;i<=200000;++i)
        if(fv[i]==0)
            ++ned;
    int cr=0;
    for(i=200000;i>=1;--i)
    {
        if(!fv[i])
        {
            --ned;
            if(ned<=0)
            {
                cout<<cr+rz;
                return 0;
            }
            continue;
        }
        if(fv[i]>=ned)
        {
            cout<<rz+cr+ned;
            return 0;
        }
        cr+=fv[i];
        ned-=fv[i];
    }
    return 0;
}