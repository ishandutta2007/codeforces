#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e5 + 100;
int lp[maxN];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int sz = 1;
    for (int i = 2; i <= n; i++) {
        if (lp[i] == 0) {
            lp[i] = sz;
            sz++;
            for (int j = 2 * i; j <= n; j += i) lp[j] = lp[i];
        }
        cout << lp[i] << " ";
    }
    return 0;
}