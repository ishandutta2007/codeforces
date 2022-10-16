#include <bits/stdc++.h>
using namespace std;
int v[200005];
int main()
{
    long long t,n,m,i,j,x,y,k,l,r;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
        }
        sort(v+1,v+n+1);
        for(i=2;i<=n;++i)
        {
            if(v[i]>v[i-1]+1)
                break;
        }
        if(i==n+1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}