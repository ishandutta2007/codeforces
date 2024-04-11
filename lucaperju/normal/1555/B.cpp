#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 1000000007;
long long fct[200005],invfct[200005],inv[200005];
long long lgput (long long a, long long exp)
{
    long long rz=1;
    while(exp)
        if(exp&1)
            exp^=1,rz=rz*1LL*a%mod;
        else
            exp>>=1,a=a*1LL*a%mod;
    return rz;
}
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=1;
    for(long long i=2;i<=200000;++i)
        inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,i,j,k,m,n;
    cin>>t;
    while(t--)
    {
        int w,h,x1,x2,y1,y2;
        cin>>w>>h>>x1>>y1>>x2>>y2;
        int a,b;
        cin>>a>>b;
        if(a+(x2-x1)>w && b + (y2-y1)>h)
        {
            cout<<"-1\n";
            continue;
        }
        int x=-1000000000,y=-1000000000;
        if(a+(x2-x1)<=w)
        x=max(x1,w-x2);
        if(b + (y2-y1)<=h)
        y=max(y1,h-y2);
        cout<<min(max(0,a-x),max(0,b-y))<<'\n';
    }
    return 0;
}