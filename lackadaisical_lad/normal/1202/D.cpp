//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int a = 0, b = 0, c = 0, d = 0;
        bool f = false;
        for (int i = 1; i <= 10000; i++) { // a
            for (int j = 1; j <= n / i; j++) { // c
                int x = i * j;
                if (x == n && (i + j) + 3 < 1e5) {
                    a = i;
                    c = j;
                    b = d = 0;
                    f = true;
                    break;
                }
                for (int k = 1; k * k <= n - x; k++) { // d
                    if ((n - x) % k == 0) {
                        int y = (n - x) / k;
                        if (y - 3 * i >= 0 && i + j + y - 3 * i + k + 3 < 1e5) {
                            a = i;
                            c = j;
                            b = y - 3 * a;
                            d = k;
                            f = true;
                            break;
                        }
                    }
                }
                if (f) {
                    break;
                }
            }
            if (f) {
                break;
            }
        }
        for (int i = 0; i < a; i++) {
            cout << 1;
        }
        cout << 3;
        for (int i = 0; i < b; i++) {
            cout << 1;
        }
        cout << 3;
        for (int i = 0; i < c; i++) {
            cout << 7;
        }
        cout << 3;
        for (int i = 0; i < d; i++) {
            cout << 7;
        }
        cout << '\n';
    }
    return 0;
}