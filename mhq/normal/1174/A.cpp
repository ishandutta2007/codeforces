#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2005;
int a[maxN];
int n;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) cin >> a[i];
    sort(a + 1, a + 2 * n + 1);
    if (a[1] == a[2 * n]) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= 2 * n; i++) cout << a[i] << " ";
    return 0;
}