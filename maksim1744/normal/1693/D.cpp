/*
    author:  Maksim1744
    created: 16.06.2022 18:02:15
*/

#include "bits/stdc++.h"

using namespace std;

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
#include "/mnt/c/Libs/tools/print.cpp"
#else
#define show(...) void(0)
#define debugf(fun)   fun
#define debugv(var)   var
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#define OSTREAM(...)    ;
#define OSTREAM0(...)   ;
#endif

namespace segtree {

template<typename Item>
Item tree_merge(const Item& a, const Item& b) {
    Item i;
    i.update(a, b);
    return i;
}

template<typename Item, bool lazy>
struct Pusher {};

template<typename Item>
struct Pusher<Item, false> {
    void push(const vector<Item>&, int, int, int) {}
    Item ask_on_segment(const vector<Item>& tree, int n, int l, int r) {
        l |= n;
        r |= n;
        Item resl, resr;
        while (l <= r) {
            if (l & 1) {
                resl = tree_merge(resl, tree[l]);
                ++l;
            }
            if (!(r & 1)) {
                resr = tree_merge(tree[r], resr);
                --r;
            }
            l >>= 1;
            r >>= 1;
        }
        return tree_merge(resl, resr);
    }
    void push_point(const vector<Item>&, int, int) {}
};

template<typename Item>
struct Pusher<Item, true> {
    void push(vector<Item>& tree, int ind, int l, int r) {
        tree[ind].push(tree[ind * 2], tree[ind * 2 + 1], l, r);
    }

    Item ask_on_segment(vector<Item>& tree, int n, int l, int r) {
        int vl = 0, vr = n - 1;
        int i = 1;
        Item result;
        while (vl != vr) {
            int m = (vl + vr) / 2;
            if (l > m) {
                push(tree, i, vl, vr);
                i = i * 2 + 1;
                vl = m + 1;
            } else if (r <= m) {
                push(tree, i, vl, vr);
                i = i * 2;
                vr = m;
            } else {
                break;
            }
        }
        if (l == vl && r == vr) {
            return tree[i];
        }
        push(tree, i, vl, vr);
        // left
        {
            int ind = i * 2;
            int L = vl, R = (vl + vr) / 2;
            while (l != L) {
                int m = (L + R) / 2;
                push(tree, ind, L, R);
                if (l <= m) {
                    result = tree_merge(tree[ind * 2 + 1], result);
                    ind *= 2;
                    R = m;
                } else {
                    ind = ind * 2 + 1;
                    L = m + 1;
                }
            }
            result = tree_merge(tree[ind], result);
        }
        // right
        {
            int ind = i * 2 + 1;
            int L = (vl + vr) / 2 + 1, R = vr;
            while (r != R) {
                int m = (L + R) / 2;
                push(tree, ind, L, R);
                if (r > m) {
                    result = tree_merge(result, tree[ind * 2]);
                    ind = ind * 2 + 1;
                    L = m + 1;
                } else {
                    ind = ind * 2;
                    R = m;
                }
            }
            result = tree_merge(result, tree[ind]);
        }
        return result;
    }

    void push_point(vector<Item>& tree, int n, int ind) {
        int l = 0, r = n - 1;
        int i = 1;
        while (l != r) {
            push(tree, i, l, r);
            int m = (l + r) / 2;
            if (ind <= m) {
                r = m;
                i *= 2;
            } else {
                l = m + 1;
                i = i * 2 + 1;
            }
        }
    }
};

template<typename Item, bool lazy = false>
struct Segtree {
    vector<Item> tree;
    Pusher<Item, lazy> pusher;
    int n;

    Segtree(int n = 0) {
        build(n);
    }

    template<typename U>
    Segtree(const vector<U>& v) {
        build(v);
    }

    void build(int n) {
        while (n & (n - 1)) ++n;
        this->n = n;
        tree.assign(n * 2, {});
    }

    template<typename U>
    void build(const vector<U>& v) {
        build(v.size());
        for (int i = 0; i < v.size(); ++i) {
            tree[n | i].init(v[i], i);
        }
        build();
    }

    void build() {
        for (int i = n - 1; i >= 1; --i) {
            tree[i].update(tree[i * 2], tree[i * 2 + 1]);
        }
    }

    void push(int ind, int l, int r) {
        pusher.push(tree, ind, l, r);
    }

    template<typename T>
    void set(int ind, const T& t) {
        pusher.push_point(tree, n, ind);
        ind |= n;
        tree[ind].init(t, ind ^ n);
        ind >>= 1;
        while (ind) {
            tree[ind].update(tree[ind * 2], tree[ind * 2 + 1]);
            ind >>= 1;
        }
    }

    template<typename T>
    void update(int ind, const T& t) {
        pusher.push_point(tree, n, ind);
        ind |= n;
        tree[ind].update(t, ind ^ n);
        ind >>= 1;
        while (ind) {
            tree[ind].update(tree[ind * 2], tree[ind * 2 + 1]);
            ind >>= 1;
        }
    }

    Item& ith(int ind) {
        static_assert(!lazy, "don't use this method with lazy propagation, unless you're sure you need it");
        return tree[ind | n];
    }

    const Item& root() const {
        return tree[1];
    }

    Item ask(int l, int r) {
        l = max(l, 0);
        r = min(r, n - 1);
        if (l > r) return {};
        return pusher.ask_on_segment(tree, n, l, r);
    }

    template<typename T>
    void modify(int l, int r, const T& t) {
        static_assert(lazy, "lazy must be set to true to use this function");
        l = max(l, 0);
        r = min(r, n - 1);
        if (l > r) return;
        int vl = 0, vr = n - 1;
        int i = 1;
        while (vl != vr) {
            int m = (vl + vr) / 2;
            if (l > m) {
                push(i, vl, vr);
                i = i * 2 + 1;
                vl = m + 1;
            } else if (r <= m) {
                push(i, vl, vr);
                i = i * 2;
                vr = m;
            } else {
                break;
            }
        }
        if (l == vl && r == vr) {
            tree[i].modify(t, l, r);
        } else {
            push(i, vl, vr);
            // left
            {
                int ind = i * 2;
                int L = vl, R = (vl + vr) / 2;
                while (l != L) {
                    int m = (L + R) / 2;
                    push(ind, L, R);
                    if (l <= m) {
                        tree[ind * 2 + 1].modify(t, m + 1, R);
                        ind *= 2;
                        R = m;
                    } else {
                        ind = ind * 2 + 1;
                        L = m + 1;
                    }
                }
                tree[ind].modify(t, L, R);
                ind >>= 1;
                while (ind != i) {
                    tree[ind].update(tree[ind * 2], tree[ind * 2 + 1]);
                    ind >>= 1;
                }
            }
            // right
            {
                int ind = i * 2 + 1;
                int L = (vl + vr) / 2 + 1, R = vr;
                while (r != R) {
                    int m = (L + R) / 2;
                    push(ind, L, R);
                    if (r > m) {
                        tree[ind * 2].modify(t, L, m);
                        ind = ind * 2 + 1;
                        L = m + 1;
                    } else {
                        ind = ind * 2;
                        R = m;
                    }
                }
                tree[ind].modify(t, L, R);
                ind >>= 1;
                while (ind != i) {
                    tree[ind].update(tree[ind * 2], tree[ind * 2 + 1]);
                    ind >>= 1;
                }
            }
            tree[i].update(tree[i * 2], tree[i * 2 + 1]);
        }
        i >>= 1;
        while (i) {
            tree[i].update(tree[i * 2], tree[i * 2 + 1]);
            i >>= 1;
        }
    }
};

}
using segtree::Segtree;

struct Item {
    int mx = -1;

    template<typename T>
    void init(const T& t, int ind) {
        mx = t;
    }

    void update(const Item& a, const Item& b) {
        mx = max(a.mx, b.mx);
    }

    //// similar to init, but more convenient for doing a[i] += x, implement only if needed
    // template<typename T> void update(const T& t, int ind) {}

    //// apply here, save for children
    // template<typename T> void modify(const T& m, int l, int r) {}

    // void push(Item& a, Item& b, int l, int r) {
    //     int m = (l + r) / 2;
    //     a.modify(mod, l, m);
    //     b.modify(mod, m + 1, r);
    //     // reset mod
    // }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> p(n);
    cin >> p;
    --p;
    show(p);

    vector<int> prev_less(n, -1), next_less(n, n);
    vector<int> prev_greater(n, -1), next_greater(n, n);
    {
        vector<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && p[st.back()] > p[i])
                st.pop_back();
            if (!st.empty())
                prev_less[i] = st.back();
            st.pb(i);
        }
    }
    {
        vector<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && p[st.back()] < p[i])
                st.pop_back();
            if (!st.empty())
                prev_greater[i] = st.back();
            st.pb(i);
        }
    }
    {
        vector<int> st;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && p[st.back()] > p[i])
                st.pop_back();
            if (!st.empty())
                next_less[i] = st.back();
            st.pb(i);
        }
    }
    {
        vector<int> st;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && p[st.back()] < p[i])
                st.pop_back();
            if (!st.empty())
                next_greater[i] = st.back();
            st.pb(i);
        }
    }

    ll ans = 0;

    map<pair<int, int>, int> ans1;
    map<pair<int, int>, int> ans2;

    {
        vector<pair<int, int>> que1;
        vector<vector<int>> segs(n + 1);
        for (int i = 0; i < n; ++i) {
            segs[next_less[i]].pb(i);
        }
        Segtree<Item> tree(n);
        for (int i = 0; i < n; ++i) {
            if (prev_greater[i] <= 0) continue;
            que1.eb(prev_greater[i] - 1, p[i]);
        }

        sort(que1.begin(), que1.end());
        int it = 0;

        for (int i = 0; i < n; ++i) {
            for (int ind : segs[i]) {
                tree.set(p[ind], ind);
            }

            while (it < que1.size() && que1[it].first == i) {
                ans1[que1[it]] = tree.ask(0, que1[it].second).mx;
                ++it;
            }
        }
    }
    {
        vector<pair<int, int>> que1;
        vector<vector<int>> segs(n + 1);
        for (int i = 0; i < n; ++i) {
            segs[next_greater[i]].pb(i);
        }
        Segtree<Item> tree(n);
        for (int i = 0; i < n; ++i) {
            if (prev_less[i] <= 0) continue;
            que1.eb(prev_less[i] - 1, p[i]);
        }

        sort(que1.begin(), que1.end());
        int it = 0;

        for (int i = 0; i < n; ++i) {
            for (int ind : segs[i]) {
                tree.set(p[ind], ind);
            }

            while (it < que1.size() && que1[it].first == i) {
                ans2[que1[it]] = tree.ask(que1[it].second, n - 1).mx;
                ++it;
            }
        }
    }

    show(prev_less);
    show(next_greater);
    show(ans2);

    auto ok1 = [&](int l, int r) {
        pair<int, int> q = {prev_greater[r] - 1, p[r]};
        if (!ans1.count(q)) return true;
        return ans1[q] < l;
    };

    auto ok2 = [&](int l, int r) {
        pair<int, int> q = {prev_less[r] - 1, p[r]};
        if (!ans2.count(q)) return true;
        return ans2[q] < l;
    };

    auto ok = [&](int l, int r) {
        return ok1(l, r) && ok2(l, r);
    };

    int r = 0;
    for (int l = 0; l < n; ++l) {
        while (r + 1 < n && ok(l, r + 1))
            ++r;
        show(l, r);
        ans += r - l + 1;
    }

    cout << ans << '\n';

    return 0;
}