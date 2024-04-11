#include <bits/stdc++.h>
using namespace std;
int fact5(int x)
{
    int ans = 0;
    while (x % 5 == 0) {x /= 5; ans++;}
    return ans;
}
main()
{
    int ans = 0, n, t = 0;
    cin >> n;
    while (t < n) {ans++; t += 1 + fact5(ans);}
    if (t == n) cout<<5<<'\n'<<5*ans<<" "<<5*ans+1<<" "<<5*ans+2<<" "<<5*ans+3<<" "<<5*ans+4; else cout<<0;
}