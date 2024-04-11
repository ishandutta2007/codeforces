
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 3e5 + 5;
int t, n;
ll a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }
        ll sum = 0, m = LLONG_MAX;
        for(int i = 0; i < n; i++) {
            ll cost = max(0LL, a[i] - b[(i + n - 1) % n]);
            sum += cost;
            m = min(m, a[i] - cost);
        }
        cout << sum + m << '\n';
    }
}