#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
int n, m;
const int maxN = 5 * (int)1e5 + 100;
int deg[maxN];
pair < ull, ull > hsh[maxN];
mt19937_64 rnd(std::chrono::duration_cast<std::chrono::milliseconds>
                (std::chrono::system_clock::now().time_since_epoch()).count());
pair < ull, ull > we[maxN];
ll c[maxN];
ll gcd(ll a, ll b) {
    while (a > 0 && b > 0) {
        if (a < b) swap(a, b);
        a %= b;
    }
    return (a + b);
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        deg[i] = 0;
        we[i] = make_pair(rnd(), rnd());
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        hsh[i].first = hsh[i].second = 0;
    }
    vector < pair < pair < ull, ull >, ll > > by_hsh;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        hsh[b].first ^= we[a].first;
        hsh[b].second ^= we[a].second;
        deg[b]++;
    }
    ll d = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i]) {
            by_hsh.emplace_back(hsh[i], c[i]);
        }
    }
    sort(by_hsh.begin(), by_hsh.end());
    int i = 0;
    while (i < by_hsh.size()) {
        int j = i;
        ll sum = 0;
        while (j < by_hsh.size() && by_hsh[j].first == by_hsh[i].first) {
            sum += by_hsh[j].second;
            j++;
        }
        i = j;
        d = gcd(d, sum);
    }
    cout << d << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) solve();
    return 0;
}