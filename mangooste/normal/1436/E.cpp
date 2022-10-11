#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

#define len(a) int(a.size())
#define all(a) (a).begin(), (a).end()

template<const int B>
struct SqrtDecomposition {
    int n;
    int nb;

    vector<int> mod;
    vector<int> mn;
    vector<int> a;

    SqrtDecomposition(int n) : n(n), nb(n / B + 1) {
        mod.resize(nb, -1);
        mn.resize(nb, n);
        a.resize(n, n);
    }

    int getMin(int l, int r) {
        int curmn = n;
        for (; l < r && l % B; l++) {
            curmn = min(curmn, max(mod[l / B], a[l]));
        }
        for (; l + B <= r; l += B) {
            curmn = min(curmn, max(mn[l / B], mod[l / B]));
        }
        for (; l < r; l++) {
            curmn = min(curmn, max(mod[l / B], a[l]));
        }
        return curmn;
    }

    void recalc(int bl) {
        if (bl < 0 || bl >= nb) return;

        int l = bl * B;
        int r = min(n, l + B);
        mn[bl] = n;
        for (int i = l; i < r; i++) {
            a[i] = max(a[i], mod[bl]);
            mn[bl] = min(mn[bl], a[i]);
        }
        mod[bl] = -1;
    }

    void update(int l, int r, int inc) {
        for (; l < r && l % B; l++) {
            a[l] = max(a[l], inc);
        }
        int b1 = l / B - 1;
        for (; l + B <= r; l += B) {
            mod[l / B] = max(mod[l / B], inc);
        }
        for (; l < r; l++) {
            a[l] = max(a[l], inc);
        }
        int b2 = l / B;

        recalc(b1);
        if (b2 != b1) recalc(b2);
    }

    void update(int pos, int val) {
        int bl = pos / B;
        int l = bl * B;
        int r = min(n, l + B);
        mn[bl] = n;
        for (int i = l; i < r; i++) {
            a[i] = max(a[i], mod[bl]);
        }
        a[pos] = val;
        for (int i = l; i < r; i++) {
            mn[bl] = min(mn[bl], a[i]);
        }
        mod[bl] = -1;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> poses(n + 1);
    for (int i = 0; i < n + 1; i++) {
        poses[i].emplace_back(-1);
    }
    bool allOne = true;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        allOne &= x == 1;
        poses[x - 1].emplace_back(i);
    }
    for (int i = 0; i < n + 1; i++) {
        poses[i].emplace_back(n);
    }

    SqrtDecomposition<128> deco(n);
    for (int i = 0; i < n + 1; i++) {
        bool any = false;
        for (int j = 0; j < len(poses[i]) - 1; j++) {
            int cur = poses[i][j];
            if (poses[i][j + 1] == cur) continue;
            if (deco.getMin(cur + 1, poses[i][j + 1]) < poses[i][j + 1]) {
                any = true;
                break;
            }
        }
        if (!any && (i || allOne)) {
            cout << i + 1 << '\n';
            return 0;
        }

        for (int j = 1; j < len(poses[i]) - 1; j++) {
            int from = poses[i][j - 1] + 1;
            int cur = poses[i][j];
            deco.update(from, cur, cur);
            int mn = deco.getMin(cur + 1, n);
            if (!i) mn = cur;
            deco.update(cur, mn);
        }
//        dbg(i);
        deco.update(poses[i].end()[-2] + 1, n, n);
    }
    cout << n + 2 << '\n';
}