/*
    16.03.2019 14:51:24
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
    long long k;
    cin >> k;
    long long t = 1, n = 2000;
    long long s = k + t * n;
    vector< int > ans(1, -t);
    while (s > 0) {
        if (s > 1000000) {
            ans.push_back(1000000);
            s -= 1000000;
        } else {
            ans.push_back(s);
            s = 0;
        }
    }
    ans.resize(n, 0);
    cout << ans.size() << '\n';
    for (auto k : ans) {
        cout << k << ' ';
    }
    cout << '\n';
    // long long n = 1999;
    // long long t = 500;
    // while ((k + n * t) % 1000 != 0)
    //     ++t;
    // long long s = (k + n * t) / 1000;
    // vector< int > ans;
    // long long m = 500;
    // for (int i = 0; i < m; ++i) {
    //     ans.push_back(1);
    //     ans.push_back(-2);
    // }
    // ans.back() = -(t - (m - 1) + 1);
    // int ind = 1000;
    // while (s > 0) {
    //     if (s > 1000000) {
    //         ans[ind] = 1000000;
    //         s -= 1000000;
    //     } else {
    //         ans[ind] = s;
    //         s = 0;
    //     }
    //     ++ind;
    // }
    // if (k + 1 == 1000000000) {
    //     vector< int > ans;
    //     for (int i = 0; i < 125; ++i) {
    //         ans.push_back(1);
    //         ans.push_back(-1);
    //     }
    //     ans.back() = -2;
    //     for (int i = 0; i < 4; ++i) {
    //         ans.push_back(1000000);
    //     }
    //     ans.push_back(2);
    //     while (ans.size() < 501)
    //         ans.push_back(0);
    //     cout << ans.size() << '\n';
    //     for (auto k : ans) {
    //         cout << k << ' ';
    //     }
    //     cout << '\n';
    //     return 0;
    // }
    // long long ij = 2000;
    // while ((k + ij) % 1000 != 0)
    //     --ij;
    // k += ij;
    // assert(ij > 1000);
    // show(ij);
    // long long sj = k / 1000;
    // // assert((ij - 1000) * 1000000 >= sj);
    // vector< int > ans;
    // for (int i = 0; i < 500; ++i) {
    //     ans.push_back(1);
    //     ans.push_back(-1);
    // }
    // ans.back() = -2;
    // while (sj > 0) {
    //     if (sj > 1000000) {
    //         ans.push_back(1000000);
    //         sj -= 1000000;
    //     } else {
    //         ans.push_back(sj);
    //         sj = 0;
    //     }
    // }
    // assert(sj * (ij - 1000) < 999);
    // while (ans.size() < ij)
    //     ans.push_back(0);
    // assert(ij == ans.size());
    // assert(ans.size() <= 2000);
    // assert(*max_element(ans.begin(), ans.end()) <= 1000000);
    // assert(*min_element(ans.begin(), ans.end()) >= -1000000);
    // cout << ans.size() << '\n';
    // for (auto k : ans) {
    //     cout << k << ' ';
    // }
    // cout << '\n';
    return 0;
}