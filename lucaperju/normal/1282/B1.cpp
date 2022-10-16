#include <iostream>
#include <algorithm>
using namespace std;
long long v[200005];
bool verif (long long n, long long k, long long p)
{
    long long pz=n;
    while(pz>=1)
    {
        if(pz>=k)
            p-=v[pz],pz-=k;
        else
            p-=v[pz],--pz;
    }
    if(p>=0)
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long n,m,p,k,i,j,ok=0,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>p>>k;
        for(i=1;i<=n;++i)
            cin>>v[i];
        sort(v+1,v+n+1);
        long long rz=0,pas=1<<20;
        while(pas)
        {
            if(rz+pas<=n && verif(rz+pas,k,p))
                rz+=pas;
            pas>>=1;
        }
        long long crz=rz-rz%k;
        pas=1<<20;
        while(pas)
        {
            if(crz+pas*1LL*k<=n && verif(crz+pas*1LL*k,k,p))
                crz+=pas*1LL*k;
            pas>>=1;
        }
        pas=1<<20;
        while(pas)
        {
            if(crz+pas<=n && verif(crz+pas,k,p))
                crz+=pas;
            pas>>=1;
        }
        cout<<max(rz,crz)<<'\n';
    }
}