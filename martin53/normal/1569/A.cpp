#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n;
char inp[nmax];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>inp[i];

    for(int i=1;i<n;i++)
        if(inp[i]!=inp[i+1])
        {
            cout<<i<<" "<<i+1<<endl;
            return;
        }

    cout<<-1<<" "<<-1<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int t;
    cin>>t;

    while(t)
    {
        t--;

        solve();
    }


    return 0;
}