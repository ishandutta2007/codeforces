#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define int long long
int n, m, d;
ll ans = 0;
const int maxN = 2 * (int)1e5 + 100;
int x[maxN], p[maxN];
const int LOG = 20;
pair < int, int > up[LOG][maxN];
int lg[maxN];
int get(int l, int r) {
    int id = lg[r - l +  1];
    return min(up[id][l], up[id][r - (1 << id) + 1]).second;
}
ll solve(int from, int to, ll have) {
    //cout << from << " " << to << " " << have << " " << x[from] << " " << x[to] << endl;
    if (x[to] - x[from] <= n) {
        ll add = max(0LL, x[to] - x[from] - have);
        return add * p[from];
    }
    if (from + 1 == to) {
        cout << -1;
        exit(0);
    }
    int where = get(from + 1, to - 1);
   // ll val1 = solve(from, where, have);
    if (x[where] - x[from] <= n) {
        int need_have;
        if (x[to] - x[where] >= n) need_have = n;
        else need_have = x[to] - x[where];
        need_have = min(n - (x[where] - x[from]), need_have);
        ll need_to_add = max(0LL, need_have + x[where] - x[from] - have);
        return need_to_add * p[from] + solve(where, to, need_have);
      //  int will_have = min(n, have + (x[w]))
    }
    else {
        //cout << "ggboys " << endl;
        return solve(from, where, have) + solve(where, to, 0);
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> d >> n >> m;
    x[0] = 0;
    p[0] = 0;
    x[m + 1] = d;
    p[m + 1] = 0;
    for (int i = 1; i <= m; i++) {
        cin >> x[i] >> p[i];
    }
    vector < pair < int, int > > all;
    for (int i = 0; i <= m + 1; i++) all.emplace_back(x[i], p[i]);
    sort(all.begin(), all.end());
    for (int i = 0; i <= m + 1; i++) {
        x[i] = all[i].first;
        p[i] = all[i].second;
    }
    for (int i = 0; i <= m + 1; i++) {
        up[0][i] = make_pair(p[i], i);
    }
    for (int i = 0; i + 1 < LOG; i++) {
        for (int j = 0; j <= m; j++) {
            if (j + (1 << (i + 1)) <= m + 1) {
                up[i + 1][j] = min(up[i][j], up[i][j + (1 << i)]);
            }
        }
    }
    lg[1] = 0;
    for (int i = 2; i <= m + 1; i++) {
        lg[i] = lg[i - 1];
        if (!(i & (i - 1))) lg[i]++;
    }
    cout << solve(0, m + 1, 0) << '\n';
    return 0;
}