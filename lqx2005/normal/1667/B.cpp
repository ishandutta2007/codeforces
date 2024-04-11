#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
const int N = 5e5 + 10;
int n, atot = 0;
struct fwt {
    int f[N];
    void clear(int n) {
        for(int i = 0; i <= n; i++) f[i] = -1e9;
    }
    void add(int x, int v) {
        for(; x <= atot; x += x & (-x)) f[x] = max(f[x], v);
    }
    int ask(int x) {
        int res = -1e9;
        for(; x > 0; x -= x & (-x)) res = max(res, f[x]);
        return res;
    }
}pre, suf;
int buc[N], dp[N];
ll a[N], arr[N];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
    atot = 0;
    for(int i = 0; i <= n; i++) arr[++atot] = a[i];
    sort(arr + 1, arr + atot + 1);
    atot = unique(arr + 1, arr + atot + 1) - (arr + 1);
    for(int i = 0; i <= n; i++) a[i] = lower_bound(arr + 1, arr + atot + 1, a[i]) - arr;
    pre.clear(atot), suf.clear(atot);
    for(int i = 1; i <= atot; i++) buc[i] = -1e9;
    dp[0] = 0, buc[a[0]] = 0, pre.add(a[0], 0), suf.add(atot + 1 - a[0], 0);
    for(int i = 1; i <= n; i++) {
        dp[i] = max({buc[a[i]], pre.ask(a[i] - 1) + i, suf.ask(atot + 1 - (a[i] + 1)) - i});
        buc[a[i]] = max(buc[a[i]], dp[i]);
        pre.add(a[i], dp[i] - i);
        suf.add(atot + 1 - a[i], dp[i] + i);
    }
    cout << dp[n] << endl;
    return;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; ) solve();
    return 0;
}