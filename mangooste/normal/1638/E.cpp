#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    binary_indexed_tree<ll> bit(n);
    set<array<int, 3>> segs;
    segs.insert({0, n, 0});
    vector<ll> add(n);

    auto add_on_segment = [&](int from, int to, ll delta) {
        bit.add(from, delta);
        bit.add(to, -delta);
    };

    while (q--) {
        string name;
        cin >> name;

        if (name[0] == 'C') {
            int l, r, c;
            cin >> l >> r >> c;
            l--, c--;

            while (true) {
                auto it = segs.lower_bound({l, -1, -1});
                if (it != segs.begin() && (*prev(it))[1] > l)
                    it--;

                if (it == segs.end())
                    break;

                auto [cur_l, cur_r, color] = *it;
                if (cur_l >= r)
                    break;

                add_on_segment(cur_l, cur_r, add[color]);
                segs.erase(it);

                if (cur_l <= l && r <= cur_r) {
                    if (cur_l != l) {
                        add_on_segment(cur_l, l, -add[color]);
                        segs.insert({cur_l, l, color});
                    }
                    if (cur_r != r) {
                        add_on_segment(r, cur_r, -add[color]);
                        segs.insert({r, cur_r, color});
                    }
                    continue;
                }

                int new_l = cur_l < l ? cur_l : r, new_r = cur_r > r ? cur_r : l;
                if (new_l < new_r) {
                    add_on_segment(new_l, new_r, -add[color]);
                    segs.insert({new_l, new_r, color});
                }
            }

            add_on_segment(l, r, -add[c]);
            segs.insert({l, r, c});
        } else if (name[0] == 'A') {
            int c, x;
            cin >> c >> x;
            add[c - 1] += x;
        } else if (name[0] == 'Q') {
            int pos;
            cin >> pos;
            pos--;
            cout << bit.query(pos) + add[(*prev(segs.lower_bound({pos + 1, -1, -1})))[2]] << '\n';
        } else {
            assert(false);
        }
    }
}