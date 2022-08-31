/*
    25.03.2019 21:41:37
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
    vector<pair<int, int>> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i].first >> c[i].second;
    }
    vector<pair<int, int>> d(n);
    multiset<pair<int, int>> sd;
    for (int i = 0; i < n; ++i) {
        cin >> d[i].first >> d[i].second;
        sd.insert(d[i]);
    }
    for (int i = 0; i < n; ++i) {
        auto ssd = sd;
        ssd.erase(ssd.find(d[i]));
        bool ok = true;
        pair<int, int> ans = {c[0].first + d[i].first, c[0].second + d[i].second};
        for (int j = 1; j < n; ++j) {
            pair<int, int> pr = {ans.first - c[j].first, ans.second - c[j].second};
            auto it = ssd.find(pr);
            if (it == ssd.end()) {
                ok = false;
                break;
            }
            ssd.erase(it);
        }
        if (ok) {
            cout << ans.first << ' ' << ans.second << '\n';
            return 0;
        }
    }
    return 0;
}