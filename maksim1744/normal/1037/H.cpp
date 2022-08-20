/*
    author:  Maksim1744
    created: 11.05.2021 02:51:35
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
#include "C:/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

// O(n*log)
vector<int> build_suf_array(string s, bool add_dollar = true) {
    if (add_dollar)
        s += '$';
    int n = s.size();
    vector<pair<int, int>> cur(s.size());
    for (int i = 0; i < s.size(); ++i) {
        cur[i] = make_pair(i, 0);
    }
    sort(cur.begin(), cur.end(), [&](const pair<int, int> &a, const pair<int, int> &b) {
        return s[a.first] < s[b.first];
    });
    for (int i = 1; i < s.size(); ++i) {
        cur[i].second = cur[i - 1].second + (s[cur[i].first] != s[cur[i - 1].first]);
    }
    vector<int> ind(n);
    vector<int> count(n);
    vector<pair<int, int>> tmp(n);
    for (int k = 1; k <= n; k *= 2) {
        for (int i = 0; i < n; ++i) {
            ind[cur[i].first] = cur[i].second;
        }
        for (int i = 0; i < n; ++i) {
            cur[i].first = (cur[i].first - k + n) % n;
            cur[i].second = ind[cur[i].first];
        }
        count.assign(count.size(), 0);
        for (int i = 0; i < n; ++i) {
            count[cur[i].second]++;
        }
        for (int i = 1; i < n; ++i)
            count[i] += count[i - 1];
        for (int i = 0; i < n; ++i)
            --count[i];
        for (int i = n - 1; i >= 0; --i) {
            tmp[count[cur[i].second]--] = make_pair(cur[i].first, 0);
        }
        swap(cur, tmp);
        for (int i = 1; i < n; ++i) {
            cur[i].second = cur[i - 1].second;
            if (ind[cur[i].first] != ind[cur[i - 1].first] || ind[(cur[i].first + k) % n] != ind[(cur[i - 1].first + k) % n])
                ++cur[i].second;
        }
    }
    vector<int> res(n);
    for (int i = 0; i < cur.size(); ++i) {
        res[i] = cur[i].first;
    }

    if (add_dollar)
        res.erase(res.begin());

    return res;
}

struct item {
    vector<int> ar;

    template<typename T>
    void init(const T &t, int l, int r) {
        ar = {t};
        ar.pb(1e9);
    }

    void update(const item &first, const item &second, int l, int r) {
        ar.resize(first.ar.size() - 1 + second.ar.size() - 1);
        std::merge(first.ar.begin(), first.ar.end() - 1, second.ar.begin(), second.ar.end() - 1, ar.begin());
        ar.pb(1e9);
    }

    static item merge(const item &first, const item &second, int l, int r) {
        item res;
        res.update(first, second, l, r);  // careful with different lengths
        return res;
    }
};

string to_string(const item &i) {
    stringstream ss;
    ss << "[" << "]";
    return ss.str();
}
ostream& operator << (ostream &o, const item &i) {
    return o << to_string(i);
}

struct segtree {
    vector<item> tree;
    int n = 1;

    segtree(int n = 1) : n(n) {
        tree.resize(1 << (__lg(n - 1) + 2));
    }

    template<typename T>
    void build(const vector<T> &v, int i, int l, int r) {
        if (l == r) {
            tree[i].init(v[l], l, r);
            return;
        }
        int m = (l + r) >> 1;
        build(v, i * 2 + 1, l, m);
        build(v, i * 2 + 2, m + 1, r);
        tree[i].update(tree[i * 2 + 1], tree[i * 2 + 2], l, r);
    }

    template<typename T>
    void build(const vector<T> &v) {
        n = v.size();
        tree.resize(1 << (__lg(n - 1) + 2));
        build(v, 0, 0, n - 1);
    }

    int ask(int l, int r, int x, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            return *lower_bound(tree[i].ar.begin(), tree[i].ar.end(), x);
        }
        int m = (vl + vr) >> 1;
        if (r <= m) {
            return ask(l, r, x, i * 2 + 1, vl, m);
        } else if (m < l) {
            return ask(l, r, x, i * 2 + 2, m + 1, vr);
        } else {
            return min(ask(l, m, x, i * 2 + 1, vl, m), ask(m + 1, r, x, i * 2 + 2, m + 1, vr));
        }
    }

    int ask(int l, int r, int x) {
        l = max(l, 0); r = min(r, n - 1);
        if (l > r) return 1e9;
        return ask(l, r, x, 0, 0, n - 1);
    }

    template<typename T>
    void set(int ind, const T &t) {
        static array<pair<int, int>, 30> st;
        int l = 0, r = n - 1, i = 0;
        int ptr = -1;
        while (l != r) {
            st[++ptr] = {l, r};
            int m = (l + r) >> 1;
            if (ind <= m) {
                i = i * 2 + 1;
                r = m;
            } else {
                i = i * 2 + 2;
                l = m + 1;
            }
        }
        tree[i].init(t, l, r);
        while (i != 0) {
            i = (i - 1) / 2;
            tree[i].update(tree[i * 2 + 1], tree[i * 2 + 2], st[ptr].first, st[ptr].second);
            --ptr;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string s;
    cin >> s;
    int q;
    cin >> q;

    auto a = build_suf_array(s);
    vector<int> ai(a.size());
    for (int i = 0; i < a.size(); ++i) {
        ai[a[i]] = i;
    }

    segtree tree(a.size());
    tree.build(ai);

    show(a);

    while (q--) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        string x;
        cin >> x;
        int m = r - (int)(x.size() + 2);
        if (m < l) m = l;

        string best;
        for (int i = m; i <= r; ++i) {
            string t = s.substr(i, r - i + 1);
            if (t > x) {
                if (best.empty() || t < best)
                    best = t;
            }
        }

        int ind = 0;
        {
            int L = -1, R = s.size();
            while (R - L > 1) {
                int C = (L + R) / 2;
                int res = -2;
                for (int i = 0; i <= x.size(); ++i) {
                    if (i == x.size()) {
                        if (a[C] + i == s.size()) {
                            res = 0;
                            break;
                        } else {
                            res = -1;
                            break;
                        }
                    }
                    if (a[C] + i == s.size()) {
                        res = 1;
                        break;
                    }
                    if (x[i] != s[a[C] + i]) {
                        res = (x[i] < s[a[C] + i] ? -1 : 1);
                        break;
                    }
                }
                show(C, res);
                assert(res != -2);
                if (res >= 0)
                    L = C;
                else
                    R = C;
            }
            ind = R;
        }
        show(ind);
        ind = tree.ask(l, m - 1, ind);
        show(ind);

        show(best);

        if (ind < s.size()) {
            string t = s.substr(a[ind], min((int)x.size() + 5, r - a[ind] + 1));
            if (best.empty() || best > t)
                best = t;
        }

        show(best);

        if (best.empty()) {
            cout << -1 << '\n';
            continue;
        }

        int dif = 0;
        while (dif < x.size() && dif < best.size() && x[dif] == best[dif])
            ++dif;
        best.resize(dif + 1);
        cout << best << '\n';
    }

    return 0;
}