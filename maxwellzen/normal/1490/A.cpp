#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define F first
#define S second
int t, n, a[100000], ans, x, y;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    ans = 0;
    for (int i = 0; i < n-1; i++) {
        x = min(a[i], a[i+1]);
        y = max(a[i], a[i+1]);
        while (y > 2*x) {
            ans++;
            x = 2*x;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}