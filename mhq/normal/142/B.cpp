#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(228);
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    if (n > m) swap(n, m);
    if (n == 1) {
        cout << m;
        return 0;
    }
    if (n == 2) {
        int c1 = (m + 3) / 4;
        int c2 = (m + 2) / 4;
        cout << 2 * c1 + 2 * c2;
        return 0;
    }
    cout << (n * m + 1) / 2;
    return 0;
}