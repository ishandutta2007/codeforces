#include <bits/stdc++.h>
using namespace std;
int v[200005],n;
int fv[10004];
int main()
{
    ios_base::sync_with_stdio(0);
    long long i,j,s=0,k,l,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        n*=4;
        for(i=1; i<=n; ++i)
        {
            cin>>v[i];
            ++fv[v[i]];
        }
        sort(v+1,v+n+1);
        int ok=1;
        for(i=1; i<=n; ++i)
        {
            if(fv[v[i]]%2==1)
            {
                ok=0;
                break;
            }
        }
        int cat=v[1]*1LL*v[n];
        for(i=2;i<=n/2;i+=2)
        {
            if(v[i]!=v[i-1] || v[n-i+1]!=v[n-i+2] || v[i]*v[n-i+2]!=cat)
                ok=0;
        }
        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
        for(i=1; i<=n; ++i)
            fv[v[i]]=0;
    }
    return 0;
}