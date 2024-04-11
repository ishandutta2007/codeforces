#include <bits/stdc++.h>
using namespace std;
char v[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,i,j,m,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        cin>>(v+1);
        sort(v+1,v+n+1);
        for(i=2;i<=m;++i)
            if(v[i]!=v[i-1])
                break;
        if(i==m+1)
        {
            if(v[n]==v[1])
            {
                for(i=1;i<=(n-1)/m+1;++i)
                    cout<<v[1];
            }
            else if (v[n]!=v[m+1])
            {
                cout<<v[1];
                for(i=m+1;i<=n;++i)
                    cout<<v[i];
            }
            else
            {
                cout<<v[1];
                for(i=1;i<=(n-1-m)/m+1;++i)
                    cout<<v[n];
            }
        }
        else
            cout<<v[m];
        cout<<'\n';
    }
    return 0;
}