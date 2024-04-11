#include <bits/stdc++.h>
using namespace std;
int v[1003][1003];
int main()
{
    long long t,n,i,j,m,k=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=n;++j)
            {
                char c;
                cin>>c;
                if(c=='a')
                    v[i][j]=1;
                else
                    v[i][j]=2;
            }
        }
        if(m%2)
        {
            cout<<"YES\n";
            for(i=1;i<=m+1;++i)
            {
                cout<<i%2+1<<' ';
            }
            cout<<'\n';
            continue;
        }
        int ci=-1,cj=-1;
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=n;++j)
            {
                if(v[i][j]==v[j][i] && i!=j)
                {
                    ci=i,cj=j;
                }
            }
        }
        if(ci!=-1)
        {
            cout<<"YES\n";
            for(i=1;i<=m+1;++i)
            {
                if(i%2==0)
                    cout<<ci<<' ';
                else
                    cout<<cj<<' ';
            }
            cout<<'\n';
            continue;
        }
        if(n==2)
        {
            cout<<"NO\n";
            continue;
        }
        int a,b,c;
        if(v[1][2]!=v[1][3])
        {
            a=1;
            b=2;
            c=3;
        }
        else if(v[2][1]!=v[2][3])
        {
            a=2;
            b=1;
            c=3;
        }
        else if(v[3][1]!=v[3][2])
        {
            a=3;
            b=1;
            c=2;
        }
        cout<<"YES\n";
        if(m%4==0)
        for(i=1;i<=m+1;++i)
        {
            if(i%2==1)
                cout<<a<<' ';
            else
            {
                if(i<=m/2)
                    cout<<b<<' ';
                else
                    cout<<c<<' ';
            }
        }
        if(m%4==2)
        if(m%4)
        for(i=1;i<=m+1;++i)
        {
            if(i%2==0)
                cout<<a<<' ';
            else
            {
                if(i<=m/2)
                    cout<<b<<' ';
                else
                    cout<<c<<' ';
            }
        }
        cout<<'\n';
    }
    return 0;
}