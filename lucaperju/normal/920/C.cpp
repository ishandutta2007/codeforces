#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
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
long long v[200005];
bool verif (int i, int j)
{
    int k;
    for(k=i;k<=j;++k)
        if(v[k]<i || v[k]>j)
            return false;
    return true;
}
int main()
{
    long long a,b,nrca,nrcb,n,i,j=1,ca,cb,mx=9999999999,mn=9999999999,s=0,k,x,y,z,nr0=0,nrb,ok=1,poz,cur=0,m,cn,cnt=0;
    char c;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=1;i<n;++i)
    {
        cin>>c;
        if(c=='0')
        {
            if(!verif(j,i))
            {
                cout<<"NO";
                return 0;
            }
            j=i+1;
        }
    }
    if(!verif(j,n))
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}