#include <bits/stdc++.h>
using namespace std;
int v[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int i,j,n,t,m;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
        {
            char c;
            cin>>c;
            v[i]=c-'0';
        }
        for(i=1;i<=n;++i)
            if(v[i]==1)
                break;
        for(j=n;j>=1;--j)
            if(v[j]==0)
                break;
        if(i>=j)
        {
            for(i=1;i<=n;++i)
                cout<<v[i];
            cout<<'\n';
            continue;
        }
        else
        {
            for(int k=1;k<=i;++k)
                cout<<0;
            for(int k=n;k>j;--k)
                cout<<1;
            cout<<'\n';
        }
    }
    return 0;
}