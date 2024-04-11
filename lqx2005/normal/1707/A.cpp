#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define ll long long
#define x first
#define y second
#define pi pair<ll, int>
using namespace std;
const int N = 1e5 + 10;
int n, q, a[N], s[N];
int check(int x) {
    int v = q;
    FOR(i, x, n) if(v < a[i]) v--;
    return v >= 0;
}
void solve() {
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i], s[i] = 0;
    int l = 1, r = n, best = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) best = mid, r = mid - 1;
        else l = mid + 1;
    }
    FOR(i, 1, best - 1) if(a[i] <= q) s[i] = 1;
    FOR(i, best, n) s[i] = 1;
    FOR(i, 1, n) cout << s[i];
    cout << "\n";
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; ) {
        solve();
    }
    return 0;
}