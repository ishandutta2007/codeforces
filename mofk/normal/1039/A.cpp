#include <bits/stdc++.h>

using namespace std;

int n;
long long t;
long long a[200005];
int x[200005];
long long b[200005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> t;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> x[i];
    a[n+1] = 1e18 + 1e17;
    int max_seen = 0;
    for (int i = 1; i <= n; ++i) {
        if (x[i] < i) return cout << "No" << endl, 0;
        if (x[i] < x[i-1]) return cout << "No" << endl, 0;
        if (i <= max_seen && x[i] > max_seen) return cout << "No" << endl, 0;
        if (x[i] == x[i-1]) continue;
        for (int j = x[i-1] + 1; j < x[i]; ++j) b[j] = a[j+1];
        b[x[i]] = a[x[i]+1] - 1;
        max_seen = x[i];
    }
    for (int i = 1; i < n; ++i) if (b[i] >= b[i+1]) return cout << "No" << endl, 0;
    for (int i = 1; i <= n; ++i) b[i] += t;
    cout << "Yes" << endl;
    for (int i = 1; i <= n; ++i) cout << b[i] << ' '; cout << endl;
    return 0;
}