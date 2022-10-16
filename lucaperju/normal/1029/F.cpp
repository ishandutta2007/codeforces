#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
long long va[1000003],vb[1000003],ka,kb,a,b;
bool verif (long long x, long long y)
{
    long long pas=1<<20LL,k=0;
    while(pas)
    {
        if(k+pas<=ka && va[k+pas]<=x)
            k+=pas;
        pas>>=1LL;
    }
    if(a/va[k]<=y)
        return true;
    pas=1<<20LL;
    k=0;
    while(pas)
    {
        if(k+pas<=kb && vb[k+pas]<=x)
            k+=pas;
        pas>>=1LL;
    }
    if(b/vb[k]<=y)
        return true;
    return false;
}
int main()
{
    long long i,j,s=0,k,m,mn=999999999,ok=0,st,dr,t,rz,mxdr=0,c;
    cin>>a>>b;
    for(i=1;i*i<=a;++i)
        if(a%i==0)
            va[++ka]=i;
    for(i=1;i*i<=b;++i)
        if(b%i==0)
            vb[++kb]=i;
    c=a+b;
    for(i=1;i*i<=c;++i)
        if(c%i==0)
            if(verif(i,c/i))
                rz=i+0LL+c/i;
    cout<<rz*2LL;
}