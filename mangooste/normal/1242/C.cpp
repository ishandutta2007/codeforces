#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL
#include "./Templates/debug.h"
#else
#define dbg(...)
#endif

#define len(a) int((a).size())
#define all(a) (a).begin(), (a).end()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    vector<vector<int>> a(k);
    map<int, pair<int, int>> where;
    ll sum = 0;
    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;
        a[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            assert(where.find(a[i][j]) == where.end());
            where[a[i][j]] = {i, j};
            sum += a[i][j];
        }
    }

    if (sum % k != 0) {
        cout << "No\n";
        return 0;
    }
    sum /= k;
//    dbg(sum);

    vector<vector<pair<int, int>>> g(k);
    for (int i = 0; i < k; i++) {
        g[i].resize(len(a[i]), {-1, -1});
    }
    for (int i = 0; i < k; i++) {
        ll curSum = accumulate(all(a[i]), 0ll);
        for (int j = 0; j < len(a[i]); j++) {
            ll need = sum - curSum + a[i][j];
            if (where.find(need) == where.end()) continue;
//            dbg(i, j, a[i][j], need, where[need]);
            pair<int, int> cur = where[need];
            if (cur.first == i && cur.second != j) continue;
            g[i][j] = cur;
        }
    }
//    dbg(g);

    const int MASK = (1 << k);
    vector<vector<pair<int, int>>> cycles(MASK);
    vector<vector<pair<int, int>>> prev(k);
    vector<vector<char>> used(k);
    vector<vector<char>> onCycle(k);
    for (int i = 0; i < k; i++) {
        prev[i].resize(len(a[i]), {-1, -1});
        used[i].resize(len(a[i]));
        onCycle[i].resize(len(a[i]));
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < len(a[i]); j++) {
            if (used[i][j]) continue;
            for (pair<int, int> cur{i, j};;) {
//                dbg(cur);
                used[cur.first][cur.second] = 1;
                pair<int, int> nxt = g[cur.first][cur.second];
                if (nxt == pair<int, int>{-1, -1}) break;

                if (used[nxt.first][nxt.second]) {
                    if (onCycle[nxt.first][nxt.second]) break;
//                    dbg("hi");
                    vector<pair<int, int>> way;
                    bool ok = true;
                    set<pair<int, int>> kek;
                    for (; nxt != cur; nxt = g[nxt.first][nxt.second]) {
                        if (kek.find(nxt) != kek.end()) {
                            ok = false;
                            break;
                        }
                        kek.insert(nxt);
//                        dbg(nxt);
                        if (nxt == pair<int, int>{-1, -1}) {
                            ok = false;
                            break;
                        }
                        way.emplace_back(nxt);
                    }
                    if (!ok) break;
                    way.emplace_back(cur);
//                    dbg("hi");

                    set<int> st;
                    int curMask = 0;
                    for (auto [i, j] : way) {
                        ok &= st.find(i) == st.end();
                        st.insert(i);
                        curMask += (1 << i);
                        onCycle[i][j] = 1;
                    }
                    if (ok) cycles[curMask] = way;
                    break;
                }
                prev[nxt.first][nxt.second] = cur;
                cur = nxt;
            }
        }
    }
//    dbg("hi");

    vector<int> par(MASK, -1);
    par[0] = 0;
    for (int mask = 1; mask < MASK; mask++) {
        vector<int> ones;
        for (int i = 0; i < k; i++) {
            if ((mask >> i) % 2) ones.emplace_back(i);
        }
        for (int submask = 0; submask < (1 << len(ones)); submask++) {
            int realSubmask = 0;
            for (int i = 0; i < len(ones); i++) {
                if ((submask >> i) % 2) realSubmask += (1 << ones[i]);
            }
            if (par[realSubmask] == -1) continue;
            if (len(cycles[mask ^ realSubmask]) == 0) continue;

            par[mask] = realSubmask;
            break;
        }
    }

    if (par.back() == -1) {
        cout << "No\n";
        return 0;
    }

    vector<pair<int, int>> take(k, {-1, -1});
    for (int mask = MASK - 1; mask; mask = par[mask]) {
//        dbg(mask);
        int curMask = (mask ^ par[mask]);
//        dbg(curMask);
//        assert(len(cycles[curMask]));
//        dbg(cycles[curMask]);
        for (int i = 0; i < len(cycles[curMask]); i++) {
            int j = (i + len(cycles[curMask]) - 1) % len(cycles[curMask]);
            take[cycles[curMask][i].first].first = cycles[curMask][i].second;
            take[cycles[curMask][i].first].second = cycles[curMask][j].first;
        }
//        dbg(take);
    }
//    dbg(take);

    vector<ll> sums(k, 0);
    for (int i = 0; i < k; i++) {
        sums[i] += accumulate(all(a[i]), 0ll);
        sums[i] -= a[i][take[i].first];
        sums[take[i].second] += a[i][take[i].first];
    }
    for (int i = 0; i < k; i++) {
        if (sums[i] != sum) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    for (int i = 0; i < k; i++) {
//        assert(take[i].first < len(a[i]));
        cout << a[i][take[i].first] << ' ' << take[i].second + 1 << '\n';
    }
}