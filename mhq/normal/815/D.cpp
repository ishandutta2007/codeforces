#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, p, q, r;
const int maxN = 5 * (int)1e5 + 100;
vector < tuple < int, int, int > > all;
vector < pair < int, int > > sec;
int b[maxN], c[maxN];
int le, ri;
ll cur_ans = 0;
ll getAns(int at_leastB, int at_leastC) {
    if (le > ri) {
        return 1LL * (q - at_leastB) * (r - at_leastC);
    }
    return cur_ans + 1LL * (b[le] - at_leastB) * (r - c[le]) + 1LL * (q - b[ri]) * (r - at_leastC);
}
int curA[maxN], curB[maxN], curC[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> p >> q >> r;
    all.resize(n);
    for(auto& t : all) {
        int a, b, c;
        cin >> a >> b >> c;
        t = tie(a, b, c);
        sec.emplace_back(b, c);
    }
    sort(all.begin(), all.end());
    for (int i = 1; i <= n; i++) {
        curA[i] = get<0>(all[i - 1]);
        curB[i] = get<1>(all[i - 1]);
        curC[i] = get<2>(all[i - 1]);
    }
    sort(sec.begin(), sec.end());
    vector < pair < int, int > > sec_sort;
    for (auto it : sec) {
        while (!sec_sort.empty() && sec_sort.back().second <= it.second) {
            sec_sort.pop_back();
        }
        sec_sort.emplace_back(it);
    }
    int tot = sec_sort.size();
    le = 1;
    ri = tot;
    for (int i = 1; i <= tot; i++) {
        b[i] = sec_sort[i - 1].first;
        c[i] = sec_sort[i - 1].second;
    }
    for (int i = 1; i + 1 <= tot; i++) {
        cur_ans += 1LL * (b[i + 1] - b[i]) * (r - c[i + 1]);
    }
    ll ans = 0;
    int mxB = 0;
    int mxC = 0;
    ans += 1LL * (p - curA[n]) * getAns(0, 0);
    for (int i = n; i >= 1; i--) {
        mxB = max(mxB, curB[i]);
        mxC = max(mxC, curC[i]);
        while (mxB >= b[le] && le <= ri) {
            if (le < ri) cur_ans -= 1LL * (b[le + 1] - b[le]) * (r - c[le + 1]);
            le++;
        }
        while (mxC >= c[ri] && le <= ri) {
            if (le < ri) cur_ans -= 1LL * (b[ri] - b[ri - 1]) * (r - c[ri]);
            ri--;
        }
        ans += 1LL * (curA[i] - curA[i - 1]) * getAns(mxB, mxC);
    }
    cout << ans;
    return 0;
}