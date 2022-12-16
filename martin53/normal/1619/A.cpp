#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    string inp;
    cin>>inp;

    int n=inp.size();

    if(n%2)return 0;

    for(int i=0;i<n/2;i++)
        if(inp[i]!=inp[i+n/2])return 0;

    return 1;
}

int main()
{
    int t;
    cin>>t;

    while(t)
    {
        t--;

        if(solve())cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}