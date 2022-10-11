#include <bits/stdc++.h>
using namespace std;

const int N = 2E5 + 5;

int n, s, t, u, q, a[N], b[N];
long long ans = 0;
map<pair<int, int>, int> ma;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans += a[i];
    }
    cin >> q;
    while (q--) {
        cin >> s >> t >> u;
        if (ma[{s, t}] != 0) {
            int v = ma[{s, t}];
            b[v]--;
            if (b[v] < a[v]) {
                ans++;
            }
            ma[{s, t}] = 0;
        }
        if (u != 0) {
            ma[{s, t}] = u;
            b[u]++;
            if (b[u] <= a[u]) {
                ans--;
            }
        }
        cout << ans << '\n';
    }
}