#include<bits/stdc++.h>
using namespace std;

string solve()
{
    int n;
    string inp;

    cin>>n>>inp;

    string in="";
    in.push_back(inp[0]);

    set<char> seen={};

    for(auto w:inp)
    {
        seen.insert(w);

        if(in.back()!=w)in.push_back(w);
    }

    if(in.size()==seen.size())return "YES";
    return "NO";
}

int main()
{
    int t;
    cin>>t;

    while(t)
    {
        cout<<solve()<<endl;
        t--;
    }

    return 0;
}