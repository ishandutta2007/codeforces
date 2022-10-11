#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m, u, v, k, ce = 0, co = 0;
char t, c;
map<pair<int, int>, char> ma;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> t;
        if (t == '+') {
            cin >> u >> v >> c;
            if (ma.count({v, u})) {
                ce++;
                co += (ma[{v, u}] == c);
            }
            ma[{u, v}] = c;
        } else if (t == '-') {
            cin >> u >> v;
            if (ma.count({v, u})) {
                ce--;
                co -= (ma[{v, u}] == ma[{u, v}]);
            }
            ma.erase({u, v});
        } else {
            cin >> k;
            cout << ((k % 2 == 1 ? ce : co) == 0 ? "NO\n" : "YES\n");
        }
    }
}