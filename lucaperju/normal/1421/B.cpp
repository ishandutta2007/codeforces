#include <bits/stdc++.h>
using namespace std;
char v[203][203];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,s=0,k,n,m,mx=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=n;++j)
                cin>>v[i][j];
        }
        if(v[1][2]==v[2][1])
        {
            int cnt=0;
            if(v[n-1][n]==v[1][2])
                ++cnt;
            if(v[n][n-1]==v[1][2])
                ++cnt;
            cout<<cnt<<'\n';
            if(v[n-1][n]==v[1][2])
                cout<<n-1<<' '<<n<<'\n';
            if(v[n][n-1]==v[1][2])
                cout<<n<<' '<<n-1<<'\n';
        }
        else if(v[n-1][n]==v[n][n-1])
        {
            int cnt=0;
            if(v[n-1][n]==v[1][2])
                ++cnt;
            if(v[n][n-1]==v[2][1])
                ++cnt;
            cout<<cnt<<'\n';
            if(v[n-1][n]==v[1][2])
                cout<<1<<' '<<2<<'\n';
            if(v[n][n-1]==v[2][1])
                cout<<2<<' '<<1<<'\n';
        }
        else
        {
            cout<<2<<'\n';
            if(v[1][2]=='1')
                cout<<"1 2\n";
            if(v[2][1]=='1')
                cout<<"2 1\n";
            if(v[n][n-1]=='0')
                cout<<n<<' '<<n-1<<'\n';
            if(v[n-1][n]=='0')
                cout<<n-1<<' '<<n<<'\n';
        }
    }
    return 0;
}