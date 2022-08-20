/*
    17.03.2019 20:04:38
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
    int n;
    cin >> n;
    int cnt1 = 0, cnt2 = 0;
    for (auto c : s) {
        if (c == '*') ++cnt1;
        if (c == '?') ++cnt2;
    }
    if (n < s.size() - (cnt1 + cnt2) * 2 || n > s.size() - cnt2 + cnt1 * 1000000) {
        cout << "Impossible";
        return 0;
    }
    if (cnt1 > 0) {
        int ind = 0;
        int found = -1;
        while (ind < s.size()) {
            if (s[ind] == '?' || (s[ind] == '*' && found != -1)) {
                s.erase(s.begin() + ind - 1);
                s.erase(s.begin() + ind - 1);
                --ind;
            } else if (s[ind] == '*') {
                found = ind;
                ++ind;
            } else {
                ++ind;
            }
        }
        // show(found, s);
        char c = s[found - 1];
        s.erase(s.begin() + found - 1);
        s.erase(s.begin() + found - 1);
        while (s.size() < n) {
            s.insert(s.begin() + found - 1, c);
        }
        cout << s << '\n';
    } else {
        if (s.size() - cnt2 <= n) {
            int ind = 0;
            int m = s.size() - cnt2;
            while (ind < s.size()) {
                if (s[ind] == '?') {
                    s.erase(s.begin() + ind);
                    if (m < n) {
                        s.insert(s.begin() + ind, s[ind - 1]);
                        ++m;
                        ++ind;
                    }
                } else {
                    ++ind;
                }
            }
            cout << s << '\n';
        } else {
            int ind = 0;
            int m = s.size() - cnt2;
            while (ind < s.size()) {
                if (s[ind] == '?') {
                    s.erase(s.begin() + ind);
                    if (m > n) {
                        s.erase(s.begin() + ind - 1);
                        --m;
                        --ind;
                    }
                } else {
                    ++ind;
                }
            }
            cout << s << '\n';
        }
    }
    return 0;
}