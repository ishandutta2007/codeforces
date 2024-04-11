#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int INF = (int)1e9 + 10;
struct sg{
    int n;
    vector < int > t;
    sg(int n) {
        t.resize(4 * n + 5, INF);
    }
    void upd(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            t[v] = val;
            return;
        }
        int tm = (tl + tr) / 2;
        if (pos <= tm) upd(2 * v, tl, tm, pos, val);
        else upd(2 * v + 1, tm + 1, tr, pos, val);
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }
    int get(int v, int tl, int tr, int l, int r) {
        if (l <= tl && tr <= r) return t[v];
        if (r < tl || l > tr) return INF;
        int tm = (tl + tr) / 2;
        return min(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
    }
};
int n;
const int maxN = 3e5 + 10;
int frst[maxN][2];
int lst[maxN][2];
int h[maxN];
int dp[maxN];
vector < int > er[maxN][2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int c = 0; c < 2; c++) {
        vector < pair < int, int > > st;
        st.emplace_back(INF, 0);
        for (int i = 1; i <= n; i++) {
            while (st.back().first < h[i]) st.pop_back();
            lst[i][c] = st.back().second + 1;
            st.emplace_back(h[i], i);
        }
        st.clear();
        st.emplace_back(INF, n + 1);
        for (int i = n; i >= 1; i--) {
            while (st.back().first < h[i]) st.pop_back();
            frst[i][c] = st.back().second - 1;
            st.emplace_back(h[i], i);
        }
        for (int i = 1; i <= n; i++) {
            h[i] *= -1;
        }
    }
    sg c1(n);
    sg c2(n);
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            dp[1] = 0;

        }
        else {
            dp[i] = min(c1.get(1, 1, n, lst[i][0] - 1, i - 1), c2.get(1, 1, n, lst[i][1] - 1, i - 1)) + 1;
        }
        c1.upd(1, 1, n, i, dp[i]);
        c2.upd(1, 1, n, i, dp[i]);
        er[frst[i][0] + 1][0].emplace_back(i);
        er[frst[i][1] + 1][1].emplace_back(i);
        for (int x : er[i][0]) {
            c1.upd(1, 1, n, x, INF);
        }
        for (int x : er[i][1]) {
            c2.upd(1, 1, n, x, INF);
        }
    }
    cout << dp[n];
    return 0;
}