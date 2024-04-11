#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 4005;
int s[maxN];
int l[maxN];
int c[maxN];
vector < int > all[maxN];
const ll INF = (ll)1e18;
int at_most[maxN];
ll vals[maxN][maxN];
ll new_val[maxN];
ll cur_val[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> l[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        all[l[i]].emplace_back(i);
    }
    for (int i = 1; i <= n + m; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        at_most[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            vals[j][i] = -INF;
        }
    }
    for (int i = 1; i <= n + m; i++) {
        //recalc
        for (int j = 1; j <= n; j++) {
            for (int p = 0; p <= at_most[j] / 2; p++) {
                new_val[p] = -INF;
            }
            for (int p = 0; p <= at_most[j]; p++) {
                new_val[p / 2] = max(new_val[p / 2], vals[j][p] + (p / 2) * c[i]);
            }
            for (int p = 0; p <= at_most[j]; p++) {
                vals[j][p] = -INF;
            }
            at_most[j] /= 2;
            for (int p = 0; p <= at_most[j]; p++) {
                vals[j][p] = new_val[p];
            }
        }
        for (int j = 0; j <= n; j++) {
            cur_val[j] = -INF;
        }
        reverse(all[i].begin(), all[i].end());
        for (int p : all[i]) {
            for (int t = p + 1; t <= n; t++) {
                if (l[p] < l[t]) continue;
                if (l[p] > l[t]) {
                    for (int j = 0; j <= at_most[t]; j++) {;
                        cur_val[j] = max(cur_val[j], vals[t][j]);
                    }
                }
                else {
                    for (int j = 0; j <= at_most[t]; j++) {
                        cur_val[j] = max(cur_val[j], vals[t][j]);
                    }
                    break;
                }
            }
            at_most[p] = n;
            cur_val[0] = max(cur_val[0], 0LL);
            vals[p][0] = -INF;
            for (int j = 0; j <= n; j++) vals[p][j] = -INF;
            for (int j = 0; j <= n; j++) {
                vals[p][j] = max(vals[p][j], cur_val[j]);
                vals[p][j + 1] = max(vals[p][j + 1], cur_val[j] - s[p] + c[i]);
            }
        }
    }
    ll mx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= at_most[i]; j++) mx = max(mx, vals[i][j]);
    }
    cout << mx;
    return 0;
}