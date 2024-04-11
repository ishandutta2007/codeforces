#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n;
char inp[nmax];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>inp[i];

    int SZ=(n+1)/2;

    for(int i=SZ+1;i<=n;i++)
        if(inp[i]=='0')
        {
            cout<<1<<" "<<i<<" "<<1<<" "<<i-1<<endl;
            return;
        }

    for(int i=1;i<=n-SZ;i++)
        if(inp[i]=='0')
        {
            cout<<i<<" "<<n<<" "<<i+1<<" "<<n<<endl;
            return;
        }

    if(n%2==0)cout<<1<<" "<<SZ<<" "<<SZ+1<<" "<<n<<endl;
    else cout<<1<<" "<<SZ<<" "<<n-SZ+1<<" "<<n<<endl;
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