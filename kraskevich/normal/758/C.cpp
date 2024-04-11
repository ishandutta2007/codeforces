#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); 
    int n, m, x, y;
    ll k;
    cin >> n >> m >> k >> x >> y;
    ll cycle = 2 * n * m - 2 * m;
    if (n == 1)
        cycle = m;
    ll add = k / cycle;
    k %= cycle;
    vector<vector<ll>> cnt(n, vector<ll>(m));
    vector<vector<ll>> perCyc(n, vector<ll>(m));
    int d_i = 1;
    int i = 0;
    int j = 0;
    for (int rep = 0; rep < cycle; rep++) {
        perCyc[i][j]++;
        j++;
        //cerr << i << " " << j << endl;
        if (j == m) {
            j = 0;
            if (n == 1)
                continue;
            if (i + d_i == n) 
                d_i = -1;
            else if (i + d_i == -1)
                d_i = 1;
            i += d_i;
        }
    }
    d_i = 1;
    i = 0;
    j = 0;
    for (int rep = 0; rep < k; rep++) {
        cnt[i][j]++;
        j++;
        //cerr << i << " " << j << endl;
        if (j == m) {
            j = 0;
            if (n == 1)
                continue;
            if (i + d_i == n) 
                d_i = -1;
            else if (i + d_i == -1)
                d_i = 1;
            i += d_i;
        }
    }
    ll mx = 0;
    ll mn = ll(1e18);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            mx = max(mx, perCyc[i][j] * add + cnt[i][j]);
            mn = min(mn, perCyc[i][j] * add + cnt[i][j]);        
        } 
    cout << mx << " " << mn << " " << perCyc[x - 1][y - 1] * add + cnt[x - 1][y - 1] << endl;
}