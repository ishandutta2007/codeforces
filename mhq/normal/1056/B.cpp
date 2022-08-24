#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1005;
ll val[maxN];
int n, m;
int main() {
    //freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    int whole = n / m;
    for (int i = 1; i <= m; i++) {
        int t = (i * i) % m;
        val[t] += whole;
    }
    for (int i = whole * m + 1; i <= n; i++) {
        int t = (1LL * i * i) % m;
        val[t]++;
    }
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        ans += (1LL * val[i] * val[(m - i) % m]);
    }
    cout << ans;
    return 0;
}