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
char v1[105],v2[105];
int main()
{
    int n,cnt=0;
    cin>>v1>>v2;
    n=strlen(v1);
    for(int i=0;i<n;++i)
    {
        if(v1[i]=='0' && v2[i]=='0')
        {
            if(v1[i-1]=='0' || v2[i-1]=='0')
            {
                v1[i]=v2[i]=v1[i-1]=v2[i-1]='x';
                ++cnt;
                continue;
            }
            if(v1[i+1]=='0')
            {
                v1[i]=v2[i]=v1[i+1]='x';
                ++cnt;
                continue;
            }
            if(v2[i+1]=='0')
            {
                v1[i]=v2[i]=v2[i+1]='x';
                ++cnt;
                continue;
            }
        }
    }
    cout<<cnt;
    return 0;
}