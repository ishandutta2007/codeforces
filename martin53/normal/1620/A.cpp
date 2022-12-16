#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    string inp;
    cin>>inp;

    int cnt=0;
    for(auto w:inp)
        if(w=='N')cnt++;

    return cnt!=1;
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