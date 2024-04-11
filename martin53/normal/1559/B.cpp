#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n;

char inp[nmax];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)cin>>inp[i];

    inp[0]='?';
    inp[n+1]='?';

    for(int i=1;i<=n;i++)
        if(inp[i]=='?'&&inp[i-1]!='?')inp[i]='B'-inp[i-1]+'R';

    for(int i=n;i>=1;i--)
        if(inp[i]=='?'&&inp[i+1]!='?')inp[i]='B'-inp[i+1]+'R';

    for(int i=1;i<=n;i++)
        if(inp[i]=='?')
        {
            if(i%2==1)inp[i]='B';
            else inp[i]='R';
        }

    for(int i=1;i<=n;i++)cout<<inp[i];cout<<endl;
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