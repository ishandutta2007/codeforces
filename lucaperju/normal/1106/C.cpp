#include <bits/stdc++.h>

using namespace std;
long long v[300005];
int main()
{
    long long n,i,j=1,k,s=0,cur,pz,m,ok=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
    }
    sort(v+1,v+n+1);
    for(i=1;i<=n/2;++i)
        s=s+(v[i]+v[n-i+1])*1LL*(v[i]+v[n-i+1]);
    cout<<s;
    return 0;
}