#include <algorithm>
#include <array>
#include <cassert>
#include <functional>
#include <iostream>
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

template<class T, class Comp = less<T>>
struct SparseTable {
    Comp cmp;
    vector<vector<T>> sparse;
    vector<int> largestBit;

    inline T best(const T &a, const T &b) {
        return cmp(a, b) ? a : b;
    }

    SparseTable() {}
    explicit SparseTable(vector<T> a) {
        int n = int(a.size());
        largestBit.resize(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            largestBit[i] = largestBit[i / 2] + 1;
        }

        sparse.resize(largestBit.back() + 1, vector<T>(n));
        for (int i = 0; i < n; i++) {
            sparse[0][i] = a[i];
        }
        for (int level = 0; level < largestBit.back(); level++) {
            for (int i = 0; i + (1 << (level + 1)) <= n; i++) {
                sparse[level + 1][i] = best(sparse[level][i], sparse[level][i + (1 << level)]);
            }
        }
    }

    inline T get(int l, int r) { // [l, r)
        assert(l < r);
        int level = largestBit[r - l];
        return best(sparse[level][l], sparse[level][r - (1 << level)]);
    }
};

template<class T, class Comp = less<T>>
struct Farakh {
    Comp cmp;
    SparseTable<T, Comp> sparse;
    vector<int> mask;
    vector<T> values;
    vector<int> lowestBit;
    int log;

    inline T best(const T &a, const T &b) {
        return cmp(a, b) ? a : b;
    }

    inline void bestInPlace(T &a, const T &b) {
        a = cmp(a, b) ? a : b;
    }

    Farakh() {}
    explicit Farakh(vector<T> a) : values(a) {
        int n = int(a.size());
        lowestBit.resize((n << 1) + 2);
        for (int i = 1; i <= (n << 1) + 1; i++) {
            if (i & 1) lowestBit[i] = 0;
            else lowestBit[i] = lowestBit[i >> 1] + 1;
        }

        log = 0;
        while ((1 << log) < n) log++;

        vector<T> mins;
        for (int i = 0; i < n; i += log) {
            T mn = a[i];
            for (int j = i + 1; j < i + log && j < n; j++) {
                bestInPlace(mn, a[j]);
            }
            mins.emplace_back(mn);
        }
        sparse = SparseTable<T, Comp>(mins);

        mask.resize(n);
        vector<pair<T, int>> st;
        st.reserve(log);
        for (int i = 0; i < n; i += log) {
            st.resize(0);
            int curMask = 0;
            for (int j = i; j < i + log && j < n; j++) {
                while (st.size() && !cmp(st.back().first, a[j])) {
                    curMask ^= (1 << st.back().second);
                    st.pop_back();
                }
                st.emplace_back(a[j], j - i);
                curMask ^= (1 << (j - i));
                mask[j] = curMask;
            }
        }
    }

    inline T getBlockMin(int st, int l, int r) {                                    // [l, r)
        assert(l < r);
        return values[st + lowestBit[(mask[r - 1] >> (l - st)) << (l - st)]];
    }

    inline T get(int l, int r) {                                                     // [l, r)
        assert(l < r);
        int bl = l / log, br = r / log;
        T res = getBlockMin(bl * log, l, min(r, (bl + 1) * log));
        if (br * log != r) bestInPlace(res, getBlockMin(br * log, max(l, br * log), r));
        if (bl + 1 < br) bestInPlace(res, sparse.get(bl + 1, br));
        return res;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &el : a) {
        cin >> el;
    }
    sort(a.begin(), a.end());
    vector<int> left(n, 0);
    for (int i = 1; i < n; i++) {
        left[i] = left[i - 1];
        while (left[i] < i && a[i] - a[left[i]] > 5) {
            left[i]++;
        }
    }
    vector<vector<int>> dp(n, vector<int>(k, 0));
    for (int i = 0; i < n; i++) {
        dp[i][0] = i - left[i] + 1;
    }
    Farakh<int, greater<>> sp;
    vector<int> for_bld(n);
    for (int j = 1; j < k; j++) {
        for (int i = 0; i < n; i++) {
            for_bld[i] = dp[i][j - 1] - i;
        }
        sp = Farakh<int, greater<>>(for_bld);
        for (int i = 0; i < n; i++) {
            if (left[i] != i) {
                dp[i][j] = max(dp[i][j], sp.get(left[i], i) + i);
            }
        }
        vector<int> pref(n);
        pref[0] = dp[0][j - 1];
        for (int i = 1; i < n; i++) {
            pref[i] = max(pref[i - 1], dp[i][j - 1]);
        }
        for (int i = 0; i < n; i++) {
            dp[i][j] = i - left[i] + 1;
            if (left[i] != 0) {
                dp[i][j] += pref[left[i] - 1];
            }
        }
    }
    int ans = *max_element(dp[0].begin(), dp[0].end());
    for (int i = 0; i < n; i++) {
        ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
    }
    cout << ans << '\n';
}