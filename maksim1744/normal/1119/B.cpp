/*
    06.04.2019 14:39:27
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#define TAG_LENGTH 25
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
    long long n, h;
    cin >> n >> h;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    multiset<long long> s;
    for (int i = 0; i < n; ++i) {
        s.insert(a[i]);
        auto it = s.end();
        --it;
        long long need_h = 0;
        while (true) {
            if (it == s.begin()) {
                need_h += *it;
                break;
            } else {
                need_h += *it;
                --it;
                if (it == s.begin())
                    break;
                else
                    --it;
            }
        }
        show(s, need_h);
        if (need_h > h) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << n << '\n';
    return 0;
}