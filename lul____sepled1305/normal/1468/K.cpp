#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

set<pii> ob;

pii mov(pii cur, char c)
{
    if(c == 'L')
        cur.first--;
    if(c == 'R')
        cur.first++;
    if(c == 'U')
        cur.second++;
    if(c == 'D')
        cur.second--;

    return cur;
}

pii mov(pii cu, char c, pii ob)
{
    pii cur = cu;
    if(c == 'L')
        cur.first--;
    if(c == 'R')
        cur.first++;
    if(c == 'U')
        cur.second++;
    if(c == 'D')
        cur.second--;

    if(cur == ob)
        cur = cu;

    return cur;
}

void solve()
{
    string s;
    cin>>s;
    int n = s.size();
    pii cur = {0,0};
    for(auto it: s)
    {
        cur = mov(cur,it);
        ob.insert(cur);
    }
    bool pass = false;
    for(auto it: ob)
    {
        cur = {0,0};
        for(auto ss: s)
        {
            cur = mov(cur,ss,it);
        }
        if(cur.first == 0 && cur.second == 0)
        {
            pass = true;
            cout<<it.first<<' '<<it.second<<endl;
            break;
        }
    }
    if(!pass)
        cout<<0<<' '<<0<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}