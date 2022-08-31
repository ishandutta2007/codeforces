#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = (int)1e6 + 10;
int a[maxN];
int n;
ll x, y;
vector < int > all;
const ll INF = (ll)1e18;
ll ans = INF;
void add(int x) {
    if (x == 1) return ;
    for (int i = 2; 1LL * i * i <= x; i++) {
        if (x % i == 0) {
            all.push_back(i);
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) all.push_back(x);
}
ll cost[maxN];
ll pref[maxN], suf[maxN];
ll mn_suf[maxN];
void solve(int p) {
    int mn_bad = n + 1;
    int mx_bad = 0;
    for (int i = 1; i <= n; i++) {
        int res = a[i] % p;
        if (res == 0) cost[i] = 0;
        else if (res == 1 || res == p - 1) cost[i] = y;
        else cost[i] = -1;
        pref[i] = pref[i - 1] + cost[i] - x;
        if (cost[i] == -1) {
            mn_bad = min(mn_bad, i);
            mx_bad = max(mx_bad, i);
        }
    }
    suf[n + 1] = 0;
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] + cost[i];
    }
    for (int i = n + 1; i >= 1; i--) {
        suf[i] += x * i;
        if (i == n + 1) mn_suf[i] = suf[i];
        else mn_suf[i] = min(mn_suf[i + 1], suf[i]);
    }
    // i [0 .. j - 1],
    // j [1 .. n + 1]
    // suf[j] - pref[i] + x * (j - i - 1) = suf[j] + x * j - pref[i] - x * i + x
    // j > i
    for (int i = 0; i <= max(mn_bad - 1, 0); i++) {
        ll upper = max(mx_bad, i);
        ans = min(ans, mn_suf[upper + 1] + pref[i] - x);
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < 2; i++) {
        int ind = 1;
        if (i == 1) ind = n;
        for (int j = -1; j <= 1; j++) add(a[ind] + j);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    ans = (n - 1) * x;
    for (int v : all) {
        solve(v);
    }
    cout << ans;
    return 0;
}