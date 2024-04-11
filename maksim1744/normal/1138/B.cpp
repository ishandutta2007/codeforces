/*
    16.03.2019 21:17:50
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#define TAG_LENGTH 45
#define LR_LEFT left
#define LR_RIGHT right
#define LR_VALUE value
#define LR_SECOND_VALUE mn
#include "C:/C++ libs/print.cpp"
#define showl cout << endl;
#define shows cout << string(5, ' ') + string(TAG_LENGTH, '-') << endl;
#else
#define show(...) 42;
#define showt(...) 42;
#define showl 42;
#define shows 42;
#define print(...) 42;
#define printTree(...) 42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

int main() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int cnt[2][2];
    for (int i = 0; i < 4; ++i) {
        cnt[i / 2][i % 2] = 0;
    }
    for (int i = 0; i < n; ++i) {
        ++cnt[a[i] - '0'][b[i] - '0'];
    }
    for (int i = 0; i <= cnt[1][0]; ++i) {
        for (int j = 0; j <= cnt[1][1]; ++j) {
            int cnt1 = i + j;
            int k10 = i, k11 = j;
            int k01 = cnt[0][1] - (cnt1 - (cnt[1][1] - j));
            if (k01 < 0 || k01 > cnt[0][1]) continue;
            int k00 = n / 2 - k10 - k11 - k01;
            if (k00 < 0 || k00 > cnt[0][0]) continue;
            for (int k = 0; k < n; ++k) {
                int i1 = a[k] - '0';
                int i2 = b[k] - '0';
                if (i1 == 0) {
                    if (i2 == 0) {
                        if (k00 > 0) {
                            --k00;
                            cout << k + 1 << ' ';
                        }
                    } else {
                        if (k01 > 0) {
                            --k01;
                            cout << k + 1 << ' ';
                        }
                    }
                } else {
                    if (i2 == 0) {
                        if (k10 > 0) {
                            --k10;
                            cout << k + 1 << ' ';
                        }
                    } else {
                        if (k11 > 0) {
                            --k11;
                            cout << k + 1 << ' ';
                        }
                    }
                }
            }
            cout << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}