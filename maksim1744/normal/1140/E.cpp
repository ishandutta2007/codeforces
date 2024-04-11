/*
    23.03.2019 16:45:03
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

long long mod = 998244353;

long long mpow(long long a, long long p, long long mod = mod) {
    long long res = 1;
    while (p) {
        if (p & 1) res = res * a % mod;
        p >>= 1;
        a = a * a % mod;
    }
    return res;
}

int main() {
    long long n, k;
    cin >> n >> k;
    vector< int > a;
    vector< int > b;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        if (i % 2 == 0)
            a.push_back(k);
        else
            b.push_back(k);
    }
    bool ok = true;
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] == a[i - 1] && a[i] != -1) {
            ok = false;
            break;
        }
    }
    for (int i = 1; i < b.size(); ++i) {
        if (b[i] == b[i - 1] && b[i] != -1) {
            ok = false;
            break;
        }
    }
    if (!ok) {
        cout << 0 << '\n';
        return 0;
    }
    show(a, b);
    long long ans = 1;
    for (int iii = 0; iii < 2; ++iii) {
        shows;
        if (a == vector< int >(a.size(), -1))
            ans = ans * k % mod * mpow(k - 1, (int)a.size() - 1) % mod;
        else {
            int i1 = 0;
            int i2 = 0;
            while (i1 < a.size() && a[i1] != -1)
                ++i1;
            while (i1 < a.size()) {
                long long bad = 1;
                long long other = 0;
                i2 = i1;
                while (i2 < a.size() && a[i2] == -1) {
                    long long new_bad = other * (k - 1) % mod;
                    long long new_other = (other * (k - 2) + bad) % mod;
                    bad = new_bad;
                    other = new_other;
                    ++i2;
                }
                show(i1, i2, bad, other);
                if (i1 == 0 || i2 == a.size()) {
                    ans = (ans * mpow(k - 1, i2 - i1)) % mod;
                } else {
                    if (a[i1 - 1] == a[i2])
                        ans = ans * other % mod * (k - 1) % mod;
                    else
                        ans = ans * ((other * (k - 2) + bad) % mod) % mod;
                }
                i1 = i2;
                while (i1 < a.size() && a[i1] != -1)
                    ++i1;
            }
        }
        swap(a, b);
    }
    cout << ans % mod << '\n';
    return 0;
}