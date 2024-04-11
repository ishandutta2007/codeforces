#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(answer) { cout << (answer) << '\n'; return; }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

const int N = 70;

void solve() {
    int k;
    cin >> k;
    vector<ll> c(k);
    for (ll &x: c) cin >> x;
    vector<ll> f(N);
    f[1] = 1;
    for (int i = 2; i < N; ++i) f[i] = f[i - 1] + f[i - 2];
    vector<ll> pref(N + 1);
    for (int i = 0; i < N; ++i) pref[i + 1] = pref[i] + f[i];
    ll sum = accumulate(c.begin(), c.end(), 0LL);
    if (find(pref.begin(), pref.end(), sum) == f.end()) answer("NO")
    int i = find(pref.begin(), pref.end(), sum) - pref.begin() - 1;
    multiset<int> cc(c.begin(), c.end());
    int p = 0;
    while (i > 0) {
        int x = *cc.rbegin();
        cc.erase(cc.find(x));
        x -= f[i--];
        cc.insert(p);
        p = x;
    }
    if (p == 0 && all_of(cc.begin(), cc.end(), [](int x) { return x == 0; })) answer("YES")
    answer("NO")
}