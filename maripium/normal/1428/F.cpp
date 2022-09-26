#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    string S; cin >> S;
    int64_t ans = 0;
    auto sum = [&](int l, int r) {
        return int64_t(l+r)*(r-l+1)/2;
    };
    function<void(int, int)> solve = [&](int l, int r) {
        if (l == r) {
            ans += (S[l] == '1');
            return;
        }
        int md = (l+r) >> 1;
        int suff = 0;
        while (md - suff >= l && S[md - suff] == '1') suff ++;
        int pref = 0;
        while (md + 1 + pref <= r && S[md+1+pref] == '1') pref ++;
        vector<int> lcnt(r-l+2);
        vector<int> rcnt(r-l+2);
        int cur = 0;
        int mx = 0;
        for (int i = md; i >= l; --i) {
            if (S[i] == '0') {
                cur = 0;
            } else {
                cur ++;
            }
            mx = max(mx, cur);
            if (i <= md - suff) {
                lcnt[mx] ++;
                int cc = mx - suff;
                cc = min(cc, pref);
                ans += int64_t(mx) * cc;
                // suff + cc + 1 -> suff + pref
                ans += sum(suff+cc+1, suff+pref);
            }
        }
        mx = 0;
        cur = 0;
        for (int i = md+1; i <= r; ++i) {
            if (S[i] == '0') {
                cur = 0;
            } else cur++;
            mx = max(mx, cur);
            if (i >= md+1+pref) {
                rcnt[mx] ++;
                int cc = mx - pref;
                cc = min(cc, suff);
                ans += int64_t(mx) * cc;
                ans += sum(pref+cc+1, pref+suff);
            }
        }
        for (int i = 1; i <= r-l+1; ++i) lcnt[i] += lcnt[i-1];
        for (int i = 1; i <= r-l+1; ++i) rcnt[i] += rcnt[i-1];
        for (int i = 1; i <= r-l+1; ++i) {
            int64_t ways = int64_t(lcnt[i]) * rcnt[i] - int64_t(lcnt[i-1]) * rcnt[i-1];
            ans += ways * max(i, pref + suff);
        }
        ans += int64_t(pref) * (pref+1)/2 * suff;
        ans += int64_t(suff) * (suff+1)/2 * pref;
        solve(l, md); solve(md+1, r);
    };
    solve(0, N-1);
    cout << ans << '\n';
    return 0;
}