#include <bits/stdc++.h>

using namespace std;
int v[100005];
int main()
{
    int i,j,n,m,k=0,cnt=0,s=0,mx=-9999999999LL,mn=9999999999LL,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        sort(v+1,v+n+1);
        cout<<min(v[n-1]-1,n-2)<<'\n';
    }
    return 0;
}