#include <bits/stdc++.h>
using namespace std;
int v[10003];
long long st[10003],dr[10003];
int main()
{
    ios_base::sync_with_stdio(false);
    int i,j,n,t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>n>>m;
        for(i=1;i<=n;++i)
        {
            char c;
            cin>>c;
            v[i]=c-'0';
        }
        st[0]=1000000003;
        for(i=1;i<=n;++i)
        {
            if(v[i]==1)
                st[i]=0;
            else
                st[i]=1+st[i-1];
        }
        dr[n+1]=1000000003;
        for(i=n;i>=1;--i)
        {
            if(v[i]==1)
                dr[i]=0;
            else
                dr[i]=1+dr[i+1];
        }
        for(i=1;i<=n;++i)
        {
            if(v[i]==1 || st[i]!=dr[i] && min(st[i],dr[i])<=m)
                cout<<1;
            else
                cout<<0;
        }
        cout<<'\n';
    }
    return 0;
}