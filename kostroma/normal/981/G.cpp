#pragma comment(linker, "/STACK:512000000")
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(__attribute__((unused)) bool);
void precalc();
clock_t start;
#define FILENAME ""

int main() {
#ifdef AIM
    string s = FILENAME;
//    assert(!s.empty());
    freopen("/home/alexandero/ClionProjects/cryptozoology/input.txt", "r", stdin);
#else
//    freopen(FILENAME ".in", "r", stdin);
//    freopen(FILENAME ".out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;
#ifndef AIM
    cout.sync_with_stdio(0);
    cin.tie(0);
#endif
    precalc();
    cout.precision(10);
    cout << fixed;
    //cin >> t;
    int testNum = 1;
    while (t--) {
        //cout << "Case #" << testNum++ << ": ";
        solve(true);
    }
    cout.flush();
#ifdef AIM1
    while (true) {
      solve(false);
  }
#endif

#ifdef AIM
    cout.flush();
    auto end = clock();

    usleep(10000);
    print_stats(end - start);
    usleep(10000);
#endif

    return 0;
}

template<typename T>
T binpow(T q, T w, T mod) {
    if (!w)
        return 1 % mod;
    if (w & 1)
        return q * 1LL * binpow(q, w - 1, mod) % mod;
    return binpow(q * 1LL * q % mod, w / 2, mod);
}

template<typename T>
T gcd(T q, T w) {
    while (w) {
        q %= w;
        swap(q, w);
    }
    return q;
}
template<typename T>
T lcm(T q, T w) {
    return q / gcd(q, w) * w;
}

template <typename T>
void make_unique(vector<T>& a) {
    sort(all(a));
    a.erase(unique(all(a)), a.end());
}

template<typename T>
void relax_min(T& cur, T val) {
    cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
    cur = max(cur, val);
}

void precalc() {
}

//#define int li
const li mod = 998244353;

struct Node {
    li sum;
    li mult;
    li add;
    int size;
    Node() : sum(0), mult(1), add(0) {}
};

li mult(li q, li w) {
    return q * w % mod;
}

Node merge(const Node& q, const Node& w) {
    Node res = Node();
    res.sum = (q.sum + w.sum) % mod;
    res.size = (q.size + w.size);
    return res;
}

struct SegTree {
    int shift;
    vector<Node> tree;
    SegTree(int n) {
        shift = 1;
        while (shift < n) {
            shift *= 2;
        }
        tree.assign(2 * shift, Node());
        for (int i = 0; i < n; ++i) {
            tree[i + shift].size = 1;
        }
        for (int i = shift - 1; i >= 0; --i) {
            tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
        }
    }
    void push(int v) {
        Node& cur = tree[v];
        for (int h = 0; h < 2; ++h) {
            Node& child = tree[2 * v + h];
            child.mult = mult(child.mult, cur.mult);
            child.add = (child.add * cur.mult + cur.add) % mod;
            child.sum = (child.sum * cur.mult + cur.add * child.size) % mod;
        }
        cur.mult = 1;
        cur.add = 0;
    }
    void modify(int v, int tl, int tr, int l, int r, bool inc) {
        if (r <= tl || tr <= l) {
            return;
        }
        if (l <= tl && tr <= r) {
            Node& cur = tree[v];
            if (inc) {
                cur.sum = (cur.sum + cur.size) % mod;
                ++cur.add;
            } else {
                cur.sum = cur.sum * 2 % mod;
                cur.mult = cur.mult * 2 % mod;
                cur.add = cur.add * 2 % mod;
            }
            return;
        }
        push(v);
        int tm = (tl + tr) / 2;
        modify(2 * v, tl, tm, l, r, inc);
        modify(2 * v + 1, tm, tr, l, r, inc);
        tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
    }
    void update(int l, int r, bool inc) {
        return modify(1, 0, shift, l, r, inc);
    }
    li rmq(int v, int tl, int tr, int l, int r) {
        if (r <= tl || tr <= l) {
            return 0;
        }
        if (l <= tl && tr <= r) {
            return tree[v].sum;
        }
        push(v);
        int tm = (tl + tr) / 2;
        return (rmq(2 * v, tl, tm, l, r) + rmq(2 * v + 1, tm, tr, l, r)) % mod;
    }
    li get_res(int l, int r) {
        return rmq(1, 0, shift, l, r);
    }
};

void solve(__attribute__((unused)) bool read) {
    //read = false;
    int n, Q;
    if (read) {
        cin >> n >> Q;
    } else {
        n = 200000;
        Q = 200000;
    }
    SegTree tree(n);
    map<int, set<pair<int, int>>> segs;
    while (Q--) {
        int type, l, r;
        if (read) {
            cin >> type >> l >> r;
        } else {
            type = rand() % 5;
            if (type == 0) {
                type = 2;
            } else {
                type = 1;
            }
            do {
                l = ((rand() << 16) | rand()) % n + 1;
                r = ((rand() << 16) | rand()) % n + 1;
            } while (l > r);
        }
        --l;
        if (type == 1) {
            int x;
            if (read) {
                cin >> x;
            } else {
                x = ((rand() << 16) | rand()) % n + 1;
            }
            set<pair<int, int>>& cur_set = segs[x];
            auto cur_it = cur_set.lower_bound(make_pair(l, l));
            if (cur_it != cur_set.begin() && prev(cur_it)->second > l) {
                cur_it = prev(cur_it);
            }
            vector<pair<int, int>> cur_segs;
            while (cur_it != cur_set.end() && cur_it->first < r) {
                cur_segs.push_back(*cur_it);
                cur_it = cur_set.erase(cur_it);
            }
            if (cur_segs.empty()) {
                cur_set.insert({l, r});
                tree.update(l, r, true);
                continue;
            }
            int finalL = min(cur_segs[0].first, l);
            int finalR = max(cur_segs.back().second, r);
            cur_set.insert({finalL, finalR});
            for (auto item : cur_segs) {
                item.first = max(item.first, l);
                item.second = min(item.second, r);
                tree.update(item.first, item.second, false);
            }
            for (int i = 0; i + 1 < cur_segs.size(); ++i) {
                int curL = cur_segs[i].second, curR = cur_segs[i + 1].first;
                tree.update(curL, curR, true);
            }
            if (l < cur_segs[0].first) {
                tree.update(l, cur_segs[0].first, true);
            }
            if (cur_segs.back().second < r) {
                tree.update(cur_segs.back().second, r, true);
            }
        } else {
            cout << tree.get_res(l, r) << "\n";
        }
    }
}