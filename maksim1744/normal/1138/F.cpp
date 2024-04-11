/*
    16.03.2019 20:53:23
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

vector< int > ask(vector< int > v) {
    cout << "next ";
    for (auto k : v) {
        cout << k << ' ';
    }
    cout << endl;
    int k;
    cin >> k;
    vector< int > groups(10);
    for (int i = 0; i < k; ++i) {
        string s;
        cin >> s;
        for (auto c : s) {
            groups[c - '0'] = i;
        }
    }
    return groups;
}

int main() {
    int cnt = 0;
    while (true) {
        ++cnt;
        ask({0});
        auto v = ask({0, 1});
        if (v[0] == v[1])
            break;
    }
    while (true) {
        auto v = ask({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
        if (v[0] == v[5])
            break;
    }
    cout << "done" << endl;
    return 0;
}