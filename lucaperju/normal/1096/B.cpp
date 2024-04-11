#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;
char v[200005];
const int mod=998244353;
int main()
{
    long long t,n,i,j=0,k=0,s=1,okneg=0,cnt=0,mn=99999999999999LL,m,cur,pz,a,b,d,vl1=1;
    cin>>n>>ws>>(v+1);
    a=v[1];
    b=v[n];
    for(i=n;i>=1;--i)
    {
        if(v[i]==a && k==0)
            ++vl1;
        else
            k=1;
        if(!okneg)
        {
            if(v[i]==b)
                ++s;
            else
                okneg=1;
        }
    }
    s%=mod;
    for(i=1;i<=n;++i)
    {
        if(v[i]!=a)
            break;
        else
        {
            s+=min(n-i,vl1);
            s%=mod;
        }
    }
    cout<<s;
}