#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n;

string inp;

void solve()
{
    cin>>inp;

    n=inp.size();

    int ret=0;

    for(int i=1;i<n;i++)
        if(inp[i]==inp[i-1]||(i>=2&&inp[i]==inp[i-2]))
        {
            inp[i]='.';
            ret++;
        }

    cout<<ret<<endl;
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