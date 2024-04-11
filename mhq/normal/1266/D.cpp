#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = (int)1e5 + 100;
ll in[maxN], out[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        in[v] += d;
        out[u] += d;
    }
    ll ans = 0;
    vector < int > fr, to;
    for (int i = 1; i <= n; i++) {
        ll d = min(in[i], out[i]);
        in[i] -= d;
        out[i] -= d;
        if (in[i] > 0) to.emplace_back(i);
        else if (out[i] > 0) fr.emplace_back(i);
    }
    vector < pair < pair < int, int >, ll > >  as;
    while (fr.size() > 0 || to.size() > 0) {
        assert(!fr.empty() && !to.empty());
        int c0 = fr.back();
        int c1 = to.back();
        fr.pop_back();
        to.pop_back();
        ll d = min(out[c0], in[c1]);
        out[c0] -= d;
        in[c1] -= d;
        as.emplace_back(make_pair(c0, c1), d);
        if (out[c0]) fr.push_back(c0);
        if (in[c1]) to.push_back(c1);
    }
    cout << as.size() << '\n';
    for (auto it : as) {
        cout << it.first.first << " " << it.first.second << " " << it.second << '\n';
    }
    return 0;
}