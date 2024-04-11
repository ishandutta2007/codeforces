#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
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
int n, q;
const int inv100 = pw(100, mod - 2);
const int maxN = 2 * (int)1e5 + 100;
int pp[maxN];
int val[maxN];
int pref_mult[maxN];
int get_prod(int u, int v) {
    // u <= v
    return mult(pref_mult[v], pw(pref_mult[u - 1], mod - 2));
}
set < int > s;
int total_sum;
int get(int u, int v) {
    // u <= v
    int has = val[v];
    return sub(has, mult(val[u - 1], get_prod(u, v)));
}
void add(int v) {
    auto it = s.lower_bound(v);
    int after = *it;
    int before = *(prev(it));
    total_sum = sub(total_sum, get(before, after - 1));
    total_sum = sum(total_sum, get(before, v - 1));
    total_sum = sum(total_sum, get(v, after - 1));
    s.insert(v);
}
void del(int v) {
    auto it = s.lower_bound(v);
    int after = *next(it);
    int before = *prev(it);
    total_sum = sub(total_sum, get(before, v - 1));
    total_sum = sub(total_sum, get(v, after - 1));
    total_sum = sum(total_sum, get(before, after - 1));
    s.erase(it);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pp[i] = pw(mult(x, inv100), mod - 2);
    }
    val[0] = 0;
    for (int i = 1; i <= n; i++) {
        val[i] = sum(pp[i], mult(val[i - 1], pp[i]));
    }
    pref_mult[0] = 1;
    for (int i = 1; i <= n; i++) {
        pref_mult[i] = mult(pref_mult[i - 1], pp[i]);
    }
    s.insert(1);
    s.insert(n + 1);
    total_sum = val[n];
    while (q--) {
        int u;
        cin >> u;
        if (s.find(u) != s.end()) del(u);
        else add(u);
        cout << total_sum << '\n';
    }
    return 0;
}