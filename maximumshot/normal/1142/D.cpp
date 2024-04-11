#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

using namespace std;

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;
typedef pair<long double, long double> pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<string> a;

    for (int i = 1; i <= 9; i++) {
        a.push_back(string(1, char('0' + i)));
    }

    vector<pii> g[11], gr[11];

    for (int i = 1; i <= 11; i++) {
        for (int j = 0; j < i % 11; j++) {
            string s = a[i - 1];
            s.push_back(j + '0');
            a.push_back(s);
            g[i % 11].push_back({(int)a.size() % 11, j});
            gr[(int)a.size() % 11].push_back({i % 11, j});
        }
    }

    string s;

    cin >> s;

    int n = (int)s.size();

    vector<int> dp(11, 1);

    ll res = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] != '0') {
            res += dp[s[i] - '0'];
        }
        if (!i) break;
        vector<int> nx(11, 1);
        for (int v = 0; v < 11; v++) {
            for (pii ed : gr[v]) {
                int to = ed.first;
                int sy = ed.second;
                if (sy == s[i] - '0') {
                    nx[to] = dp[v] + 1;
                }
            }
        }
        dp = nx;
    }

    cout << res << "\n";

    return 0;
}