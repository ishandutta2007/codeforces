#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define F first
#define S second
int t, n, a[101];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int mini = INT_MAX;
    for (int i = 0; i < n; i++) mini = min(mini, a[i]);
    int ans = n;
    for (int i = 0; i < n; i++) {
        if (a[i]==mini) ans--;
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