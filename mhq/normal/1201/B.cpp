#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e5 + 10;
int a[maxN];
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    ll sm = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sm += a[i];
    }
    sort(a + 1, a + n + 1);
    if (sm % 2 == 1 || 2 * a[n] > sm) cout << "NO" << '\n';
    else cout << "YES" << '\n';
    return 0;
}