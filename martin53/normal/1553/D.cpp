#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    string s,t;

    cin>>s>>t;

    int pos_s=s.size()-1,pos_t=t.size()-1;

    while(pos_s>=0&&pos_t>=0)
    {
        if(s[pos_s]==t[pos_t])pos_s--,pos_t--;
        else pos_s=pos_s-2;
    }

    return pos_t<0;
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