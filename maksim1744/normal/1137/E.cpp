/*
    28.03.2019 14:09:24
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#define TAG_LENGTH 45
#define LR_LEFT left
#define LR_RIGHT right
#define LR_VALUE value
#define LR_SECOND_VALUE mn
#include "C:/C++ libs/print.cpp"
#define showl cout << endl;
#define shows cout << string(5, ' ') + string(TAG_LENGTH, '-') << endl;
#else
#define show(...) 42;
#define showt(...) 42;
#define showl 42;
#define shows 42;
#define print(...) 42;
#define printTree(...) 42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

const long long inf = 1e9l * 1e9l * 4ll;

struct item {
    long long mn = 0;
    long long ind = 0;  // index of minimum
    long long sm = 0;

    item() {}
    item(long long mn, long long ind): mn(mn), ind(ind), sm(0) {}

    auto ask() {
        return mn + sm;
    }

    auto update(item& a, item& b) {
        if (a.ask() <= b.ask()) {  // return left minimum
            mn = a.ask();
            ind = a.ind;
        } else {
            mn = b.ask();
            ind = b.ind;
        }
        return *this;
    }
};

item operator + (item a, item b) {
    return item().update(a, b);
}

item operator + (item a, long long b) {
    item c = a;
    c.mn += b;
    return c;
}

struct segtree {
    vector<item> tree;
    int n;

    segtree(int size) : n(size), tree(size * 4, item()) {
        vector<decltype(item().mn)> v(n, 0);
        build(v, 0, 0, n - 1);
    }
    template<typename InType>
    segtree(vector< InType >& v) : n(v.size()), tree(v.size() * 4) {
        build(v, 0, 0, n - 1);
    }

    template<typename InType>
    void build(vector< InType >& v, int i, int l, int r) {
        if (l == r) {
            tree[i] = item(v[l], l);
            return;
        }
        int m = (l + r) / 2;
        build(v, i * 2 + 1, l, m);
        build(v, i * 2 + 2, m + 1, r);
        tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    }

    template<typename InType>
    void set(int ind, InType k, int i, int vl, int vr) {
        if (vl == vr) {
            tree[i].mn = k - tree[i].sm;
            return;
        }
        int m = (vl + vr) / 2;
        if (ind <= m) set(ind, k - tree[i].sm, 2 * i + 1, vl, m);
        else set(ind, k - tree[i].sm, 2 * i + 2, m + 1, vr);
        tree[i].update(tree[2 * i + 1], tree[2 * i + 2]);
    }

    template<typename InType>
    void set(int ind, InType k) {
        set(ind, k, 0, 0, n - 1);
    }

    template<typename InType>
    void add(int l, int r, InType k, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            tree[i].sm += k;
            return;
        }
        int m = (vl + vr) / 2;
        if (r <= m) add(l, r, k, 2 * i + 1, vl, m);
        else if (l > m) add(l, r, k, 2 * i + 2, m + 1, vr);
        else {
            add(    l, m, k, 2 * i + 1,    vl,  m);
            add(m + 1, r, k, 2 * i + 2, m + 1, vr);
        }
        tree[i].update(tree[2 * i + 1], tree[2 * i + 2]);
    }

    template<typename InType>
    void add(int l, int r, InType k) {
        add(l, r, k, 0, 0, n - 1);
    }

    auto ask(int l, int r, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            return tree[i].ask();
        }
        int m = (vl + vr) / 2;
        if (r <= m)
            return ask(l, r, 2 * i + 1, vl, m) + tree[i].sm;
        if (l > m)
            return ask(l, r, 2 * i + 2, m + 1, vr) + tree[i].sm;
        return min(ask(l, m, 2 * i + 1, vl, m), ask(m + 1, r, 2 * i + 2, m + 1, vr)) + tree[i].sm;
    }

    auto ask(int l, int r) {
        return ask(l, r, 0, 0, n - 1);
    }

    auto ask_item(int l, int r, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            return item(tree[i].ask(), tree[i].ind);
        }
        int m = (vl + vr) / 2;
        if (r <= m)
            return ask_item(l, r, 2 * i + 1, vl, m) + tree[i].sm;
        if (l > m)
            return ask_item(l, r, 2 * i + 2, m + 1, vr) + tree[i].sm;
        return ask_item(l, m, 2 * i + 1, vl, m) + ask_item(m + 1, r, 2 * i + 2, m + 1, vr) + tree[i].sm;
    }

    auto ask_item(int l, int r) {
        return ask_item(l, r, 0, 0, n - 1);
    }

    int find_first_negative(int l, int r, int i, int vl, int vr) {
        // show(l, r, i, vl, vr, tree[i].ask(), tree[2*i+1].ask());
        if (vl == l && vr == r) {
            if (tree[i].ask() <= 0)
                return tree[i].ind;
            else
                return -1;
        }
        int m = (vl + vr) / 2;
        if (r <= m) return find_first_negative(l, r, 2 * i + 1, vl, m);
        // else if (l > m) return find_first_negative(l, r, 2 * i + 2, m + 1, vr);
        else {
            assert(l == vl);
            if (tree[2 * i + 1].ask() <= 0) return tree[2 * i + 1].ind;
            return find_first_negative(m + 1, r, 2 * i + 2, m + 1, vr);
        }
    }

    int find_first_negative(int r) {  // or zero
        return find_first_negative(0, r, 0, 0, n - 1);
    }
};

struct item_sum {
    long long value = 0;
    long long l = 0;
    long long r = 0;
    long long mod_sm = 0;  // modify sum, not sum on [l; r] !!!

    item_sum() {}
    item_sum(long long value, long long l = 0, long long r = 0): value(value), l(l), r(r) {}

    long long ask() {
        return value + mod_sm * (r - l + 1);
    }
};

item_sum operator + (item_sum a, item_sum b) {
    return item_sum(a.ask() + b.ask(), a.l, b.r);
}

struct segtree_sum {
    vector< item_sum > tree;
    int n;

    segtree_sum(int size) : n(size), tree(size * 4, item_sum()) {}
    template<typename InType>
    segtree_sum(vector< InType >& v) : n(v.size()), tree(v.size() * 4) {
        build(v, 0, 0, n - 1);
    }

    template<typename InType>
    void build(vector< InType >& v, int i, int l, int r) {
        if (l == r) {
            tree[i] = item_sum(v[l], l, l);
            return;
        }
        int m = (l + r) / 2;
        build(v, i * 2 + 1, l, m);
        build(v, i * 2 + 2, m + 1, r);
        tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    }

    template<typename InType>
    void set(int ind, InType k, int i, int vl, int vr) {
        if (vl == vr) {
            tree[i].value = k - tree[i].mod_sm;
            return;
        }
        int m = (vl + vr) / 2;
        if (ind <= m) set(ind, k - tree[i].mod_sm, 2 * i + 1, vl, m);
        else set(ind, k - tree[i].mod_sm, 2 * i + 2, m + 1, vr);
        tree[i].value = (tree[2 * i + 1] + tree[2 * i + 2]).value;
    }

    template<typename InType>
    void set(int ind, InType k) {
        set(ind, k, 0, 0, n - 1);
    }

    template<typename InType>
    void add(int l, int r, InType k, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            tree[i].mod_sm += k;
            return;
        }
        int m = (vl + vr) / 2;
        if (r <= m) add(l, r, k, 2 * i + 1, vl, m);
        else if (l > m) add(l, r, k, 2 * i + 2, m + 1, vr);
        else {
            add(    l, m, k, 2 * i + 1,    vl,  m);
            add(m + 1, r, k, 2 * i + 2, m + 1, vr);
        }
        tree[i].value = (tree[2 * i + 1] + tree[2 * i + 2]).value;
    }

    template<typename InType>
    void add(int l, int r, InType k) {
        add(l, r, k, 0, 0, n - 1);
    }

    auto ask(int l, int r, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            return tree[i].ask();
        }
        int m = (vl + vr) / 2;
        if (r <= m)
            return ask(l, r, 2 * i + 1, vl, m) + tree[i].mod_sm * (r - l + 1);
        if (l > m)
            return ask(l, r, 2 * i + 2, m + 1, vr) + tree[i].mod_sm * (r - l + 1);
        return ask(l, m, 2 * i + 1, vl, m) + ask(m + 1, r, 2 * i + 2, m + 1, vr) + tree[i].mod_sm * (r - l + 1);
    }

    auto ask(int l, int r) {
        return ask(l, r, 0, 0, n - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    long long n, m;
    cin >> n >> m;
    segtree_sum tsum(m + 5);
    segtree_sum tkoef(m + 5);
    segtree_sum treal_place(m + 5);
    segtree tree(m + 5);
    tree.set(0, inf);
    set<int> heads{0};
    vector<long long> lens(m + 5, 0);
    lens[0] = n;
    int last = 0;
    int death = -1;
    // vector<long long> start_value(m + 5, 0);
    // vector<long long> real_place(m + 5, 0);
    long long head_plus = 0;
    long long head_added = 0;
    // vector<long long> distance_from_start(m + 5, 0);
    long long first_value = 0;
    auto ask = [&](int i) {
        if (i == 0) return first_value;
        return tsum.ask(i, i) + tkoef.ask(i, i) * (treal_place.ask(i, i) - head_added);
    };
    for (int i = 0; i < m; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            long long k;
            cin >> k;
            death = last;
            head_plus += k;
            head_added += k;
            show(heads, lens);
            for (auto t : heads) {
                if (t != 0)
                    lens[0] += lens[t];
            }
            heads = {0};
            lens[0] += k;
            first_value = 0;
            if (last >= 1)
                treal_place.add(1, last, k);
            // clear all
        } else if (type == 2) {
            long long k;
            cin >> k;
            long long last_i = *--heads.end();
            long long last_value = ask(last_i);
            show(heads, last_value, lens, head_plus, head_added);
            if (last_value > 0) {
                ++last;
                heads.insert(last);
                lens[last] = k;
                // real_place[last] = real_place[last_i] + lens[last_i] + head_plus;
                // long long place = treal_place.ask(last - 1, last - 1) + lens[last - 1]
                treal_place.set(last, treal_place.ask(last - 1, last - 1) + lens[last - 1]);
                // distance_from_start[last] = distance_from_start[last_i] + lens[last_i];
                head_plus = 0;
                long long last_len = lens[last_i];
                // if (last_i == 0) {
                //     last_len += head_added;
                // }
                show(last_len);
                long long need = (last_value + last_len - 1) / last_len;
                tree.set(last, need);
                show(need);
            } else {
                ++last;
                lens[last] = k;
                treal_place.set(last, treal_place.ask(last - 1, last - 1) + lens[last - 1]);
                lens[last_i] += k;
            }
        } else {
            long long b, s;
            cin >> b >> s;
            first_value += b;
            tsum.add(0, last, b + head_added * s);
            tree.add(0, last, -s);
            tkoef.add(0, last, s);
            int ind = tree.find_first_negative(last);
            while (ind != -1) {
#ifdef TAG_LENGTH
                for (int i = 0; i < 5; ++i) {
                    for (int j = i; j <= i; ++j) {
                        cout << "[" << i << " : " << j << "] : ";
                        cout << tree.ask(i, j) << '\n';
                        // cout << tree.ask_item(i, j).ind << '\n';
                    }
                }
                cout << endl;
#endif
                // show(ind, tree.ask(ind,ind));
                if (heads.find(ind) == heads.end()) {
                    tree.set(ind, inf);
                } else {
                    tree.set(ind, inf);
                    auto it = heads.find(ind);
                    if (it != heads.begin()) {
                        showt("here", heads, ind);
                        --it;
                        int prev = *it;
                        ++it;
                        int now = *it;
                        lens[prev] += lens[now];
                        ++it;
                        if (it != heads.end()) {
                            int next = *it;
                            long long last_len = lens[prev];
                            show(prev, now, next);
                            // if (prev == 0)
                            //     last_len += head_added;
                            long long need = (ask(prev) - ask(next) + last_len - 1) / last_len;
                            tree.set(next, need);
                        }
                    }
                    // recalc for next
                    heads.erase(ind);
                }
                ind = tree.find_first_negative(last);
            }
        }
        show(heads, lens);
        cout << treal_place.ask(*--heads.end(), *--heads.end()) + 1 << ' ' << ask(*--heads.end()) << '\n';
    }
    return 0;
}