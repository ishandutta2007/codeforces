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
/*
for(i=1;i<=n;++i)
*/
long long v[205];
void prm (int st, int dr)
{
    int a=v[dr];
    for(int i=dr;i>st;--i)
        v[i]=v[i-1];
    v[st]=a;
}
int main()
{
    long long n,i,j,a,b,c,mx=-1000000000000000000,mn=1000000000000000000,s=0,cat;
    cin>>n;
    for(i=1;i<=2*n;++i)
        cin>>v[i];
    for(i=1;i<=2*n;++i)
    {
        if(v[i]==v[i+1])
        {
            ++i;
            continue;
        }
        else
        {
            for(j=i+1;j<=n*2;++j)
            {
                if(v[j]==v[i])
                    break;
            }
            s+=j-i-1;
            prm(i+1,j);
            ++i;
        }
    }
    cout<<s;
    return 0;
}