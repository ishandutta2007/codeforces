#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a[n];
    for (int i = 0; i < n; ++i) {
        a[i] = int(s[i]) - 48;
    }
    int cnt0 = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) { cnt0++; }
    }
    int cnt1 = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) { cnt1++; }
    }
    int cnt2 = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 2) { cnt2++; }
    }
    int zers[cnt0];
    int p = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            zers[p++] = i;
        }
    }
    int ones[cnt1];
    p = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            ones[p++] = i;
        }
    }
    int twos[cnt2];
    p = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 2) {
            twos[p++] = i;
        }
    }
    n = int(n / 3);
    int a_copy[n * 3];
    for (int i = 0; i < n * 3; ++i) {
        a_copy[i] = a[i];
    }
    if ((cnt0 < n) xor (cnt1 < n) xor (cnt2 < n)) {
        if (cnt0 < n) {
            for (int i = 0; i < (cnt1 - n); ++i) {
                a[ones[i]] = 0;
            }
            for (int i = 0; i < (cnt2 - n); ++i) {
                a[twos[i]] = 0;
            }
        }
        if (cnt1 < n) {
            for (int i = 0; i < (cnt0 - n); ++i) {
                a[zers[cnt0 - i - 1]] = 1;
            }
            for (int i = 0; i < (cnt2 - n); ++i) {
                a[twos[i]] = 1;
            }
        }
        if (cnt2 < n) {
            for (int i = 0; i < (cnt0 - n); ++i) {
                a[zers[cnt0 - i - 1]] = 2;
            }
            for (int i = 0; i < (cnt1 - n); ++i) {
                a[ones[cnt1 - i - 1]] = 2;
            }
        }
    }
    int a_result[n * 3];
    for (int i = 0; i < n * 3; ++i) {
        a_result[i] = a[i];
    }
    for (int i = 0; i < n * 3; ++i) {
        a[i] = a_copy[i];
    }
    if ((cnt0 > n) xor (cnt1 > n) xor (cnt2 > n)) {
        if (cnt0 > n) {
            for (int i = 0; i < (n - cnt2); ++i) {
                a[zers[cnt0 - i - 1]] = 2;
            }
            for (int i = (n - cnt2); i < (n - cnt2) + (n - cnt1); ++i) {
                a[zers[cnt0 - i - 1]] = 1;
            }
        }
        if (cnt1 > n) {
            for (int i = 0; i < (n - cnt0); ++i) {
                a[ones[i]] = 0;
            }
            for (int i = 0; i < (n - cnt2); ++i) {
                a[ones[cnt1 - i - 1]] = 2;
            }
        }
        if (cnt2 > n) {
            for (int i = 0; i < (n - cnt0); ++i) {
                a[twos[i]] = 0;
            }
            for (int i = (n - cnt0); i < (n - cnt0) + (n - cnt1); ++i) {
                a[twos[i]] = 1;
            }
        }
    }
    bool first_more;
    for (int i = 0; i < n * 3; ++i) {
        if (a_result[i] != a[i]) {
            first_more = a_result[i] > a[i];
            break;
        }
    }
    if (((cnt0 < n) xor (cnt1 < n) xor (cnt2 < n)) &&
        !((cnt0 > n) xor (cnt1 > n) xor (cnt2 > n))) { first_more = false; }
    if (!((cnt0 < n) xor (cnt1 < n) xor (cnt2 < n)) &&
        ((cnt0 > n) xor (cnt1 > n) xor (cnt2 > n))) { first_more = true; }
    if (!first_more) {
        for (int i = 0; i < n * 3; ++i) {
            cout << a_result[i];
        }
    } else {
        for (int i = 0; i < n * 3; ++i) {
            cout << a[i];
        }
    }
    cout << "\n";

}