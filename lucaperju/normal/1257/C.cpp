#include <bits/stdc++.h>

using namespace std;
int v[200005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n,x,a,b,mn,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        mn=n+1;
        for(i=1;i<=n;++i)
            v[i]=0;
        for(i=1;i<=n;++i)
        {
            cin>>a;
            if(v[a])
                mn=min(mn,i-v[a]+1);
            v[a]=i;
        }
        if(mn==n+1)
            cout<<"-1\n";
        else
            cout<<mn<<'\n';
    }
    return 0;
}