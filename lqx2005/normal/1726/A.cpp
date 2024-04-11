#include <bits/stdc++.h>
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define sz(a) int((a).size())
#define ll long long
#define db double
#define vi vector<int>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    FOR(i, 0, n - 1) cin >> a[i];
    if(n == 1) {
        cout << "0\n";
        return;
    }
    int mx = -1e9;
    FOR(i, 1, n - 1) mx = max(mx, a[i]);
    int ans = -1e9;
    ans = max(ans, mx - a[0]);
    mx = 1e9;
    FOR(i, 0, n - 2) mx = min(mx, a[i]);
    ans = max(ans, a[n - 1] - mx);
    FOR(i, 0, n - 1) ans = max(ans, a[(i - 1 + n) % n] - a[i]);
    cout << ans << "\n";
    return;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; solve());
}