#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
using namespace std;
const long long INF=100000000000000LL;
long long stp[200],put[200];
const long long z18=1000000000000000000LL;
const long long mod=1000000007;
int main()
{
   /* ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand ( time(NULL) );*/
    long long pz,add=1,t,h,i,j,n,mn=10000030LL*10000030LL,k=0,mx=-999999999999LL,tot,m,obj,cnt=0,cnti=0,nri=0,b2,a3,b3,a,b,ok=0;
    long long ra,rb,dv=-1,dv1=-1,l,r;
    cin>>l>>r;
    stp[2]=2;
    long long sc=2;
    add=4;
    i=2;
    while(i<60)
    {
        sc+=add;
        add=add*4LL;
        ++i;
        stp[++i]=sc;
    }
    stp[1]=1;
    sc=1;
    add=2;
    i=1;
    while(i<61)
    {
        sc+=add;
        add=add*4LL;
        ++i;
        stp[++i]=sc;
    }
    put[1]=1;
    for(i=2;i<=62;++i)
        put[i]=put[i-1]*2LL;
    int incst=-1,incdr=-1;
    for(i=1;i<=61;++i)
    {
        if(incst==-1)
        if(put[i]<=l && put[i+1]>l)
            incst=i;
        if(incdr==-1)
        if(put[i]<=r && put[i+1]>r)
            incdr=i;
    }
    if(incst==incdr)
    {
        long long rz=(stp[incst]%mod+2LL*(l-put[incst])%mod)%mod;
        rz=(rz*1LL*((r-l+1)%mod))%mod;
        rz=(rz+(((r-l)%mod)*1LL*((r-l+1)%mod))%mod)%mod;
        cout<<rz;
        return 0;
    }
    long long incp,sfp,inci,sfi;
    if(incst%2==1)
        incp=stp[incst+1];
    else
        inci=stp[incst+1];
    if(incdr%2==1)
        sfp=stp[incdr+1]-2LL;
    else
        sfi=stp[incdr+1]-2LL;
    if(incst%2==1)
        inci=stp[incst]+2LL*(l-put[incst]);
    else
        incp=stp[incst]+2LL*(l-put[incst]);
    if(incdr%2==1)
        sfi=stp[incdr]+2LL*(r-put[incdr]);
    else
        sfp=stp[incdr]+2LL*(r-put[incdr]);
    long long rz;
    rz=((incp%mod)*1LL*(((sfp-incp)/2LL+1LL)%mod))%mod;
    rz=rz%mod;
    long long dst=((sfp-incp)/2LL+1LL)%mod;
    rz=(rz+(dst*1LL*(dst-1LL))%mod)%mod;
    ///------------------
    rz=(rz+((inci%mod)*1LL*(((sfi-inci)/2LL+1LL)%mod)%mod)%mod)%mod;
    rz=rz%mod;
    dst=((sfi-inci)/2LL+1LL)%mod;
    rz=(rz+(dst*1LL*(dst-1LL))%mod)%mod;
    cout<<rz;
    return 0;
}