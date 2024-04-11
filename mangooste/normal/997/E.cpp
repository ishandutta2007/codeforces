#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

template<typename Fun>
class y_combinator {
    const Fun fun_;
public:
    explicit y_combinator(const Fun&& fun) : fun_(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    decltype(auto) operator()(Args&&... args) const {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template<typename T>
struct binary_indexed_tree {
    std::vector<T> bit;

    binary_indexed_tree(int n = 0, T value = 0) : bit(n + 1) {
        for (int i = 1; i <= n; i++)
            bit[i] = value * (i & -i);
    }

    void add(int pos, T delta) {
        for (pos++; pos < int(bit.size()); pos += pos & -pos)
            bit[pos] += delta;
    }

    T query(int pref) {
        T sum = 0;
        for (pref++; pref > 0; pref -= pref & -pref)
            sum += bit[pref];

        return sum;
    }

    T query(int l, int r) {
        if (r >= int(bit.size()))
            r = int(bit.size()) - 1;

        if (l < 0)
            l = 0;

        if (r <= l)
            return 0;

        return query(r - 1) - query(l - 1);
    }
};

struct query {
    int l, r, id;
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> perm(n);
    for (auto &x : perm) {
        cin >> x;
        x--;
    }

    vector<vector<query>> queries(4 * n);
    vector<int> l(4 * n);
    vector<int> r(4 * n);
    vector<int> leaf_id(n);

    y_combinator([&](auto build, int v, int vl, int vr) -> void {
        l[v] = vl;
        r[v] = vr;
        if (vr - vl == 1) {
            leaf_id[vl] = v;
            return;
        }

        int vm = (vl + vr) >> 1;
        build(v << 1, vl, vm);
        build(v << 1 | 1, vm, vr);
    })(1, 0, n);

    auto lca = [&](int v, int u) {
        auto is_parent = [&](int v, int u) {
            return l[v] <= l[u] && r[u] <= r[v];
        };
        while (!is_parent(v, u))
            v >>= 1;

        return v;
    };

    int q;
    cin >> q;
    vector<ll> answer(q);

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        queries[lca(leaf_id[l], leaf_id[r])].push_back({l, r, i});
    }

    vector<ll> right(n);
    vector<ll> left(n);

    vector<int> pref_max(n);
    vector<int> pref_min(n);
    vector<int> suf_max(n);
    vector<int> suf_min(n);

    vector<int> left_limit(n);
    vector<int> right_limit(n);
    vector<pair<int, int>> left_segs(n);
    vector<pair<int, int>> right_segs(n);

    vector<map<int, vector<int>>::iterator> it_left(n);
    vector<map<int, vector<int>>::iterator> it_right(n);

    vector<ll> suf_right(n + 1);
    vector<ll> pref_left(n + 1);

    binary_indexed_tree<int> bit(n);
    vector<vector<pair<int, int>>> events1(n);
    vector<vector<int>> events2(n);

    y_combinator([&](auto solve, int v, int vl, int vr) -> void {
        if (vr - vl == 1) {
            right[vl]++;
            left[vl]++;
            for (const auto &[l, r, id] : queries[v])
                answer[id]++;

            return;
        }

        int vm = (vl + vr) >> 1;
        solve(v << 1, vl, vm);
        solve(v << 1 | 1, vm, vr);

        suf_right[vm] = 0;
        for (int i = vm - 1; i >= vl; i--)
            suf_right[i] = suf_right[i + 1] + right[i];

        pref_left[vm - 1] = 0;
        for (int i = vm; i < vr; i++)
            pref_left[i] = pref_left[i - 1] + left[i];

        for (auto &[l, r, id] : queries[v]) {
            answer[id] += suf_right[l];
            answer[id] += pref_left[r];
        }

        for (int rot : {0, 1}) {
            suf_max[vm - 1] = suf_min[vm - 1] = perm[vm - 1];
            for (int i = vm - 2; i >= vl; i--) {
                suf_max[i] = max(perm[i], suf_max[i + 1]);
                suf_min[i] = min(perm[i], suf_min[i + 1]);
            }

            pref_max[vm] = pref_min[vm] = perm[vm];
            for (int i = vm + 1; i < vr; i++) {
                pref_max[i] = max(perm[i], pref_max[i - 1]);
                pref_min[i] = min(perm[i], pref_min[i - 1]);
            }

            for (int i = vl; i < vm; i++) {
                int l = vm - 1, r = vr;
                while (r - l > 1) {
                    int mid = (l + r) >> 1;
                    (pref_max[mid] > suf_max[i] ? r : l) = mid;
                }
                left_limit[i] = l;
            }

            for (int i = vm; i < vr; i++) {
                int l = vl - 1, r = vm;
                while (r - l > 1) {
                    int mid = (l + r) >> 1;
                    (suf_min[mid] < pref_min[i] ? l : r) = mid;
                }
                right_limit[i] = r;
            }

            map<int, vector<int>> left_blocks;
            for (int i = vl; i < vm; i++)
                left_blocks[i + suf_max[i]].push_back(i);

            map<int, vector<int>> rigth_blocks;
            for (int i = vm; i < vr; i++)
                rigth_blocks[i + pref_min[i]].push_back(i);

            for (int i = vl; i < vm; i++) {
                auto it = rigth_blocks.find(i + suf_max[i]);
                it_left[i] = it;
                if (it == rigth_blocks.end()) {
                    left_segs[i] = {0, 0};
                    continue;
                }

                int from = upper_bound(all(it->second), left_limit[i]) - it->second.begin();
                int l = -1, r = from;
                while (r - l > 1) {
                    int mid = (l + r) >> 1;
                    int pos = it->second[mid];
                    (suf_min[i] > pref_min[pos] ? r : l) = mid;
                }
                left_segs[i] = {r, from};
            }

            for (int i = vm; i < vr; i++) {
                auto it = left_blocks.find(i + pref_min[i]);
                it_right[i] = it;
                if (it == left_blocks.end()) {
                    right_segs[i] = {0, 0};
                    continue;
                }

                int from = lower_bound(all(it->second), right_limit[i]) - it->second.begin();
                int l = from - 1, r = len(it->second);
                while (r - l > 1) {
                    int mid = (l + r) >> 1;
                    int pos = it->second[mid];
                    (pref_max[i] < suf_max[pos] ? l : r) = mid;
                }
                right_segs[i] = {from, r};
            }

            if (rot == 0) {
                for (int i = vm - 1; i >= vl; i--) {
                    int j = suf_max[i] - suf_min[i] + i;
                    if (vm <= j && j < vr && pref_max[j] < suf_max[i] && pref_min[j] > suf_min[i]) {
                        events2[i].push_back(j);
                        right[i]++;
                        left[j]++;
                    }
                }

                for (int j = vm; j < vr; j++) {
                    int i = j - pref_max[j] + pref_min[j];
                    if (vl <= i && i < vm && suf_max[i] < pref_max[j] && suf_min[i] > pref_min[j]) {
                        events2[i].push_back(j);
                        right[i]++;
                        left[j]++;
                    }
                }

                for (auto &[l, r, id] : queries[v])
                    events1[l].emplace_back(r, id);

                for (int i = vm - 1; i >= vl; i--) {
                    for (auto x : events2[i])
                        bit.add(x, 1);

                    for (auto &[x, id] : events1[i])
                        answer[id] += bit.query(x);
                }

                for (int i = vl; i < vm; i++) {
                    for (auto x : events2[i])
                        bit.add(x, -1);

                    events1[i].clear();
                    events2[i].clear();
                }
            }

            for (int i = vl; i < vm; i++)
                right[i] += left_segs[i].second - left_segs[i].first;

            for (int i = vm; i < vr; i++)
                left[i] += right_segs[i].second - right_segs[i].first;

            const int B = sqrt(vr - vl);
            sort(all(queries[v]), [&](query &a, query &b) {
                int block_a = (vm - 1 - a.l) / B;
                int block_b = (vm - 1 - b.l) / B;
                if (block_a != block_b)
                    return block_a < block_b;

                return (block_a & 1) ? a.r < b.r : a.r > b.r;
            });

            int current_l = vm;
            int current_r = vm - 1;
            ll current_answer = 0;

            auto update_left = [&](int pos, int coeff) {
                auto it = it_left[pos];
                if (it == rigth_blocks.end())
                    return;

                int limit = upper_bound(all(it->second), current_r) - it->second.begin();
                current_answer += coeff * max(0, min(limit, left_segs[pos].second) - left_segs[pos].first);
            };

            auto update_right = [&](int pos, int coeff) {
                auto it = it_right[pos];
                if (it == left_blocks.end())
                    return;

                int limit = lower_bound(all(it->second), current_l) - it->second.begin();
                current_answer += coeff * max(0, right_segs[pos].second - max(limit, right_segs[pos].first));
            };

            for (auto &[l, r, id] : queries[v]) {
                while (current_l > l)
                    update_left(--current_l, 1);

                while (current_l < l)
                    update_left(current_l++, -1);

                while (current_r < r)
                    update_right(++current_r, 1);

                while (current_r > r)
                    update_right(current_r--, -1);

                answer[id] += current_answer;
            }

            for (int i = vl; i < vr; i++)
                perm[i] = n - 1 - perm[i];
        }
    })(1, 0, n);

    for (auto x : answer)
        cout << x << '\n';
}