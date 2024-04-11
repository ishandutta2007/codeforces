#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define vi vector<int>
using namespace std;
const int N = 1e5 + 10;
int n, a[N], b[N];
void solve() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    vector<int> b[2];
    ll sum = 0;
    FOR(i, 1, n) {
        int x;
        cin >> x;
        sum += x;
        b[a[i]].emplace_back(x);
    }
    FOR(i, 0, 1) sort(b[i].begin(), b[i].end(), greater<int>());
    ll mx = 0;
    FOR(i, 0, 1) {
        if(b[i].empty()) continue;
        int cnt = min(sz(b[i]) - 1, sz(b[i ^ 1]));
        ll sum = 0;
        FOR(j, 0, cnt - 1) sum += b[i][j] + b[i ^ 1][j];
        if(sz(b[i ^ 1]) > cnt) sum += b[i & 1][cnt];
        mx = max(mx, sum);
    }
    cout << sum + mx << "\n";
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; ) solve();
    return 0;
}