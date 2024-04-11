#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,m;

char inp[nmax],help[nmax];

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>inp[i];

    inp[0]='0';
    inp[n+1]='0';

    int change=1;

    while(m&&change)
    {
        m--;
        change=0;

        for(int i=1;i<=n;i++)
            if(inp[i]=='1')help[i]=inp[i];
            else
            {
                if(min(inp[i-1],inp[i+1])=='0'&&max(inp[i-1],inp[i+1])=='1')help[i]='1';
                else help[i]=inp[i];
            }

        for(int i=1;i<=n;i++)
        {
            if(inp[i]!=help[i])change=1;
            inp[i]=help[i];
        }
    }

    for(int i=1;i<=n;i++)cout<<inp[i];
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;

    while(t)
    {
        t--;
        solve();
    }

    return 0;
}