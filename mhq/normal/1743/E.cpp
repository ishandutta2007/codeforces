#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int maxN = 5005;
ll dp[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int p1;
    ll t1;
    int p2;
    ll t2;
    ll h;
    int s;
    cin >> p1 >> t1 >> p2 >> t2 >> h >> s;
    dp[0] = 0;
    for (int i = 1; i <= h; i++) {
        dp[i] = 1e18;
        for (int iter = 0; iter < 2; iter++) {
            for (int A = 0; A <= i; A++) {
                //before
                if (A * (p1 - s) >= i) {
                    dp[i] = min(dp[i], A * t1);
                }
                ll at_most = (A * t1 + t1);
                if (t2 > at_most) continue;
                at_most -= t2;
                at_most /= t2;
                if (at_most > h) at_most = h;
                ll his_hp = i - A * (p1 - s) - at_most * (p2 - s);
                his_hp -= (p1 + p2 - s);
                his_hp = max(his_hp, 0LL);
                dp[i] = min(dp[i], dp[his_hp] + (A * t1 + t1));
            }
            swap(t1, t2);
            swap(p1, p2);
        }
    }
    cout << dp[h];

    return 0;
}