#include <bits/stdc++.h>

using namespace std;
int v[300005];
int main()
{
    int i,j,n,m,k=0,cnt=0,s=0,mx=-9999999999LL,mn=9999999999LL,t;
    cin>>n>>k;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        if(i!=1)
            v[i-1]=v[i]-v[i-1];
    }
    --n;
    --k;
    sort(v+1,v+n+1);
    for(i=1;i<=n-k;++i)
        s+=v[i];
    cout<<s;
    return 0;
}