#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n, m;
const int maxN = 55;
int a[maxN], b[maxN];
int s = 0;
int f[maxN];
const int BUBEN = (int)1e4;
int dp[BUBEN + 10];
int ndp[BUBEN + 10];
const int INF = (int)1e9;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(239);
    cin >> n >> m;
    vector < int > all;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        s += b[i];
        f[i] = a[i] - b[i];
    }
    s *= m;
    for (int i = 0; i <= BUBEN; i++) {
        dp[i] = INF;
        ndp[i] = INF;
    }
    dp[0] = 0;
    vector < int > vals;
    vals.push_back(dp[0]);
    for (int i = 0; i < BUBEN; i++) {
        for (int bal = 0; bal <= i; bal++) {
            ndp[bal + 1] = min(ndp[bal + 1], dp[bal] + f[i % n]);
            if (bal >= 1) ndp[bal - 1] = min(ndp[bal - 1], dp[bal]);
        }
        for (int bal = 0; bal <= i + 1; bal++) {
            dp[bal] = ndp[bal];
            ndp[bal] = INF;
        }
        // dp[4] =
        if (((i + 1) % (2 * n)) == 0) {
            vals.push_back(dp[0]);
        }
    }
    if (vals.size() > (m / 2)) {
        cout << vals[m / 2] + s;
    }
    else {
        // 2 * m < BUBEN
        int lim = vals.size() - 1;
        int d = vals[lim] - vals[lim - 1];
        int steps = m / 2 - lim;
        // m = 2 * lim - steps = 0
        cout << vals[lim] + 1LL * d * steps + s;
    }
    return 0;
}