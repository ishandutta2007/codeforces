/*
    27.03.2019 23:17:21
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOMEm
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

long long intersect(pair<long long, long long> a, pair<long long, long long> b) {
    assert(a.first != b.first);
    if (a.first < b.first)
        swap(a, b);
    return (b.second - a.second + a.first - b.first - 1) / (a.first - b.first);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<pair<long long, long long>, long long>> v(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i].first.first >> v[i].first.second >> v[i].second;
    }
    sort(v.begin() + 1, v.end());
    show(v);
    vector<long long> dp(n + 1);
    dp[0] = 0;
    vector<pair<long long, long long>> s;
    s.emplace_back(0, 0);
    for (int i = 1; i <= n; ++i) {
        shows;
        int l = -1, r = s.size() - 1;
        int to_find = v[i].first.second;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (m + 1 == s.size() || intersect(s[m], s[m + 1]) <= to_find) {
                r = m;
            } else {
                l = m;
            }
        }
        int ind = r;
        auto jline = s[ind];
        show(s, ind, to_find);
        dp[i] = jline.first * v[i].first.second + jline.second + v[i].first.first * v[i].first.second - v[i].second;
        pair<long long, long long> line = {-v[i].first.first, dp[i]};
        while (s.size() > 1 && intersect(s.back(), line) >= intersect(s[s.size() - 2], s.back())) {
            s.pop_back();
            show(s);
        }
        show("ok");
        s.push_back(line);
    }
    show(dp);
    cout << *max_element(dp.begin(), dp.end()) << '\n';
    return 0;
}