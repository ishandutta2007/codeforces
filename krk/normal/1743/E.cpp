#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 5005;
const ll Inf = 4000000000000000000ll;

ll p1, t1;
ll p2, t2;
ll h, s;
ll dp[Maxn];

int main()
{
    cin >> p1 >> t1;
    cin >> p2 >> t2;
    cin >> h >> s;
    if (t1 > t2) {
        swap(p1, p2);
        swap(t1, t2);
    }
    dp[0] = 0;
    for (int i = 1; i <= h; i++) {
        dp[i] = Inf;
        ll nxt1 = t1, nxt2 = t2;
        ll cur = i;
        ll lst;
        while (cur > 0)
            if (nxt1 <= nxt2) {
                // wait
                int ni = max(0ll, cur - (p1 + p2 - s));
                dp[i] = min(dp[i], dp[ni] + nxt2);
                // don't wait
                lst = nxt1;
                cur -= (p1 - s);
                nxt1 += t1;
            } else {
                // wait
                int ni = max(0ll, cur - (p1 + p2 - s));
                dp[i] = min(dp[i], dp[ni] + nxt1);
                // don't wait
                lst = nxt2;
                cur -= (p2 - s);
                nxt2 += t2;
            }
        dp[i] = min(dp[i], lst);
    }
    cout << dp[h] << endl;
    return 0;
}