/*
    17.03.2019 21:55:57
*/

#include <bits/stdc++.h>

using namespace std;

struct item;
string to_string(item a);

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

const long long inf = 1e9 + 5;
long double e = 0.000000001;

struct item {
    long long mn = 0, delta = 0, l = 0, r = 0, end_speed = 0, start = 0;
    bool active = false, leaf = false;

    void init(pair< long long, long long >& pr) {
        l = pr.first;
        r = pr.second;
        leaf = true;
    }

    void update(item& a, item& b) {
        l = a.l; r = b.r;
        if (!a.active && !b.active) {
            active = false;
        } else if (!a.active) {
            active = true;
            mn = b.mn;
            delta = b.delta;
            start = b.start;
            end_speed = b.end_speed;
        } else if (!b.active) {
            active = true;
            delta = a.delta + a.end_speed * (b.r - b.l);
            mn = min(a.mn, delta);
            start = a.start;
            end_speed = a.end_speed;
        } else {
            active = true;
            start = a.start;
            delta = a.delta + (b.start - b.l) * a.end_speed + b.delta;
            mn = min(a.mn, b.mn + delta - b.delta);
            end_speed = b.end_speed;
        }
    }

    long double ask(long long v) {
        show(*this, v);
        if (end_speed >= 0) return -1;
        return -(long double)v / (long double)end_speed;
    }
};

item operator + (item a, item b) {
    item c;
    c.update(a, b);
    return c;
}

string to_string(item a) {
    return "[active: " + to_string(a.active) + ", " +
            "mn: " + to_string(a.mn) + ", " +
            "delta: " + to_string(a.delta) + ", " + 
            "(l, r): (" + to_string(a.l) + ", " + to_string(a.r) + "), " +
            "end_speed: " + to_string(a.end_speed) + ", " + 
            "start: " + to_string(a.start) + "]";
}

using T = item;

struct segtree {
    vector< T > tree;
    int n;

    segtree(int size) : n(size), tree(size * 4) {}
    segtree(vector< pair< long long, long long > >& v) : n(v.size()), tree(v.size() * 4) {
        build(v, 0, 0, n - 1);
    }

    void build(vector< pair< long long, long long > >& v, int i, int l, int r) {
        if (l == r) {
            tree[i].init(v[l]);
            return;
        }
        int m = (l + r) / 2;
        build(v, i * 2 + 1, l, m);
        build(v, i * 2 + 2, m + 1, r);
        tree[i].update(tree[2 * i + 1], tree[2 * i + 2]);
    }

    void set(int ind, long long t, long long s, int i, int l, int r) {
        while (l < r) {
            int m = (l + r) / 2;
            if (ind <= m) {
                r = m;
                i = 2 * i + 1;
            } else {
                l = m + 1;
                i = 2 * i + 2;
            }
        }
        tree[i].active = true;
        tree[i].end_speed = s;
        tree[i].delta = s * (tree[i].r - tree[i].l);
        tree[i].mn = min(0ll, tree[i].delta);
        tree[i].start = tree[i].l;
        while (i != 0) {
            i = (i - 1) / 2;
            tree[i].update(tree[2 * i + 1], tree[2 * i + 2]);
        }
    }

    void set(int ind, long long t, long long s) {
        set(ind, t, s, 0, 0, n - 1);
    }

    void erase(int ind) {
        int l = 0, r = n - 1, i = 0;
        while (l < r) {
            int m = (l + r) / 2;
            if (ind <= m) {
                r = m;
                i = 2 * i + 1;
            } else {
                l = m + 1;
                i = 2 * i + 2;
            }
        }
        tree[i].active = false;
        while (i != 0) {
            i = (i - 1) / 2;
            tree[i].update(tree[2 * i + 1], tree[2 * i + 2]);
        }
    }

    void split(int l, int r, int i, int vl, int vr, vector< int >& ans) {
        if (l == vl && r == vr) {
            ans.push_back(i);
            return;
        }
        int m = (vl + vr) / 2;
        if (r <= m) split(l, r, 2 * i + 1, vl, m, ans);
        else if (l > m) split(l, r, 2 * i + 2, m + 1, vr, ans);
        else {
            split(l, m, 2 * i + 1, vl, m, ans);
            split(m + 1, r, 2 * i + 2, m + 1, vr, ans);
        }
    }

    vector< int > split(int l, int r) {
        vector< int > answer;
        split(l, r, 0, 0, n - 1, answer);
        return answer;
    }

    long double ask(int l, int r, long long v) {
        vector< int > ind_ = split(l, r);
        if (v == 0) return tree[ind_[0]].l;
        vector< int > ind;
        for (auto i : ind_)
            if (tree[i].active) ind.push_back(i);
        show(l, r, ind_, ind);
        for (int j = 0; j < ind.size(); ++j) {
            int i = ind[j];
            if (!tree[i].active) continue;
            if (tree[i].mn + v <= 0 || (j + 1 == ind.size() && (tree[i].end_speed < 0 || v == 0))) {
                long double ans = ask_(i, v);
                show(ans);
                if (ans < 0) return -1;
                return ans + tree[i].l;
            }
            else {
                v += tree[i].delta;
                if (j + 1 < ind.size()) {
                    long long v1 = v + (tree[ind[j + 1]].start - tree[i].r) * tree[i].end_speed;
                    if (v1 <= 0)
                        return (long double)tree[i].r + (long double)(v) / (long double)(-tree[i].end_speed);
                    v = v1;
                }
            }
        }
        return -1;
    }

    long double ask_(int i, long long v) {
        show(i, v, tree[i]);
        if (tree[i].leaf) return tree[i].ask(v);
        if (tree[2 * i + 1].active && tree[2 * i + 1].mn + v <= 0 || !tree[2 * i + 2].active)
            return ask_(2 * i + 1, v);
        else {
            show(tree[2*i+1], tree[2*i+2]);
            if (tree[2 * i + 1].active) {
                long long v1 = v + (tree[2 * i + 2].start - tree[2 * i + 1].r) * tree[2 * i + 1].end_speed +
                    tree[2 * i + 1].delta;
                if (v1 <= 0) {
                    show("here");
                    long double ans =  (long double)(tree[2 * i + 1].r - tree[2 * i + 1].l) +
                        (long double)(v + tree[2 * i + 1].delta) / (long double)(-tree[2 * i + 1].end_speed);
                    return ans;
                }
                v = v1;
            }
            long double ans = ask_(2 * i + 2, v);
            // show(i, ans+tree[2*i+1].r-tree[2*i+1].l);
            if (ans < 0) return -1;
            return ans + tree[2 * i + 1].r - tree[2 * i + 1].l;
        }
    }
};

int main() {
    int q;
    cin >> q;
    vector< vector< int > > queries(q);
    vector< long long > times;
    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        queries[i].push_back(type);
        if (type == 1) {
            int t, s;
            cin >> t >> s;
            times.push_back(t);
            queries[i].push_back(t);
            queries[i].push_back(s);
        } else if (type == 2) {
            int t;
            cin >> t;
            times.push_back(t);
            queries[i].push_back(t);
        } else {
            int l, r, v;
            cin >> l >> r >> v;
            times.push_back(l);
            times.push_back(r);
            queries[i].push_back(l);
            queries[i].push_back(r);
            queries[i].push_back(v);
        }
    }
    times.push_back(inf);
    sort(times.begin(), times.end());
    times.erase(unique(times.begin(), times.end()), times.end());
    vector< pair< long long, long long > > tpr;
    for (int i = 0; i + 1 < times.size(); ++i) {
        tpr.emplace_back(times[i], times[i + 1]);
    }
    segtree tr(tpr);
    // show(tpr, tr.tree);
    for (int i = 0; i < q; ++i) {
        if (queries[i][0] == 1) {
            long long t = queries[i][1], s = queries[i][2];
            tr.set(lower_bound(times.begin(), times.end(), t) - times.begin(), t, s);
        } else if (queries[i][0] == 2){
            long long t = queries[i][1];
            tr.erase(lower_bound(times.begin(), times.end(), t) - times.begin());
        } else {
            long long l = queries[i][1]; l = lower_bound(times.begin(), times.end(), l) - times.begin();
            long long r = queries[i][2]; r = lower_bound(times.begin(), times.end(), r) - times.begin();
            long long v = queries[i][3];
            long double ans = tr.ask(l, r, v);
            if (ans > (long double) queries[i][2] + e || ans < 0)
                cout << -1 << '\n';
            else
                cout << setprecision(20) << ans << '\n';
        }
        // for (auto k : tr.tree) {
        //     show(k);
        // }
        // shows;
    }
    return 0;
}