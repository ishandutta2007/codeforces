#include <iostream>
#include <algorithm>
#include <cstring>
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
    while(cnt>1)
    {
        if(!(cnt&1))
        {
            p=p*1LL*p%mod;
            cnt>>=1;
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
long long fct[20],rez=0;
void frmfct ()
{
    long long i;
    fct[1]=1;
    for(i=2;i<=19;++i)
        fct[i]=fct[i-1]*i;
}
long long fv[11],fvc[11];
long long sum ()
{
    long long i,s=0,rzc=1,jos=1,sus;
    for(i=0;i<=9;++i)
        s+=fvc[i];
    sus=fct[s];
    for(i=0;i<=9;++i)
        if(fvc[i])
            jos=jos*fct[fvc[i]];
    rzc=sus/jos;
    if(fv[0])
    {
        sus=fct[s-1];
        jos=jos/fvc[0];
        rzc-=sus/jos;
    }
    return rzc;
}
void bck (long long poz)
{
    if(poz==10)
    {
        rez=rez+0LL+sum();
        return;
    }
    if(!fv[poz])
        bck(poz+1);
    for(long long i=1;i<=fv[poz];++i)
    {
        fvc[poz]=i;
        bck(poz+1);
    }
}
int main()
{
    long long n;
    cin>>n;
    frmfct();
    while(n)
    {
        fv[n%10]++;
        n/=10;
    }
    bck(0);
    cout<<rez;
    return 0;
}