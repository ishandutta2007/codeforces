#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int n, m;
const int maxM = 55;
ll f[maxM];
int pivot[maxM];
int sz = 0;
void add(ll x) {
    for (int i = 0; i < sz; i++) {
        if (x & (1LL << pivot[i])) {
            x ^= f[i];
        }
    }
    if (x == 0) return;
    int bt = -1;
    for (int j = 0; j < m; j++) {
        if (x & (1LL << j)) {
            bt = j;
            break;
        }
    }
    for (int j = 0; j < sz; j++) {
        if (f[j] & (1LL << bt)) {
            f[j] ^= x;
        }
    }
    pivot[sz] = bt;
    f[sz] = x;
    sz++;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) {
        return mult(a, pw(a, b - 1));
    }
    int res = pw(a, b / 2);
    return mult(res, res);
}
ll nf[maxM];
bool used[maxM];
unordered_map < ll, int > mp[maxM];
int ans[maxM];
void upd(int& a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        add(x);
    }
    for (int i = 0; i < sz; i++) {
        assert(!used[pivot[i]]);
        used[pivot[i]] = true;
    }
    vector < int > not_pivot;
    for (int i = 0; i < m; i++) {
        if (!used[i]) {
            not_pivot.emplace_back(i);
        }
    }
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < not_pivot.size(); j++) {
            if (f[i] & (1LL << not_pivot[j])) nf[i] |= (1LL << j);
        }
    }
    mp[0][0] = 1;
    for (int i = 0; i < sz; i++) {
        for (int sz = m - 1; sz >= 0; sz--) {
            for (auto& it : mp[sz]) {
                ll nx = it.first ^ nf[i];
                int& d = mp[sz + 1][nx];
                d = sum(d, it.second);
            }
        }
    }
    for (int i = 0; i <= sz; i++) {
        for (auto& it : mp[i]) {
            upd(ans[i + __builtin_popcountll(it.first)], it.second);
        }
    }
    int coef = pw(2, n - sz);
    for (int i = 0; i <= m; i++) cout << mult(coef, ans[i]) << " ";
    return 0;
}