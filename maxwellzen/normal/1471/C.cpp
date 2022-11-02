#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define F first
#define S second
int t, n, m;

void solve() {
    cin >> n >> m;
    vi k(n), c(m);
    for (int i = 0; i < n; i++) cin >> k[i];
    for (int i = 0; i < m; i++) cin >> c[i];
    sort(k.begin(), k.end(), greater<>());
    int r = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (r+1 < k[i]) {
            ans += c[r];
            r++;
        } else ans += c[k[i]-1];
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}