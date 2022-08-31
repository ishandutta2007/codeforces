#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 1e6 + 10;
ll a[maxN];
ll x;
ll pref[maxN];
ll at_most[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= (n + 1) / 2; i++) {
        cin >> a[i];
    }
    cin >> x;
    for (int i = (n + 1) / 2 + 1; i <= n; i++) {
        a[i] = x;
    }
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }
    if (x >= 0) {
        if (pref[n] > 0) {
            cout << n << '\n';
        }
        else {
            cout << -1 << '\n';
        }
        return 0;
    }
    int half = (n + 1) / 2;
    for (int st = 1; st <= half; st++) {
        ll cur_sum = pref[half] - pref[st - 1];
        if (cur_sum <= 0) {
            at_most[st] = 0;
            continue;
        }
        at_most[st] = min((ll)n - st + 1, (cur_sum - 1) / abs(x) + half - st + 1);
    }
    ll mn = 1e9;
    for (int i = 1; i <= half; i++) {
        mn = min(mn, at_most[i]);
        if (mn >= n - i + 1) {
            cout << n - i + 1 << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}