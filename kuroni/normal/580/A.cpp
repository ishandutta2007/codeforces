#include <bits/stdc++.h>
using namespace std;
main()
{
    ios_base::sync_with_stdio(0);
    int ans = 1, now, prev = 0, tmp = 0, n;
    cin>>n;
    for (int i = 0; i < n; i++) {cin>>now; tmp = (now >= prev)?tmp+1:1; ans = max(ans,tmp); prev = now;}
    cout<<ans;
}