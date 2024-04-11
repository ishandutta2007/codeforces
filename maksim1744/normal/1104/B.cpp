/*
    16.03.2019 17:18:46
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
    stack< char > st;
    for (int i = 0; i < s.size(); ++i) {
        if (!st.empty() && st.top() == s[i])
            st.pop();
        else
            st.push(s[i]);
    }
    int k = st.size();
    int n = s.size();
    if ((n - k) / 2 % 2 == 1) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}