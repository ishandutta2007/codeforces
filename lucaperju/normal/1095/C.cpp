#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;
long long v[50];
int main()
{
    long long t,n,i,j=0,k,s=0,st,cnt=0;
    cin>>n>>k;
    i=n;
    while(n)
    {
        if(n&1LL)
        {
            ++cnt;
            ++v[j];
        }
        n>>=1LL;
        ++j;
    }
    n=i;
    if(k>=cnt && k<=n)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
        return 0;
    }
    k-=cnt;
    for(i=35;i>=1;--i)
    {
        if(v[i]<=k)
        {
            v[i-1]+=v[i]*2LL;
            k-=v[i];
            v[i]=0;
        }
        else
        {
            v[i-1]+=k*2LL;
            v[i]-=k;
            break;
        }
    }
    k=1;
    for(i=0;i<=30;++i)
    {
        for(j=1;j<=v[i];++j)
            cout<<k<<' ';
        k<<=1LL;
    }
}