#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
vector < pair < int, int > > all;
int A;
int B;
bool check(int K) {
    int x_small = 0;
    int x_big = 1e7;
    int y_small = 0;
    int y_big = 1e7;
    int diff_big = 1e7;
    int diff_small = -1e7;
    for (auto& it : all) {
        int X = it.first;
        int Y = it.second;
        x_big = min(x_big, X + K);
        x_small = max(x_small, X - K);
        y_big = min(y_big, Y + K);
        y_small = max(y_small, Y - K);
        diff_big = min(diff_big, X - Y + K);
        diff_small = max(diff_small, X - Y - K);
    }
    if (x_small > x_big || y_small > y_big || diff_small > diff_big) return false;
    int range_big = x_big - y_small;
    int range_small = x_small - y_big;
    A = x_small;
    B = y_big;
    A += max(0, min(x_big - x_small, diff_small - (A - B)));
    B -= max(0, min(y_big - y_small, diff_small - (A - B)));
    if (range_big < diff_small || range_small > diff_big) return false;
    assert(x_small <= A && A <= x_big);
    assert(y_small <= B && B <= y_big);
    assert(diff_small <= A - B && A - B <= diff_big);
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mx = max(mx, (int)s.size());
        all.emplace_back(0, 0);
        for (char& c : s) {
            if (c == 'B') all.back().first++;
            else all.back().second++;
        }
    }
//    for (auto& it : all) cout << it.first << " " << it.second << endl;
//    cout << "------" << endl;
    int l = -1;
    int r = 1e6 + 10;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    check(r);
    cout << r << '\n';
    cout << string(A, 'B') + string(B, 'N');
/*    int best = 1e9;
    for (int i = 0; i <= mx; i++) {
        for (int j = 0; j <= mx; j++) {
            int bb = 0;
            for (auto& it : all) {
                int d1 = it.first - i;
                int d2 = it.second - j;
                bb = max(bb, max({0, d1, d2}) + max({0, -d1, -d2}));
            }
            best = min(best, bb);
        }
    }
    cout << best;*/
    return 0;
}