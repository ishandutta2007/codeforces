/*
    01.04.2019 19:33:30
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
    auto no = []() {
        cout << "NO\n";
        exit(0);
    };
    auto yes = []() {
        cout << "YES\n";
        exit(0);
    };
    if (n % 10 == 1 || n / 10 == 9 || n % 10 == 9 || n / 10 == 7 || n % 10 == 7 || n == 11 || (n > 12 && n < 20) || n / 10 == 2 || n == 10) no();
    else yes();
    return 0;
}