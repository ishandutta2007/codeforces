#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define F first
#define S second
int t, n, x[1001], y[1001];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    if (n%2!=0) {
        cout << 1 << '\n';
        return;
    }
    sort(x, x+n);
    sort(y, y+n);
    int half = n / 2;
    cout << (ll)(x[half] - x[half-1] + 1) * (ll)(y[half]-y[half-1]+1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}