#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
using namespace std;
const long long INF=100000000000000LL;
int a[2003],b[2003];
std::map<int,std::map<int,int> >mp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long pz,add=1,t,i,j,mn=10000030LL*10000030LL,k=0,mx=-999999999999LL,tot,n,m,obj,cnt=0,cnti=0,b2,a3,b3,ok=0,rz=0,val;
    long long ra,rb,dv=-1,dv1=-1;
    long long a00,a01,a10,a11;
    cin>>n;
    long long s=0;
    for(i=1;i<=n;++i)
        cin>>a[i]>>b[i];
    for(i=1;i<=n;++i)
        for(j=i+1;j<=n;++j)
        {
            //++mp[a[j]-a[i]][b[j]-b[i]],++mp[a[i]-a[j]][b[i]-b[j]];
            if(a[j]-a[i]>0 || a[j]-a[i]==0 && b[j]-b[i]>0)
                ++mp[a[j]-a[i]][b[j]-b[i]];
            else
                ++mp[a[i]-a[j]][b[i]-b[j]];
        }
    for(i=1;i<=n;++i)
        for(j=i+1;j<=n;++j)
        {
            int cj=j,ci=i;
            if(a[j]-a[i]>0 || a[j]-a[i]==0 && b[j]-b[i]>0){}
            else
                swap(i,j);
            s=s+(mp[a[j]-a[i]][b[j]-b[i]]*1LL*(mp[a[j]-a[i]][b[j]-b[i]]-1LL)/2LL);
            mp[a[j]-a[i]][b[j]-b[i]]=0;
            j=cj;
            i=ci;
        }
    cout<<s/2;
    return 0;
}