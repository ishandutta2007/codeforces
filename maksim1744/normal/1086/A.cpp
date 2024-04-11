/*
    25.03.2019 14:34:49
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
    vector<pair<int, int>> v(3);
    for (int i = 0; i < 3; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    vector<pair<int, int>> ans;
    int x = v[0].first, y = v[0].second;
    while (x <= v[1].first) {
        ans.emplace_back(x, y);
        ++x;
    }
    show(x, y, ans);
    x = v[1].first;
    if (y <= v[1].second) {
        ++y;
        while (y <= v[1].second) {
            ans.emplace_back(x, y);
            ++y;
        }
    } else {
        --y;
        while (y >= v[1].second) {
            ans.emplace_back(x, y);
            --y;
        }
    }
    if (v[0].second <= v[2].second && v[2].second <= v[1].second || v[0].second >= v[2].second && v[2].second >= v[1].second) {
        x = v[1].first + 1;
        y = v[2].second;
        while (x <= v[2].first) {
            ans.emplace_back(x, y);
            ++x;
        }
    } else {
        int y1 = min(v[0].second, v[1].second);
        int y2 = max(v[0].second, v[1].second);
        if (v[2].second < y1) {
            x = v[1].first;
            y = y1 - 1;
            while (y >= v[2].second) {
                ans.emplace_back(x, y);
                --y;
            }
        } else {
            x = v[1].first;
            y = y2 + 1;
            while (y <= v[2].second) {
                ans.emplace_back(x, y);
                ++y;
            }
        }
        ++x;
        y = v[2].second;
        while (x <= v[2].first) {
            ans.emplace_back(x, y);
            ++x;
        }
    }
    cout << ans.size() << '\n';
    for (auto p : ans) {
        cout << p.first << ' ' << p.second << '\n';
    }
    return 0;
}