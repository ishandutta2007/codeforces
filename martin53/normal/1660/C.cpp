#include<bits/stdc++.h>
using namespace std;

int solve()
{
    string inp;

    cin>>inp;

    int outp=0;

    set<char> active={};

    for(auto w:inp)
        if(active.count(w))
        {
            outp+=2;
            active={};
        }
        else active.insert(w);

    return inp.size()-outp;
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

        cout<<solve()<<"\n";
    }

    return 0;
}