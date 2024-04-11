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
const int MX = 5010;
const ll INF = 1e14;
int n, m;
vector<pair<int, ll> > vv;
ll dp[2 * MX];
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        vv.push_back(make_pair(x, -1));
    }
    for (int i = 0; i < m; ++i) {
        int p, c;
        cin >> p >> c;
        vv.push_back(make_pair(p, c));
    }
    for (int i = 0; i <= MX; ++i)
        dp[i] = 0;
    for (int i = MX + 1; i < 2 * MX; ++i)
        dp[i] = INF;
    sort(vv.begin(), vv.end());
    for (int i = 0; i < vv.size(); ++i) {
        int c = vv[i].second;
        if (c == -1) {
            for (int i = 0; i < 2 * MX - 1; ++i)
                dp[i] = dp[i + 1];
            dp[2 * MX - 1] = INF;
        }
        else {
            for (int i = 2 * MX - 1; i >= c; --i)
                dp[i] = dp[i - c];
            for (int i = c - 1; i >= 0; --i)
                dp[i] = dp[c];
        }
        if (i != vv.size() - 1) {
            ll d = vv[i + 1].first - vv[i].first;
            ll mn = INF;
            for (int i = 2 * MX - 1; i >= 0; --i) {
                dp[i] += abs(i - MX) * d;
                mn = min(mn, dp[i]);
                dp[i] = mn;
            }
        }
    }
    if (dp[MX] < INF)
        cout << dp[MX] << "\n";
    else
        cout << -1 << "\n";
    return 0;
}