// https://atcoder.jp/contests/arc114/submissions/20953290

#include <bits/extc++.h>

template <typename K, typename V, typename Comp = std::less<K>>
using order_statistic_map = __gnu_pbds::tree<
	K, V, Comp,
	__gnu_pbds::rb_tree_tag,
	__gnu_pbds::tree_order_statistics_node_update
>;

template <typename K, typename Comp = std::less<K>>
using order_statistic_set = order_statistic_map<K, __gnu_pbds::null_type, Comp>;

// Supports
//  auto iterator = order_statistic_set().find_by_order(idx); // (0-indexed)
//  int num_strictly_smaller = order_statistic_set().order_of_key(key);

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> A(N); for (int &a : A) cin >> a;

        int64_t ans = 0;
        { // 11..1100..00
            int64_t pref = 0;
            int64_t suff = 0;
            for (int i = 0; i < N; ++i) suff += A[i];
            ans += (pref > suff);

            for (int i = 0; i < N; ++i) {
                pref += A[i];
                suff -= A[i];
                ans += (pref > suff);
            }
        }
        for (int ft = 0; ft < 2; ++ft) {
            for (int lt = 0; lt < 2; ++lt) {
                int st = ft;
                int en = N - (!lt);
                if (en - st < 2) continue;

                /*
                int len = en - st - 2;
                for (int r0 = 0; r0 <= len; ++r0) {
                    for (int r1 = 0; r0+r1 <= len; ++r1) {
                        if ((len - r0 - r1) % 2) continue;
                        int64_t sum = 0;
                        if (ft) sum += A[0];
                        if (!lt) sum -= A[N-1];
                        sum -= A[st];
                        sum += A[en-1];
                        for (int i = st+1; i <= st+r0; ++i) sum -= A[i];
                        for (int i = en-r1-1; i <= en-2; ++i) sum += A[i];
                        for (int i = st+r0+1; i <= en-r1-2; ++i) {
                            if ((i - st-r0) & 1) sum += A[i];
                            else sum -= A[i];
                        }
                        ans += (sum > 0);
                    }
                }
                */

                for (int r0 = 0; r0 < 2; ++r0) {
                    if (r0 > en - st - 2) continue;
                    int r1 = (en - st - 2 - r0) & 1;

                    int64_t base = 0;
                    if (ft) base += A[0];
                    if (!lt) base -= A[N-1];
                    base -= A[st];
                    base += A[en-1];
                    vector<int64_t> pref(N+1);
                    vector<int64_t> suff(N+1);
                    for (int i = st+1; i < en-1; ++i) {
                        int64_t v = -A[i];
                        if ((i + st + r0) & 1) v = +A[i];
                        pref[i] = -A[i] - v;
                        suff[i] = A[i] - v;
                        base += v;
                    }
                    for (int i = st+1; i < en-1; ++i) {
                        pref[i] += pref[i-1];
                    }
                    for (int i = en-2; i >= st; --i) {
                        suff[i] += suff[i+1];
                    }
                    int s = st+1;
                    if (r0) s++;
                    order_statistic_set<pair<int64_t, int>> st;
                    while (s <= en-1) {
                        st.insert({-pref[s-1], s});
                        ans += st.order_of_key({suff[s] + base, -1e9});
                        s += 2;
                    }
                }
            }
        }
        cout << ans % 998244353 << '\n';
    }
}