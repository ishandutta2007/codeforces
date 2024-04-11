
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

#define answer(ans) {cout << ans << '\n'; return;}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    map<int, vector<pair<int, int>>> bad;
    map<int, int> freq;
    for (int x: a) freq[x]++;
    for (int x: a) bad[x] = vector<pair<int, int>>{{-1, -1}};
    for (int j = 0; j < m; ++j) {
        int u, v;
        cin >> u >> v;
        bad[u].emplace_back(freq[v], v);
        bad[v].emplace_back(freq[u], u);
    }
    for (auto &[u, v]: bad) sort(v.rbegin(), v.rend());
    map<int, vector<int>> valuesByFreq;
    for (auto[value, freq]: freq) {
        valuesByFreq[freq].push_back(value);
    }
    for (auto &[freq, values]: valuesByFreq) sort(values.rbegin(), values.rend());
    vector vvaluesByFreq(valuesByFreq.begin(), valuesByFreq.end());
    ll ans = 0;
    for (auto &[u, vec]: bad) {
        int cur = 0;
        int uFreq = freq[u];
        for (int j = vvaluesByFreq.size() - 1; j >= 0; --j) {
            int vFreq = vvaluesByFreq[j].first;
            for (int v: vvaluesByFreq[j].second) {
                if (v == vec[cur].second) {
                    cur++;
                } else if (v != u) {
                    ans = max(ans, (u + v) * 1LL * (uFreq + vFreq));
                    break;
                }
            }
        }
    }
    cout << ans << '\n';
}