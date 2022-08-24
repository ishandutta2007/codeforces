#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = 998244353;
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
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    else {
        int res = pw(a, b / 2);
        return mult(res, res);
    }
}
int get_inv(int a) {
    return pw(a, mod - 2);
}
int n;
const int maxN = 2 * (int)1e5 + 10;
int f[maxN];
int inv2 = (mod + 1) / 2;
void upd(int v, int d) {
    while (v < maxN) {
        f[v] += d;
        v = (v | (v - 1)) + 1;
    }
}
int get_fenw(int r) {
    int ans = 0;
    while (r > 0) {
        ans += f[r];
        r = (r & (r - 1));
    }
    return ans;
}
int get_sum(int l, int r) {
    return get_fenw(r) - get_fenw(l - 1);
}
int p[maxN];
bool used[maxN];
int que_pref[maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector < pair < int, int > > by_pos;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        que_pref[i] = que_pref[i - 1];
        if (p[i] != -1) {
            by_pos.emplace_back(p[i], i);
            used[p[i]] = true;
        }
        else {
            que_pref[i]++;
        }
    }
    sort(by_pos.begin(), by_pos.end());
    int cur = 0;
    for (auto t : by_pos) {
        cur = sum(cur, get_sum(t.second + 1, n));
        upd(t.second, 1);
    }
    int all = que_pref[n];
    int add = mult(all, (all - 1));
    add = mult(add, mult(inv2, inv2));
    cur = sum(cur, add);
    if (all == 0) {
        cout << cur;
        return 0;
    }
    for (int i = 0; i < by_pos.size(); i++) {
        auto t = by_pos[i];
        int smaller = t.first - i - 1;
        int bigger = all - smaller;
        int places_before = que_pref[t.second];
        int places_after = all - places_before;
        cur = sum(cur, mult(places_before, mult(bigger, get_inv(smaller + bigger))));
        cur = sum(cur, mult(places_after, mult(smaller, get_inv(smaller + bigger))));
    }
    cout << cur;
    return 0;
}