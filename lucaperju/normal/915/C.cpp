#include <iostream>
using namespace std;
long long cmmdc(long long a,long long b)
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
long long lgput (long long cnt, long long mod,long long put)
{
    long long r=1,p=put;
    if(cnt==0)
        return 1;
    else
    if(cnt<0)
        return 0;
    while(cnt>1)
    {
        if(!(cnt&1))
        {
            p=p*1LL*p%mod;
            cnt>>=1LL;
        }
        else
        {
            --cnt;
            r=r*1LL*p%mod;
        }
    }
    p=p*1LL*r;
    return p%mod;
}
int fv[15],bv[25];
int main()
{
    long long a,b,nrca,nrcb,n,i,j,c,ca,cb,mx=-9999999999,s=0,sa=0,cur=0,cc,y,k,ok=0;
    cin>>a>>b;
    ca=a;
    cb=b;
    while(ca)
    {
        ++fv[ca%10];
        ca/=10LL;
        ++sa;
    }
    while(cb)
    {
        ++s;
        cb/=10LL;
    }
    if(s>sa)
        ok=1;
    cb=b;
    while(cb)
    {
        bv[s--]=cb%10;
        cb/=10LL;
    }
    for(i=1;i<=sa;++i)
    {
        for(j=9;j>=0;--j)
            if(j<=bv[i] && fv[j] || ok && fv[j])
                break;
        if(j<bv[i])
        {
            cout<<j;
            cur=cur*10LL+j;
            --fv[j];
            ok=1;
            continue;
        }
        cc=cur*10LL+j;
        --fv[j];
        for(y=0;y<=9;++y)
            for(k=1;k<=fv[y];++k)
                cc=cc*10LL+y;
        if(cc<=b)
        {
            cout<<j;
            cur=cur*10LL+j;
            continue;
        }
        ++fv[j];
        for(--j;j>=0;--j)
            if(fv[j])
                break;
        cout<<j;
        cur=cur*10LL+j;
        --fv[j];
        ok=1;
    }
    return 0;
}