#include <bits/stdc++.h>
using namespace std;
int v[200005];
int main()
{
    long long n,m,i,j,x,y,k,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        for(i=n-1;i>=1;--i)
        {
            if(v[i]<v[i+1])
                break;
        }
        for(;i>=1;--i)
        {
            if(v[i]>v[i+1])
                break;
        }
        cout<<i<<'\n';
    }
    return 0;
}