#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2 * (int)1e5 + 100;
int a[2 * maxN];
ll ans = 0;
int nxt[maxN];
int mx[maxN];
bool good[2 * maxN];
int len[maxN];
int cnt[maxN];
int gc[maxN];
ll solve(int d) {
    for (int i = 0; i < d; i++) mx[i] = 0;
    for (int i = 0; i < n; i++) {
        cnt[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cnt[i] = cnt[i - 1];
        if (gc[i] == d) cnt[i]++;
    }
    for (int i = 0; i < n; i++) {
        mx[i % d] = max(mx[i % d], a[i]);
    }
    bool has_bad = false;
    for (int i = 0; i < n; i++) {
        if (mx[i % d] == a[i]) good[i] = true;
        else {
            good[i] = false;
            has_bad = true;
        }
    }
    if (!has_bad) {
        for (int i = 0; i < n; i++) len[i] = n;
    }
    else {
        for (int i = n; i < 2 * n; i++) {
            good[i] = good[i - n];
        }
        int l = -1;
        for (int i = 0; i < n; i++) {
            l = max(l, i - 1);
            while (good[l + 1]) l++;
            len[i] = l - i + 1;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int at_most = len[i] / d;
        ans += cnt[at_most * d];
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) gc[i] = __gcd(i, n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            ans += solve(i);
        }
    }
    cout << ans << '\n';
    return 0;
}