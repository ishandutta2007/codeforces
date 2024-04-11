#include <bits/stdc++.h>
using namespace std;
int v[100005];
int cv[100005];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        for(i=1;i<=n;++i)
            cv[i]=v[i];
        sort(cv+1,cv+n+1);
        for(i=1;i<=n;++i)
        {
            if(v[i]!=cv[i] && v[i]%cv[1]!=0)
                break;
        }
        if(i==n+1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}