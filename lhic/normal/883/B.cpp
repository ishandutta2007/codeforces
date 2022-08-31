#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;

const int MAXN = 200001;

int r[MAXN];

set <pair<int, int>, greater<pair<int,int>>> cands;
int d[MAXN];
int u[MAXN];

vector<int> e[MAXN];
vector<int> erev[MAXN];
vector<int> vals[MAXN];
set<int> rs[MAXN];

void nein() {
    cout << "-1\n" << "\n";
    exit(0);
}

void tl(bool expr = false) {
    if (!expr) {
        for (;;);
    }
}

int main() {
#ifdef PAUNSVOKNO
    freopen("in", "r", stdin); cout.tie(nullptr);
    cout.setf(ios::fixed); cout.precision(20); ios_base::sync_with_stdio(false);
#endif
    int n, k, m;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
        if (r[i]) {
            u[i] = d[i] = MAXN;
            vals[r[i]].push_back(i);
        }
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        erev[b].emplace_back(a);
        d[a]++;
        u[b]++;
    }

    for (int i = 1; i <= n; ++i) {
        if (!d[i]) {
            vals[1].push_back(i);
            r[i] = 1;
        }
    }

    for (int i = 1; i <= k; ++i) {
        for (int v: vals[i]) {
            for (int u: erev[v]) {
                if (r[u] && r[u] <= r[v]) {
                    nein();
                }

                if (--d[u] == 0) {
                    vals[i + 1].push_back(u);
                    r[u] = i + 1;
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (!r[i] || r[i] > k) {
            nein();
        }

        rs[r[i]].insert(i);

        if (u[i] == 0) {
            cands.emplace(r[i], i);
        }
    }

    for (int i = k; i >= 1; --i) {
        if (rs[i].empty()) {
            for (;;cands.erase(cands.begin())) {
                if (cands.empty()) {
                    nein();
                }

                if (cands.begin()->first < i) {
                    break;
                }
            }

            int ver = cands.begin()->second;
            cands.erase(cands.begin());

            rs[r[ver]].erase(ver);
            rs[r[ver] = i].insert(ver);
        }

        tl(!rs[i].empty());

        for (int v: rs[i]) {
            tl(r[v] == i);
            for (int uv: e[v]) {
                if (--u[uv] == 0) {
                    cands.emplace(r[uv], uv);
                }
            }
        }
    }
    set<int> used;
    for (int i = 1; i <= n; i++) {
        used.insert(r[i]);
    }

    assert(used.size() == k && *used.begin() == 1 && *used.rbegin() == k);

    for (int i = 1; i <= n; ++i) {
        cout << r[i] << " ";
    }

    cout << "\n";
}