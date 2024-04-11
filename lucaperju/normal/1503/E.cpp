#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
int fct[4500],invfct[4500];
int lgput (int a, int exp)
{
    int rz=1;
    while(exp)
    {
        if(exp%2)
        {
            --exp;
            rz=(rz*1LL*a)%mod;
        }
        else
        {
            a=(a*1LL*a)%mod;
            exp>>=1;
        }
    }
    return rz;
}
int cmb (int n, int k)
{
    return fct[n]*1LL*invfct[n-k]%mod*1LL*invfct[k]%mod;
}
int get (int fel, int lc, int cc)
{
    if(fel==2)
        return cmb(lc+cc,lc);
    if(fel==1)
        return cmb(lc+m-cc,lc);
    if(fel==3)
        return cmb(cc+n-lc,cc);
    if(fel==4)
        return cmb(n+m-cc-lc,n-lc);
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,d,i,j;
    int s=0;
    cin>>n>>m;
    fct[0]=fct[1]=invfct[0]=invfct[1]=1;
    for(i=2;i<=4300;++i)
        fct[i]=i*1LL*fct[i-1]%mod;
    for(i=2;i<=4300;++i)
        invfct[i]=lgput(fct[i],mod-2);
    int l,c;
    int sc;
    for(l=1;l<n;++l)
    {
        sc=0;
        for(c=1;c<m;++c)
        {
            sc+=get(3,l,c-1)*1LL*get(4,l+1,c)%mod;
            if(sc>=mod)
                sc-=mod;
            s+=sc*1LL*get(1,l,c+1)%mod*1LL*get(2,l-1,c)%mod;
            if(s>=mod)
                s-=mod;
        }
        sc=0;
        for(c=m-1;c>=1;--c)
        {
            s+=sc*1LL*get(1,l-1,c)%mod*1LL*get(2,l,c-1)%mod;
            if(s>=mod)
                s-=mod;
            sc+=get(3,l+1,c)*1LL*get(4,l,c+1)%mod;
            if(sc>=mod)
                sc-=mod;
        }
    }
    swap(n,m);
    for(l=1;l<n;++l)
    {
        sc=0;
        for(c=1;c<m;++c)
        {
            sc+=get(3,l,c-1)*1LL*get(4,l+1,c)%mod;
            if(sc>=mod)
                sc-=mod;
            s+=sc*1LL*get(1,l,c+1)%mod*1LL*get(2,l-1,c)%mod;
            if(s>=mod)
                s-=mod;
        }
        sc=0;
        for(c=m-1;c>=1;--c)
        {
            s+=sc*1LL*get(1,l-1,c)%mod*1LL*get(2,l,c-1)%mod;
            if(s>=mod)
                s-=mod;
            sc+=get(3,l+1,c)*1LL*get(4,l,c+1)%mod;
            if(sc>=mod)
                sc-=mod;
        }
    }
    cout<<s;
	return 0;
}