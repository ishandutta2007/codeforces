/*
    02.04.2019 13:55:47
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
    vector<int> v;
    while (n) {
        v.push_back(n % 10);
        n /= 10;
    }
    reverse(v.begin(), v.end());
    vector<int> p9(12);
    p9[0] = 1;
    for (int i = 1; i < p9.size(); ++i)
        p9[i] = p9[i - 1] * 9;
    int ans = p9[v.size() - 1];
    int p = 1;
    for (int i = 0; i < v.size(); ++i) {
        ans = max(ans, p * (v[i] - 1) * p9[(int)v.size() - i - 1]);
        p *= v[i];
    }
    cout << max(p, ans) << '\n';
    return 0;
}