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

void solve() {
    int n, m;
    cin >> n >> m;
    n *= 3;
    vector<int> mt(n + 1, -1);
    vector<int> matching;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (mt[u] == -1 && mt[v] == -1) {
            mt[u] = v;
            mt[v] = u;
            matching.push_back(i);
        }
    }
    if ((int) matching.size() >= n / 3) {
        cout << "Matching\n";
        for (int i = 0; i < n / 3; i++) {
            cout << matching[i] << "\n";
        }
        return;
    }
    cout << "IndSet\n";
    int cur = n / 3;
    for (int i = 1; i <= n && cur > 0; i++) {
        if (mt[i] != -1) continue;
        cur--;
        cout << i << "\n";
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}