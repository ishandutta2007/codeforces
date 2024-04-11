#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

void solve()
{
    string inp;
    cin>>inp;

    string ret="";

    for(auto k:inp)
    {
        if(k=='B'&&ret.size()>=1)ret.pop_back();
        else ret.push_back(k);
    }

    cout<<ret.size()<<"\n";
}

int main()
{
    int t;
    scanf("%i",&t);
    while(t)
    {
        solve();
        t--;
    }
    return 0;
}