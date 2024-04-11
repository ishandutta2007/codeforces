#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}
const int MX = 5100;

vector<int> eds[MX];
ll dp0[MX][MX];
ll dp1[MX][MX];

int n;
ll c[MX];
ll d[MX];
const ll INF = 1e9 + 100;

int dfs1(int v) {
    int sz = 0;
    for (int u: eds[v]) {
        int sz1 = dfs1(u);
        for (int j = sz + 1; j <= sz + sz1; ++j)
            dp0[v][j] = dp1[v][j] = INF;
        for (int i = sz; i >= 0; --i) {
            for (int j = 1; j <= sz1; ++j) {
                dp0[v][i + j] = min(dp0[v][i + j], dp0[v][i] + dp0[u][j]);
                dp1[v][i + j] = min(dp1[v][i + j], dp1[v][i] + dp1[u][j]);
            }
        }
        sz += sz1;
    }
    dp0[v][sz + 1] = dp1[v][sz + 1] = INF;
    for (int i = sz; i >= 0; --i)
        dp0[v][i + 1] = min(dp0[v][i + 1], dp0[v][i] + c[v]);
    for (int i = sz; i >= 0; --i)
        dp1[v][i + 1] = dp1[v][i] + c[v] - d[v];
    ++sz;
    for (int i = 0; i <= sz; ++i)
        dp1[v][i] = min(dp1[v][i], dp0[v][i]);
    return sz;
}

int main() {
    ll b;
    cin >> n >> b;
    for (int i = 0; i < n; ++i) {
        cin >> c[i] >> d[i];
        if (i) {
            int x;
            cin >> x;
            --x;
            eds[x].push_back(i);
        }
    }
    dfs1(0);
    int mx = 0;
    for (int i = 0; i <= n; ++i)
        if (dp1[0][i] <= b)
            mx = i;
    cout << mx << "\n";
    return 0;
}