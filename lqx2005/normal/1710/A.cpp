#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define db double
#define x first
#define y second
#define pi pair<ll, int>
#define vi vector<int>
using namespace std;
const int N = 1e5 + 10;
int n, m, k;
int a[N], b[N];
int check(int cnt) {
    ll sum = 0;
    FOR(i, 1, k) sum += b[i];
    if(sum < cnt) return 0;
    FOR(i, 1, k) if(b[i] >= 3) return 1;
    if(cnt & 1) return 0;
    return 1;
}
void solve() {
    cin >> n >> m >> k;
    FOR(i, 1, k) cin >> a[i];
    FOR(i, 1, k) {
        if(a[i] / n > 1) b[i] = a[i] / n;
        else b[i] = 0;
    }
    if(check(m)) {
        cout << "Yes\n";
        return;
    }
    FOR(i, 1, k) {
        if(a[i] / m > 1) b[i] = a[i] / m;
        else b[i] = 0;
    }
    if(check(n)) {
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
    return;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; ) solve();
    return 0;
}