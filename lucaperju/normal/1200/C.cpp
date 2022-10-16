#include <bits/stdc++.h>

using namespace std;
long long v[103];
long long cmmdc (long long a, long long b)
{
    long long r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    long long k=0,t,i,j=0,cnt=0,n,is,js,ib,jb,s=0,cur=0,q,m;
    cin>>n>>m>>t;
    long long cmdc=cmmdc(n,m);
    while(t--)
    {
        long long a,b,c,d;
        cin>>a>>b>>c>>d;
        long long sect1=n/cmdc;
        long long sect2=m/cmdc;
        long long pza;
        if(a==1)
            pza=(b-1LL)/sect1+1;
        else
            pza=(b-1LL)/sect2+1;
        long long pzb;
        if(c==1)
            pzb=(d-1LL)/sect1+1;
        else
            pzb=(d-1LL)/sect2+1;
        if(pza==pzb)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}