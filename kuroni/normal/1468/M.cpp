#include <bits/stdc++.h>
using namespace std;

const int N = 200005, B = 100;

int n, k, t, sz, chk[N];
vector<int> tot, ve[N], con[N];
vector<pair<int, int>> sim;

int index(int v) {
    return lower_bound(tot.begin(), tot.end(), v) - tot.begin();
}

void solve() {
    cin >> n;
    tot.clear();
    for (int i = 1; i <= n; i++) {
        cin >> k;
        ve[i] = vector<int>(k);
        for (int& v : ve[i]) {
            cin >> v;
            tot.push_back(v);
        }
        sort(ve[i].begin(), ve[i].end());
    }

    sort(tot.begin(), tot.end());
    tot.erase(unique(tot.begin(), tot.end()), tot.end());
    sz = tot.size();
    for (int i = 0; i < sz; i++) {
        con[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        for (int& v : ve[i]) {
            v = index(v);
            con[v].push_back(i);
        }
    }
    for (int i = 0; i < sz; i++) {
        if (con[i].size() >= B) {
            fill(chk, chk + sz, 0);
            for (int se : con[i]) {
                for (int v : ve[se]) {
                    if (v == i) {
                        continue;
                    }
                    if (chk[v] == 0) {
                        chk[v] = se;
                    } else {
                        cout << chk[v] << " " << se << '\n';
                        return;
                    }
                }
            }
        }
    }
    sim.clear();
    for (int i = 0; i < sz; i++) {
        if (con[i].size() < B) {
            for (int j = 0; j < con[i].size(); j++) {
                for (int k = j + 1; k < con[i].size(); k++) {
                    sim.push_back({con[i][j], con[i][k]});
                }
            }
        }
    }
    sort(sim.begin(), sim.end());
    for (int i = 1; i < sim.size(); i++) {
        if (sim[i] == sim[i - 1]) {
            cout << sim[i].first << " " << sim[i].second << '\n';
            return;
        }
    }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
}