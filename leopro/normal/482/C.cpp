#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(out) { cout << (out) << '\n'; return; }
#define answerExit(out) { cout << (out) << '\n'; exit(0); }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

using ull = unsigned int;

mt19937 rng(0);
using vb = ll;
const int sz = 1 << 10;
vector<ull> aa[sz];
int used[1 << 20];

void solve() {
    for (auto &v: aa) v.reserve(100);
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int l = a[0].size();
    vector<vb> guessed(1 << l, (1LL << n) - 1);
    vector<ull> hash(l);
    for (auto &v: hash) v = rng();
    vector<ull> sub(n);
    vector<bool> vis(1 << l);
    auto fill = [&](auto fill, int mask) -> void {
        if (vis[mask]) return;
        vis[mask] = true;
        for (auto x: sub) aa[x & (sz - 1)].push_back(x);
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int x: aa[sub[i] & (sz - 1)]) {
                if (x == sub[i] && ++cnt == 2) {
                    guessed[mask] &= ~(1LL << i);
                    break;
                }
            }
        }
        for (auto x: sub) aa[x & (sz - 1)].clear();
        for (int i = 0; i < l; ++i) {
            if (mask & (1 << i) || vis[mask | (1 << i)]) continue;
            for (int j = 0; j < n; ++j) {
                sub[j] += a[j][i] * hash[i];
            }
            fill(fill, mask | (1 << i));
            for (int j = 0; j < n; ++j) {
                sub[j] -= a[j][i] * hash[i];
            }
        }
    };
    fill(fill, 0);
    vector<double> prob(1 << l);
    auto go = [&](auto go, int mask) -> double {
        if (used[mask]) return prob[mask];
        int here = n - __builtin_popcountll(guessed[mask]);
        if (here == 0) return 0;
        double ans = 0;
        int cnt = 0;
        for (int bit = 0; bit < l; ++bit) {
            if (mask & (1 << bit)) continue;
            ans += go(go, mask | (1 << bit));
            cnt++;
        }
        used[mask] = true;
        return prob[mask] = here * 1.0 / n + ans / cnt;
    };
    double ans = go(go, 0);
    cout << setprecision(10);
    cout << ans << '\n';
}