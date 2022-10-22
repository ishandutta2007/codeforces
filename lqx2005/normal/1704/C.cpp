#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define ull unsigned long long
#define db double
#define x first
#define y second
#define vi vector<int>
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for(auto &x : a) cin >> x, x--;
    sort(a.begin(), a.end());
    vector<int> delta;
    FOR(i, 0, m - 1) delta.emplace_back((a[(i + 1) % m] - a[i] - 1 + n) % n);
    sort(delta.begin(), delta.end(), greater<int>());
    ll ans = 0, cnt = 0;
    for(auto x : delta) {
        if(x - cnt * 2 <= 0) continue;
        if(x - cnt * 2 <= 2) ans += 1, cnt += 1;
        else ans += x - cnt * 2 - 1, cnt += 2;
    }
    cout << n - ans << "\n";
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; ) solve();
    return 0;
}