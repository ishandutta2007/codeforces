/*
    author:  Maksim1744
    created: 13.08.2021 20:42:16
*/

#include "bits/stdc++.h"

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order, order_of_key

using ll = long long;
using ld = long double;

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "/mnt/c/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

template<typename T>
struct fenwick {
    vector<T> tree;
    int n;
    int K;
    vector<int> ops;

    fenwick(int n = 0) : n(n) {
        tree.assign(n, 0);
        K = 0;
        while ((1 << K) < n) ++K;
    }

    void add(int i, T k, bool push = true) {
        if (push)
            ops.pb(i);
        for (; i < n; i = (i | (i + 1)))
            tree[i] += k;
    }

    T ask(int r) {
        T res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            res += tree[r];
        return res;
    }

    T ask(int l, int r) {
        if (l > r) return 0;
        return ask(r) - ask(l - 1);
    }

    // smallest ind such that ind + sum[0..ind] >= v
    int find_ind(int v) {
        int cur = 0;
        int cur_sum = 0;
        for (int k = K - 1; k >= 0; --k) {
            int ind = cur | ((1 << k) - 1);
            if (ind >= n) continue;
            if (cur_sum + tree[ind] + ind >= v) continue;
            cur_sum += tree[ind];
            cur |= (1 << k);
        }
        return cur;
    }

    void undo() {
        for (int k : ops)
            add(k, -1, false);
        ops.clear();
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> b(n);
    cin >> b;
    for (int i = 0; i < n; ++i)
        b[i] = i - b[i];

    const int B = 230;

    vector<fenwick<int>> blocks(n / B + 1);
    for (int i = 0; i < blocks.size(); ++i) {
        blocks[i] = fenwick<int>(n + 1);
    }
    auto upd_block = [&](int ind) {
        auto& s = blocks[ind];
        s.undo();
        int l = ind * B;
        int r = min(n - 1, (ind + 1) * B - 1);

        // ..... | ..... | ..... | .....
        //   0       1       2       3
        //          ^

        for (int j = l; j <= r; ++j) {
            int ind = s.find_ind(b[j]);
            s.add(ind, 1);
        }
    };

    for (int i = 0; i < n; i += B)
        upd_block(i / B);

    int q;
    cin >> q;

    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int i, x;
            cin >> i >> x;
            --i;
            b[i] = i - x;
            upd_block(i / B);
        } else {
            int ind;
            cin >> ind;
            --ind;

            int cur = b[ind];
            ++ind;
            int L = (ind + B - 1) / B;

            for (int j = ind; j < n && j < L * B; ++j)
                if (b[j] <= cur)
                    ++cur;

            for (int b = L; b * B < n; ++b)
                cur += blocks[b].ask(0, cur);

            cout << cur + 1 << '\n';
        }
    }

    return 0;
}