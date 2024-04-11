#include <iostream>
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
int fv[1505];
int main()
{
    long long a,b,nrca,nrcb,n,i,j,c,ca,cb,mx=-9999999999,mn=9999999999,s=0,k,x,y,z,nra,nrb,ok,poz,cur=0,m;
    cin>>a>>b>>c;
    ++fv[a];
    ++fv[b];
    ++fv[c];
    if(fv[1] || fv[2]>=2 || fv[3]>=3)
        cout<<"YES";
    else
    {
        if(fv[2]==1 &&fv[4]==2)
            cout<<"YES";
        else
            cout<<"NO";
    }
    return 0;
}