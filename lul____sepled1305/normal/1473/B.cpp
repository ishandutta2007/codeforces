#include<bits/stdc++.h>
using namespace std;
 
void solve()
{
    string s,t,S,T;
    cin>>s>>t;
    int lm = lcm(s.size(),t.size());
    for(int i = 0; i<(lm/s.size());i++)
        S.append(s);
    for(int i = 0; i<(lm/t.size());i++)
        T.append(t);
    if(T != S)
        cout<<"-1\n";
    else
        cout<<S<<'\n';
}
 
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}