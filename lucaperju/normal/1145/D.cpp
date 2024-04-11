#include <bits/stdc++.h>

using namespace std;
long long v[20];
int main()
{
    long long t,n,i,j,mn=100003LL*100003LL,k,mx=0,tot,m,obj,st,cntp=0,cnti=0,s=0,pz;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        mn=min(mn,v[i]);
    }
    cout<<2+(v[3]xor mn);
    return 0;
}