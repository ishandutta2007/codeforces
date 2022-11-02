#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int a,b,i,ls;
    long long ans = 0;
    cin>>a>>b;
    for(i=1;(i*i < a+1) && i<=b;i++)
        ans += i-1, ls = i;
    for(i=1;i*i < a;i++)
        ans += max(min(b,a/i-1)-ls,0);
    cout<<ans<<endl;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}