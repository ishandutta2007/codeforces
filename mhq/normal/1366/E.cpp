#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;

const int mod = 998244353;

const int root = 646;

const int root_1 = 208611436;

const int root_pw = 1 << 20;

int mult(int a, int b) {
    return (1LL * a * b) % mod;
}

int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}

int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}

int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}

int n, m;
const int maxN = 2e5 + 10;
int a[maxN];
int b[maxN];
int suf[maxN];
int cnt[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    suf[n + 1] = 1e9 + 10;
    for (int i = n; i >= 1; i--) {
        suf[i] = min(suf[i + 1], a[i]);
    }
    if (suf[1] != b[1]) {
        cout << 0;
        return 0;
    }
    for (int i = 2; i <= n; i++) {
        int p = suf[i];
        int pos = lower_bound(b + 1, b + m + 1, p) - b;
        if (1 <= pos && pos <= m && b[pos] == p) cnt[pos]++;
    }
    int ans = 1;
    for (int i = 2; i <= m; i++) {
        ans = mult(ans, cnt[i]);
    }
    cout << ans;
    return 0;
}