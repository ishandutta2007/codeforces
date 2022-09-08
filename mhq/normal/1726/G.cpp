#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;

const int mod = 998244353;
const int maxN = 6e5 + 10;
int fact[maxN], invfact[maxN], inv[maxN];
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int cnk(int n, int k) {
    if (n < k || k < 0) return 0;
    return mult(fact[n], mult(invfact[k], invfact[n - k]));
}
int a[maxN];
int b[maxN];
int cnt[2][maxN];
int delta[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    fact[0] = invfact[0] = fact[1] = invfact[1] = inv[1] = 1;
    for (int i = 2; i <= 2 * n; i++) {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult(inv[mod % i], mod - mod / i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int mn = *min_element(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] -= mn;
        a[i] += 1;
    }
    mn = *min_element(a + 1, a + n + 1);
    assert(mn == 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        cnt[b[i]][a[i]]++;
    }
    int mx = *max_element(a + 1, a + n + 1);
    if (mn == mx) {
        cout << fact[n];
        return 0;
    }
    int pos = min_element(a + 1, a + n + 1) - a;
    if (b[pos] != 1) {
        cout << 0;
        return 0;
    }
    if (mx > n) {
        cout << 0;
        return 0;
    }
    int ans = 1;
    int mn_zero = n;
    for (int i = 1; i <= n; i++) {
        if (b[i] == 0) {
            mn_zero = min(mn_zero, a[i]);
        }
    }
    if (n - mn_zero >= mn_zero) {
        cout << 0;
        return 0;
    }
    ans = mult(ans, cnk(n, cnt[1][n]));
    ans = mult(ans, fact[cnt[1][n]]);
    ans = mult(ans, fact[cnt[0][n]]);
    for (int p = mn_zero; p < n; p++) {
        ans = mult(ans, fact[cnt[0][p]]);
        if (cnt[1][n - p] != 1) {
            cout << 0;
            return 0;
        }
        delta[p] += cnt[0][p];
    }
    int s = n - mn_zero + 1;
    for (int i = 1; i <= n; i++) {
        delta[i] += delta[i - 1];
    }
    for (int i = 1; i < n; i++) {
        if (cnt[1][i] > 1) {
            cout << 0;
            return 0;
        }
    }
    vector<int> vals;
    int add = (n - mn_zero);
    int cur = 0;
    for (int x = s; x < n; x++) {
        if (cnt[1][x]) {
            assert(cnt[1][x] == 1);
            //x + (n - 1 - add) - = n
            int smaller_suf = (x + n - 1 - add - delta[x]) - n;
            if (smaller_suf < 0 || smaller_suf > cur) {
                cout << 0;
                return 0;
            }
            cur++;
        }
    }
    cout << ans;



    return 0;
}