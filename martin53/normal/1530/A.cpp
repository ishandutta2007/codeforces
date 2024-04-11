#include<bits/stdc++.h>
using namespace std;

int solve()
{
    string inp;

    cin>>inp;

    int ret=0;

    for(auto w:inp)
        ret=max(ret,w-'0');

    return ret;
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