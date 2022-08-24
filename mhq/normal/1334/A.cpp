#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 105;
int p[maxN], c[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            cin >> p[i] >> c[i];
            if (p[i - 1] > p[i] || c[i - 1] > c[i] || (p[i] - p[i - 1] < c[i] - c[i - 1])) ok = false;
        }
        cout << ((ok ? "YES" : "NO")) << '\n';
    }
    return 0;
}