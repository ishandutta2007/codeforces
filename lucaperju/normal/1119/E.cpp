#include <bits/stdc++.h>

using namespace std;
long long v[300003];
int main()
{
    long long add=1,t,h,n,i,j,mn=100003LL*100003LL,k,mx=0,rz=0,tot,m,obj,st,cntp=0,cnti=0,s=0,nri=0,a,b,a2,b2,a3,b3;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=n;i>=1;--i)
    {
        s+=v[i]/2LL;
        if(v[i]%2LL && s)
            ++rz,--s;
    }
    cout<<rz+s*2/3; /// test, sa vad daca ar fi luat accepted
    return 0;
}