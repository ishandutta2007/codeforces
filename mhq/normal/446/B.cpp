#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = (int)1e3 + 10;
const ll INF = (ll)1e18;
int n, m, k, p;
int a[maxN][maxN];
ll row[maxN];
ll col[maxN];
ll fr[maxN * maxN], fc[maxN * maxN];
multiset < ll > s;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k >> p;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            row[i] += a[i][j];
            col[j] += a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) s.insert(row[i]);
    ll cur = 0;
    for (int i = 0; i <= k; i++) {
        fr[i] = cur;
        auto it = s.end();
        it--;
        ll f = *it;
        //cout << f << endl;
        cur += f;
        s.erase(it);
        f -= m * p;
        s.insert(f);
    }
    s.clear();
    // -= i * p
    for (int i = 1; i <= m; i++) s.insert(col[i]);
    cur = 0;
    for (int i = 0; i <= k; i++) {
        fc[i] = cur;
        auto it = s.end();
        it--;
        ll f = *it;
        cur += f;
        s.erase(it);
        f -= n * p;
        s.insert(f);
    }
    ll ans = -INF;
    for (int i = 0; i <= k; i++) {
        ans = max(ans, fr[i] + fc[k - i] - 1LL * i * (k - i) * p);
    }
    cout << ans;
}