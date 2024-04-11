
#include<bits/stdc++.h>
using namespace std;
inline void solve()
{
    int a,b;
    cin>>a>>b;
    cout<<(__gcd(a,b)==1?"Finite":"Infinite")<<endl;
    return;
}
signed main()
{
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}