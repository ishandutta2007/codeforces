#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    string inp;

    cin>>inp;

    if(inp.back()!='B')return 0;

    int active=0;

    for(auto w:inp)
        if(w=='A')active++;
        else
        {
            if(active==0)return 0;
            active--;
        }

    return 1;
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

        if(solve())cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}