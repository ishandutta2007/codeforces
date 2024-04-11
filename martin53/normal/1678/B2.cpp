#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;

    cin>>n;

    string inp;

    cin>>inp;

    int operations=0,segments=0;

    char prv='-';

    for(int i=0;i<n;i=i+2)
        if(inp[i]!=inp[i+1])operations++;
        else
        {
            if(prv!=inp[i])segments++;

            prv=inp[i];
        }

    if(segments==0)segments=1;

    cout<<operations<<" "<<segments<<"\n";
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