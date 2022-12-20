#include<bits/stdc++.h>
using namespace std;

set<string> seen={"0","1","01","10"};

bool solve()
{
    int n;

    cin>>n;

    string inp;

    cin>>inp;

    return seen.count(inp);
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