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
long long v[2005];
int main()
{
    long long n,i,j,cnt=0,cmc,mn=9999999;
    cin>>n;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    cmc=v[1];
    if(cmc==1)
    {
        for(i=1; i<=n; ++i)
            if(v[i]!=1)
                ++cnt;
        cout<<cnt;
        return 0;
    }
    j=1;
    while(j<=n)
    {
        for(i=j+1; i<=n; ++i)
        {
            cmc=cmmdc(cmc,v[i]);
            if(cmc==1)
                break;
        }
        if(cmc!=1)
            break;
        j=i+1;
        cmc=v[i];
        for(;i>=1;--i)
        {
            if(cmc==1)
                break;
            cmc=cmmdc(cmc,v[i]);
            if(cmc==1)
                break;
        }
        if(j-i-1<mn)
            mn=j-i-1;
    }
    if(mn!=9999999)
    for(i=1;i<=n;++i)
        if(v[i]!=1)
            ++cnt;
    if(mn!=9999999 && mn!=0)
        cout<<cnt+mn-1;
    else if(mn!=9999999)
        cout<<cnt;
    else
        cout<<-1;
    return 0;
}