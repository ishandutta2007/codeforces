#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> ii;

int n;
vector<ii> ans;

inline char col_char(int x) { return char(x + 96); }

ii move_next(ii cur) {
    if (cur.fi == 1 || cur.fi == 8) {
        ++cur.se;
        if (cur.se > 8) ++cur.fi, cur.se = 8;
    } else {
        int d = cur.se % 2 == 0 ? 1 : -1;
        cur.fi += d;
        if (cur.fi > 7) cur.fi = 7, --cur.se;
        if (cur.fi < 2) cur.fi = 2, --cur.se;
    }
    return cur;
}

int main() {
    cin >> n;
    ans.push_back({1, 1});
    if (8 <= n && n <= 15) {
        if (n < 15) {
            for (int i = 1; i < n; ++i) ans.push_back(move_next(ans.back()));
            ans.push_back({8, 8});
        } else {
            cout << "a1 b1 c1 d1 e1 f1 g1 h1 h2 h3 h4 h5 h6 g6 g8 h8";
            return 0;
        }
    } else {
        for (int i = 1; i <= min(n - 2, 55); ++i)
            ans.push_back(move_next(ans.back()));
        if (n <= 57) {
            ans.push_back({8, ans.back().se});
        } else {
            ans.push_back({8, 1});
            for (int i = 57; i < n; ++i) 
                ans.push_back(move_next(ans.back()));
        }
        ans.push_back({8, 8});
    }
    for (ii i : ans) cout << col_char(i.se) << i.fi << " ";
    return 0;
}