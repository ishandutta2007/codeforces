#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
#include <map>
using namespace std;
map <long long,long long> fv;
map <long long,long long> fv1;
long long v[200005],ok[200005],val[200005];
const long long mod=998244353;
int main()
{
    long long i,j,mx=-999999999999LL,pz=-1,n,k,cur=1,a=0,b=0,c=0,x,rez=1;
    long long mn=-mx;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        ++fv[v[i]];
    }
    for(i=1;i<=n;++i)
    {
        --fv[v[i]];
        if(fv[v[i]]==0)
            ok[i]=1;
    }
    for(i=n;i>=1;--i)
    {
        if(fv1[v[i]]==0)
            fv1[v[i]]=i,val[i]=i;
        else
            val[i]=fv1[v[i]];
    }
    if(ok[1])
        pz=-1;
    else
        pz=v[1];
    for(i=2;i<=n;++i)
    {
        if(pz==-1)
        {
            rez=rez*2LL;
            rez%=mod;
            pz=val[i];
        }
        if(i==pz)
            pz=-1;
        if(ok[i]==0)
            pz=max(pz,val[i]);
    }
    cout<<rez;
}