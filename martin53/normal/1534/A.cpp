#include<bits/stdc++.h>
using namespace std;

const int nmax=1e3+42;

int n,m;

char inp[nmax][nmax];

int seen[2][2];

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)cin>>inp[i][j];

    memset(seen,0,sizeof(seen));

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(inp[i][j]=='R')seen[0][(i+j)%2]=1;
            else if(inp[i][j]=='W')seen[1][(i+j)%2]=1;

    char type[2]={'W','W'};

    if(seen[0][1]==0&&seen[1][0]==0)
    {
        type[0]='R';
        type[1]='W';
    }
    else if(seen[0][0]==0&&seen[1][1]==0)
    {
        type[0]='W';
        type[1]='R';
    }
    else
    {
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<type[(i+j)%2];
        }
        cout<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    int t;
    cin>>t;

    while(t)
    {
        t--;

        solve();
    }

    return 0;
}