#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 3e5 + 5;

int n, m;
ll f[N];

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int d, u, v, i = 0; i < m; i++) {
        cin >> u >> v >> d;
        f[u] += d;
        f[v] -= d;
    }

    vector<int> pos, neg;
    for (int v = 1; v <= n; v++) {
        if (f[v] > 0) {
            pos.push_back(v);
        } else if (f[v] < 0) {
            neg.push_back(v);
        }
    }

    vector<tuple<int, int, ll>> edges;

    for (int i = 0, j = 0; i < (int) pos.size() && j < (int) neg.size(); ) {
        int v_pos = pos[i];
        int v_neg = neg[j];
        ll w = min(f[v_pos], -f[v_neg]);
        f[v_pos] -= w;
        f[v_neg] += w;
        edges.emplace_back(v_pos, v_neg, w);
        if (f[v_pos] == 0)
            i++;
        if (f[v_neg] == 0)
            j++;
    }

    cout << (int) edges.size() << "\n";

    for (auto item : edges) {
        int u, v;
        ll w;
        tie(u, v, w) = item;
        cout << u << " " << v << " " << w << "\n";
    }

    return 0;
}