#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

#define rep(i,N) for(int i=0;i<(int)N;i++)
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

int main() {
    int n, m;
    cin >> n >> m;
    V<int> a(n);
    V<ll> b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    VV<ll> g(m);
    for (int i = 0; i < n; i++) g[a[i]-1].push_back(b[i]);
    int cnt = 0;
    V<ll> z;
    for (int i = 0; i < m; i++) {
        sort(g[i].begin(), g[i].end());
        if (g[i].empty()) continue;
        cnt++;
        g[i].pop_back();
        for (ll d: g[i]) z.push_back(d);
    }
    sort(z.begin(), z.end());
    ll ans = 0;
    for (int i = 0; i < m - cnt; i++) {
        ans += z[i];
    }
    cout << ans << endl;
    return 0;
}