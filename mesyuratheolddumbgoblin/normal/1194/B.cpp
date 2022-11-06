#include <sstream>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <map>
#include <set>

#define MOD 1000000007
#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef int ll;
using namespace std;
ll n, m, k, x, y, z, q;
ll r[500500], cc[500500];
vector<vector<ll> > b;
int main() {
    cin >> q;
    while (q--) {
        b.clear();
        cin >> n >> m;
        b.resize(n);
        for (int i = 0; i < n; i++) {
            b[i].resize(m);
        }
        for (int i = 0; i < n; i++) {
            r[i] = 0;
        }
        for (int j = 0; j < m; j++) {
            cc[j] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c;
                cin >> c;
                if (c == '*') {
                    b[i][j] = 1;
                    r[i]++;
                    cc[j]++;
                } else {
                    b[i][j] = 0;
                }
            }
        }
        ll ans = n + m - 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ll cur = r[i] + cc[j] - b[i][j];
                ans = min(ans, n + m - 1 - cur);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}