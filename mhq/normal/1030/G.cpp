#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int n;
const int maxN = 2 * (int)1e6 + 100;
int lp[maxN];
int cnt_hs[maxN];
int coef[maxN];
int ans = 1;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
vector < int > gg;
bool add(int x) {
    bool f = false;
    int cp = x;
    while (x > 1) {
        int p = lp[x];
        int ex = 0;
        while (x % p == 0) {
            x /= p;
            ex++;
        }
        if (ex > coef[p]) {
            f = true;
            for (int j = coef[p]; j < ex; j++) ans = mult(ans, p);
            coef[p] = ex;
        }
    }
    if (f) gg.push_back(cp);
    return f;
}
int cnt_val[maxN];
void add2(int x) {
    while (x > 1) {
        int p = lp[x];
        int ex = 0;
        while (x % p == 0) {
            x /= p;
            ex++;
        }
        assert(ex <= coef[p]);
        if (ex == coef[p]) cnt_val[p]++;
    }
}
bool can_del(int x) {
    bool f = true;
    while (x > 1) {
        int p = lp[x];
        int ex = 0;
        while (x % p == 0) {
            x /= p;
            ex++;
        }
        if (ex == coef[p] && cnt_val[p] == 1) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 2; i < maxN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            for (int j = 2 * i; j < maxN; j += i) lp[j] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt_hs[x]++;
    }
    bool go = false;
    for (int i = maxN - 1; i >= 2; i--) {
        if (lp[i] != i) continue;
        if (cnt_hs[i] == 0) continue;
        if (add(i)) {
            cnt_hs[i]--;
        }
        if (cnt_hs[i] > 0) {
            if (add(i - 1)) {
                cnt_hs[i]--;
            }
        }
        if (cnt_hs[i] > 0) go = true;
    }
    if (go) {
        ans = (ans + 1) % mod;
        cout << ans;
    }
    else {
        for (int v : gg) {
            add2(v);
        }
        for (int v : gg) {
            if (can_del(v)) {
                ans = (ans + 1) % mod;
                cout << ans;
                return 0;
            }
        }
        cout << ans;
    }
    return 0;
}