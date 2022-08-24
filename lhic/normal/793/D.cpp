#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>
#include <functional>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

#ifndef LOCAL
#define cerr _cer
struct _cert
{
    template <typename T> _cert& operator << (T) { return *this; }
};
_cert _cer;
#endif

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
		cerr << (*i) << " ";
    }
    cerr << "\n";
}
const int INF = 1e6;

int n, k;
int m;
vector<pair<int, int> > eds[100];
int dp[85][85][85][2];

int main() {
    cin >> n >> k;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        eds[a].push_back(make_pair(b, c));
    }
    for (int i = 1; i < k; ++i) {
        for (int l = n; l >= 0; --l) {
            for (int r = l + 1; r <= n + 1; ++r) {
                dp[i][l][r][0] = INF;
                for (auto e: eds[l]) {
                    int u = e.first;
                    if (u > l && u < r) {
                        dp[i][l][r][0] = min(dp[i][l][r][0], dp[i - 1][l][u][1] + e.second);
                        dp[i][l][r][0] = min(dp[i][l][r][0], dp[i - 1][u][r][0] + e.second);
                    }
                }
                dp[i][l][r][1] = INF;
                for (auto e: eds[r]) {
                    int u = e.first;
                    if (u > l && u < r) {
                        dp[i][l][r][1] = min(dp[i][l][r][1], dp[i - 1][l][u][1] + e.second);
                        dp[i][l][r][1] = min(dp[i][l][r][1], dp[i - 1][u][r][0] + e.second);
                    }
                }
            }
        }
    }
    int ans = INF;
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, dp[k - 1][0][i][1]);
        ans = min(ans, dp[k - 1][i][n + 1][0]);
    }
    if (ans == INF) {
        cout << -1 << "\n";
    }
    else {
        cout << ans << "\n";
    }
	return 0;
}