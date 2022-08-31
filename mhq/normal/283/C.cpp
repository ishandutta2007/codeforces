#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
int n, q, t;
const int maxN = 1e5 + 10;
int a[maxN];
bool bad[maxN];
int prv[maxN];
bool marked[maxN];
const int mod = (int) 1e9 + 7;
int dp[maxN];

int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> q >> t;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= q; i++) {
        int b, c;
        cin >> b >> c;
        bad[b] = true;
        prv[c] = b;
    }
    vector<vector<int> > path;
    for (int i = 1; i <= n; i++) {
        if (!bad[i]) {
            int c = i;
            vector<int> v;
            while (c != 0) {
                marked[c] = true;
                v.emplace_back(a[c]);
                c = prv[c];
            }
            reverse(v.begin(), v.end());
            path.emplace_back(v);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!marked[i]) {
            cout << 0;
            return 0;
        }
    }
    dp[0] = 1;
    vector<int> gg;
    for (int i = 0; i < path.size(); i++) {
        int sm = 0;
        vector<int> v = path[i];
        for (int j = 0; j < v.size(); j++) {
            sm += v[j];
            if (j != v.size() - 1) {
                t -= sm;
                if (t < 0) {
                    cout << 0;
                    return 0;
                }
            }
            gg.emplace_back(sm);
        }
    }
    // a1, a2
    // a1, a1 + a2
    if (t < 0) {
        cout << 0;
        return 0;
    }
    assert(gg.size() == n);
    for (int v : gg) {
        for (int p = 0; p + v <= t; p++) {
            dp[p + v] = sum(dp[p + v], dp[p]);
        }
    }
    cout << dp[t];


    return 0;
}