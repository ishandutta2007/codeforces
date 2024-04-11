#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e5 + 5;

int n, s;
vector<int> g[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    for (int u, v, i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int leafs = 0;

    for (int v = 1; v <= n; v++) {
        if ((int) g[v].size() == 1) {
            leafs++;
        }
    }

    cout.precision(20);
    cout << fixed;

    cout << ld(s) * ld(2) / ld(leafs);

    return 0;
}