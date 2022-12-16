#include<bits/stdc++.h>
using namespace std;

string solve()
{
    string inp;
    cin>>inp;

    sort(inp.begin(),inp.end());
    return inp;
}

int main()
{
    int t;
    cin>>t;

    while(t)
    {
        t--;

        cout<<solve()<<"\n";
    }

    return 0;
}