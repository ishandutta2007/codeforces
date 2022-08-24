#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, k, mod;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
const int maxN = 1e5 + 10;
int cnt[maxN];
void solve(int n, int k) {
    if (k <= 1 || n == 1) {
        cnt[n]++;
        return;
    }
    solve(n / 2, k - 1);
    solve((n + 1) / 2, k - 1);
}
int pref[maxN];
int go(int a, int b) {
    int t = mult(a, mult(b, (mod + 1) / 2));
    for (int r = 1; r <= a; r++) {
        int G = sub(pref[b + r], pref[r]);
        t = sub(t, G);
    }
    return t;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> k >> mod;
    solve(n, k);
    pref[1] = pw(1, mod - 2);
    for (int i = 2; i < maxN; i++) {
        pref[i] = sum(pref[i - 1], pw(i, mod - 2));
    }
    int ans = 0;
    vector<pair<int,int>> t;
    for (int i = 1; i <= n; i++) {
        if (cnt[i]) {
            t.emplace_back(i, cnt[i]);
        }
    }
    int inv2 = (mod + 1) / 2;
    int inv4 = mult(inv2, inv2);
    for (int x = 0; x < t.size(); x++) {
        for (int y = x; y < t.size(); y++) {
            if (x == y) {
                ans = sum(ans, mult(t[x].second, mult(t[x].first, mult(t[x].first - 1, inv4))));
                ans = sum(ans, mult(t[x].second, mult(t[x].second - 1, mult(inv2, go(t[x].first, t[x].first)))));
            }
            else {
                ans = sum(ans, mult(t[x].second, mult(t[y].second, go(t[x].first, t[y].first))));
            }
        }
    }
    cout << ans;
    return 0;
}