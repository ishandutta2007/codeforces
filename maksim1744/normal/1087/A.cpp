/*
    25.03.2019 20:01:55
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
    string s;
    cin >> s;
    int i1 = 0, i2 = s.size() - 1;
    string ans;
    while (i1 <= i2) {
        if ((i1 + i2) % 2 == 0) {
            ans.push_back(s[i1]);
            ++i1;
        } else {
            ans.push_back(s[i2]);
            --i2;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
    return 0;
}