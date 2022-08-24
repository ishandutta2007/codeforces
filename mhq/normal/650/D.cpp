#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 4e5 + 10;
int h[maxN];
int d[maxN];
int lenPref[maxN], lenSuf[maxN];
const int INF = (int)1e9 + 10;
bool can[maxN];
int cnt[maxN];
int val[maxN];
vector < pair < int, int > > askPref[maxN];
vector < pair < int, int > > askSuf[maxN];
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    d[0] = -INF;
    for (int i = 1; i <= n; i++) {
        d[i] = INF;
    }
    for (int i = 1; i <= n; i++) {
        int where = lower_bound(d, d + n + 1, h[i]) - d;
        d[where] = h[i];
        lenPref[i] = where - 1;
    }
    d[0] = -INF;
    for (int i = 1; i <= n; i++) {
        d[i] = INF;
    }
    for (int i = n; i >= 1; i--) {
        int where = lower_bound(d, d + n + 1, -h[i]) - d;
        d[where] = -h[i];
        lenSuf[i] = where - 1;
    }
    int best = 0;
    for (int i = 1; i <= n; i++) best = max(best, lenPref[i] + 1);
    for (int i = 1; i <= n; i++) {
        if (lenPref[i] + lenSuf[i] + 1 != best) {
            can[i] = true;
            continue;
        }
        cnt[lenPref[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (lenPref[i] + lenSuf[i] + 1 != best) continue;
        if (cnt[lenPref[i]] > 1) can[i] = true;
        else can[i] = false;
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        askPref[a].emplace_back(b, i);
        askSuf[a].emplace_back(-b, i);
        ::a[i] = a;
    }
    d[0] = -INF;
    for (int i = 1; i <= n; i++) d[i] = INF;
    for (int i = 1; i <= n; i++) {
        for (auto it : askPref[i]) {
            int where = lower_bound(d, d + n + 1, it.first) - d;
            val[it.second] += where;
        }
        int where = lower_bound(d, d + n + 1, h[i]) - d;
        d[where] = h[i];
    }

    d[0] = -INF;
    for (int i = 1; i <= n; i++) d[i] = INF;
    for (int i = n; i >= 1; i--) {
        for (auto it : askSuf[i]) {
            int where = lower_bound(d, d + n + 1, it.first) - d;
            val[it.second] += where - 1;
        }
        int where = lower_bound(d, d + n + 1, -h[i]) - d;
        d[where] = -h[i];
    }
    for (int i = 1; i <= m; i++) {
        int ans = val[i];
        if (can[a[i]]) ans = max(ans, best);
        else ans = max(ans, best - 1);
        cout << ans << '\n';
    }
    return 0;
}