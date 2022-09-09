#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
int main() {
#ifdef AIM
    freopen("/home/alexandero/ClionProjects/cryptozoology/input.txt", "r", stdin);
  //freopen("/home/alexandero/CLionProjects/ACM/output.txt", "w", stdout);
  //freopen("out.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;
#ifndef AIM
    cout.sync_with_stdio(0);
    cin.tie(0);
#endif
    cout.precision(20);
    cout << fixed;
    //cin >> t;
    precalc();
    while (t--) {
        solve(true);
    }
    cout.flush();

#ifdef AIM1
    while (true) {
      solve(false);
  }
#endif

#ifdef AIM
    cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif
    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

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
void make_unique(vector<T>& vec) {
    sort(all(vec));
    vec.erase(unique(all(vec)), vec.end());
}

template<typename T>
void relax_min(T& cur, T val) {
    cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
    cur = max(cur, val);
}



//#define int li
const li mod = 1000000007;

//using ull = unsigned long long;

const int C = 10000500;
int lp[C];

void precalc() {
    vector<int> pr;
    for (int i=2; i<C; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]< C; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

const int L = 17;
vector<vector<int>> g;
vector<int> tin, tout;
int TIMER = 0;
vector<vector<int>> parent;

void dfs1(int v, int p) {
    parent[0][v] = p;
    tin[v] = TIMER++;
    for (int i = 1; i < L; ++i) {
        parent[i][v] = parent[i - 1][parent[i - 1][v]];
    }
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs1(to, v);
    }
    tout[v] = TIMER;
}

bool upper(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b) {
    if (upper(a, b)) {
        return a;
    }
    for (int i = L - 1; i >= 0; --i) {
        if (!upper(parent[i][a], b)) {
            a = parent[i][a];
        }
    }
    return parent[0][a];
}

struct SegTree {
    int shift;
    vector<int> tree;
    SegTree(int n) {
        shift = 1;
        while (shift < n) {
            shift *= 2;
        }
        tree.assign(2 * shift, 0);
    }
    int get_res(int v) {
        v += shift;
        int res = 0;
        while (v) {
            res += tree[v];
            v /= 2;
        }
        return res;
    }
    void update(int l, int r, int val) {
        int res = 0;
        l += shift;
        r += shift;
        while (l < r) {
            if (l & 1) {
                tree[l] += val;
                ++l;
                continue;
            }
            if (r & 1) {
                --r;
                tree[r] += val;
                continue;
            }
            l /= 2;
            r /= 2;
        }
    }
};

struct Query {
    int up, down;
    int alpha, whom;
    bool operator < (const Query& ot) const {
        return alpha < ot.alpha;
    }
};

void solve(bool read) {
    int n;
    //read = false;
    if (read) {
        cin >> n;
    } else {
        n = 100000;
    }
    tin.assign(n, 0);
    tout.assign(n, 0);
    g.clear();
    g.resize(n);
    parent.assign(L, vector<int>(n));
    for (int i = 1; i < n; ++i) {
        int a, b;
        if (read) {
            cin >> a >> b;
            --a;
            --b;
        } else {
            a = i;
            b = rand() % i;
        }
        g[a].push_back(b);
        g[b].push_back(a);
    }
    TIMER = 0;
    dfs1(0, 0);

    map<int, vector<pair<int, int>>> adds;
    for (int i = 0; i < n; ++i) {
        int cur;
        if (read) {
            cin >> cur;
        } else {
            cur = rand() % 10000000 + 1;
        }
        while (cur > 1) {
            int p = lp[cur];
            int cnt = 0;
            while (cur % p == 0) {
                cur /= p;
                ++cnt;
            }
            adds[p].push_back({cnt, i});
            //cout << "add " << p << " " << cnt << " " << i << endl;
        }
    }
    map<int, vector<Query>> qs;
    int Q;
    if (read) {
        cin >> Q;
    } else {
        Q = 100000;
    }
    for (int i = 0; i < Q; ++i) {
        int a, b, cur;
        if (read) {
            cin >> a >> b >> cur;
            --a;
            --b;
        } else {
            a = rand() % n;
            b = rand() % n;
            cur = rand() % 10000000 + 1;
        }
        int c = lca(a, b);
        int prev_c = ((c == 0) ? -1 : parent[0][c]);
        //cout << a + 1 << " " << b + 1 << " " << c + 1 << "\n";
        while (cur > 1) {
            int p = lp[cur];
            int cnt = 0;
            while (cur % p == 0) {
                cur /= p;
                ++cnt;
            }
            qs[p].push_back({c, a, cnt, i});
            qs[p].push_back({prev_c, b, cnt, i});
        }
    }

    SegTree tree(n);
    vector<li> res(Q, 1);
    for (auto& item : qs) {
        int p = item.first;
        auto& vec = item.second;
        sort(all(vec));
        auto& cur_adds = adds[p];
        sort(all(cur_adds));
        vector<vector<int>> all_adds;
        int uk = 0;
        for (int i = 0; i < vec.size(); ++i) {
            int alpha = vec[i].alpha;
            while (uk < cur_adds.size() && cur_adds[uk].first <= alpha) {
                int v = cur_adds[uk].second, val = cur_adds[uk].first;
                all_adds.push_back({tin[v], tout[v], val});
                //cout << p << " " << tin[v] << " " << tout[v] << " " << val << "\n";
                tree.update(tin[v], tout[v], val);
                ++uk;
            }
            int deg = tree.get_res(tin[vec[i].down]) - ((vec[i].up == -1) ? 0 : tree.get_res(tin[vec[i].up]));
            res[vec[i].whom] = res[vec[i].whom] * binpow((li)p, (li)deg, mod) % mod;
        }
        for (auto& old : all_adds) {
            tree.update(old[0], old[1], -old[2]);
        }
        all_adds.clear();

        uk = (int)cur_adds.size() - 1;
        for (int i = (int)vec.size() - 1; i >= 0; --i) {
            int alpha = vec[i].alpha;
            while (uk >= 0 && cur_adds[uk].first > alpha) {
                int v = cur_adds[uk].second, val = 1;
                all_adds.push_back({tin[v], tout[v], val});
                //cout << "add " << p << " " << tin[v] << " " << tout[v] << " " << val << endl;
                tree.update(tin[v], tout[v], val);
                --uk;
            }
            int deg = tree.get_res(tin[vec[i].down]) - ((vec[i].up == -1) ? 0 : tree.get_res(tin[vec[i].up]));
            /*if (p == 2 && alpha == 1 && vec[i].down == 1 && vec[i].up == 0)
            cout << alpha << " " << p << " " << tree.get_res(tin[vec[i].down]) << " " << ((vec[i].up == -1) ? 0 : tree.get_res(tin[vec[i].up])) << endl;*/
            res[vec[i].whom] = res[vec[i].whom] * binpow((li)p, ((deg * 1LL * alpha) % (mod - 1)), mod) % mod;
        }
        for (auto& old : all_adds) {
            tree.update(old[0], old[1], -old[2]);
        }
        all_adds.clear();
    }

    for (int i = 0; i < Q; ++i) {
        cout << res[i] << "\n";
    }

}