#include <bits/stdc++.h>
using namespace std;
int v[200005];
int main()
{
    int t,i,j,n,m,cnt=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        for(i=2;i<=n;++i)
            if(v[i]!=v[i-1])
                break;
        if(i==n+1)
        {
            cout<<"1\n";
            for(i=1;i<=n;++i)
            {
                cout<<1<<' ';
            }
            cout<<'\n';
            continue;
        }
        v[n+1]=v[1];
        for(i=1;i<=n;++i)
        {
            if(v[i]==v[i+1])
                break;
        }
        if(i==n+1 && n%2==1)
        {
            cout<<"3\n";
            for(i=1;i<n;++i)
                cout<<i%2+1<<' ';
            cout<<3<<'\n';
            continue;
        }
        else
        {
            cout<<2<<'\n';
            if(n%2==0)
            {
                for(i=1;i<=n;++i)
                    cout<<i%2+1<<' ';
                cout<<'\n';
                continue;
            }
            else
            {
                for(j=1;j<=n;++j)
                {
                    if(j<=i)
                        cout<<j%2+1<<' ';
                    else
                        cout<<2-j%2<<' ';
                }
                cout<<'\n';
                continue;
            }
        }
    }
    return 0;
}