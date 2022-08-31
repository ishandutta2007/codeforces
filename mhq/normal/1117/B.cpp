#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 100;
int a[maxN];
int n, m, k;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    ll ans = 0;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    //0 .. k - 1, k, k + 1 .. 2k, 2k + 1
    //(k + 1) * x - 1 <= m - 1
    int num = m / (k + 1);
    int left = m - num;
    ans = 1LL * left * a[1] + 1LL * num * a[2];
    cout << ans;
}