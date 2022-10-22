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

int fast(int n, int m, vector<pii> a) {
    int res = 0;
    vector<int> in_row(n + 1, -1), in_col(n + 1, -1);
    for (int i = 0; i < m; i++) {
        auto [x, y] = a[i];
        if (x == y)
            continue;
        in_row[x] = i;
        in_col[y] = i;
        res++;
    }
    vector<vector<int>> g(m);
    for (int i = 0; i < m; i++) {
        auto [x, y] = a[i];
        if (x == y)
            continue;
        if (in_col[x] != -1)
            g[i].push_back(in_col[x]);
        if (in_row[y] != -1)
            g[i].push_back(in_row[y]);
    }
    vector<int> used(m);
    for (int i = 0; i < m; i++) {
        if (used[i])
            continue;
        queue<int> q;
        int V = 1, E = (int) g[i].size();
        q.push(i);
        used[i] = 1;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int to : g[v]) {
                if (used[to])
                    continue;
                V++;
                E += (int) g[to].size();
                used[to] = 1;
                q.push(to);
            }
        }
        E /= 2;
        if (E == V)
            res++;
    }
    return res;
}

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        vector<pii> a;

        cin >> n >> m;
        a.resize(m);
        for (int i = 0; i < m; i++)
            cin >> a[i].first >> a[i].second;

        int fs = fast(n, m, a);
        cout << fs << "\n";
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}