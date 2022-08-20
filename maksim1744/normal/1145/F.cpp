/*
    01.04.2019 19:43:34
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
    string a = "QRUOPSDGJBC";
    string b = "AWETYIFHKLMNVXZ";
    vector<int> v(26, 1);
    for (auto c : a) {
        v[c - 'A'] = -1;
    }
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (v[s[i] - 'A'] != v[s[0] - 'A']) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}