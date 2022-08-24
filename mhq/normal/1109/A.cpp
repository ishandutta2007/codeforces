#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxN = 3 * (int)1e5 + 100;
int f[(1 << 20) + 10][2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int cur = 0;
    ll ans = 0;
    cin >> n;
    f[cur][0]++;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cur ^= x;
        ans += f[cur][i % 2];
        f[cur][i % 2]++;
    }
    cout << ans;
}