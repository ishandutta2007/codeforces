#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 3e5 + 5;

long long n, s[N];
long long ans = 0;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    long long kol = 0;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        int x = min(kol, s[i] / 2);
        ans += x;
        kol -= x;
        s[i] -= x * 2;
        ans += s[i] / 3;
        s[i] %= 3;
        kol += s[i];
    }
    cout << ans;
    return 0;
}