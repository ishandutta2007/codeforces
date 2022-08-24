#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 11;
int a[maxN];
int pw3[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        pw3[0] = 1;
        for (int i = 1; i <= n; i++) pw3[i] = 3 * pw3[i - 1];
        bool ok = false;
        for (int f = 1; f < pw3[n]; f++) {
            int s = 0;
            for (int z = 0; z < n; z++) {
                int bit = (f / pw3[z]) % 3;
                if (bit == 1) s += a[z];
                else if (bit == 2) s -= a[z];
            }
            if (s == 0) ok = true;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}