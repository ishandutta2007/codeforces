#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define F first
#define S second
int t, n, h[101];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += h[i];
        if (sum < (ll)i * (i+1)/2) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}