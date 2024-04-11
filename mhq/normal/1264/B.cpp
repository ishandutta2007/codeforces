#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int a, b, c, d;
const int maxN = (int)1e5 + 100;
int f[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> a >> b >> c >> d;
    if (abs(a + c - b - d) > 1) {
        cout << "NO";
        return 0;
    }
    if (a + c >= b + d) {
        int cnt0 = 0;
        int cnt1 = 0;
        for (int i = 1; i <= a + b + c + d; i++) {
            if (i % 2 == 1) {
                if (cnt0 < a) {
                    f[i] = 0;
                    cnt0++;
                }
                else {
                    f[i] = 2;
                }
            }
            else {
                if (cnt1 < b) {
                    f[i] = 1;
                    cnt1++;
                }
                else {
                    f[i] = 3;
                }
            }
        }
    }
    else {
        int cnt0 = 0;
        int cnt1 = 0;
        for (int i = 1; i <= a + b + c + d; i++) {
            if (i % 2 == 0) {
                if (cnt0 < a) {
                    f[i] = 0;
                    cnt0++;
                }
                else {
                    f[i] = 2;
                }
            }
            else {
                if (cnt1 < b) {
                    f[i] = 1;
                    cnt1++;
                }
                else {
                    f[i] = 3;
                }
            }
        }
    }
    for (int i = 1; i + 1 <= a + b + c + d; i++) {
        if (abs(f[i] - f[i + 1]) != 1) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << '\n';
    for (int i = 1; i <= a + b + c + d; i++) cout << f[i] << " ";
    return 0;
}