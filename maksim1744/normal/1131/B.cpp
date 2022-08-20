/*
    27.03.2019 18:10:10
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
    int ans = 1;
    pair<int, int> last = {0, 0};
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if (make_pair(a, b) == last) continue;
        if (a == last.first) {
            if (a > last.second && b >= a)
                ++ans;
        } else if (b == last.second) {
            if (b > last.first && a >= b)
                ++ans;
        } else {
            int d = min(a, b) - max(last.first, last.second) + (last.first != last.second);
            ans += max(0, d);
        }
        last = {a, b};
    }
    cout << ans << '\n';
    return 0;
}