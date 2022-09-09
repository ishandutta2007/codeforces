#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
/*#if !defined(YCM) && 0
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx,tune=native")
#include <stdio.h>
#endif*/
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
    freopen("/home/alexandero/ClionProjects/ACM/input.txt", "r", stdin);
    //freopen("/home/alexandero/ClionProjects/ACM/output.txt", "w", stdout);
    //freopen("out.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;
    cout.sync_with_stdio(0);
    cin.tie(0);
    precalc();
    cout.precision(10);
    cout << fixed;
    //cin >> t;
    int testNum = 1;
    while (t--) {
        //cout << "Case #" << testNum++ << ": ";
        //cerr << testNum << endl;
        solve(true);
        //cerr << testNum - 1 << endl;
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

void precalc() {}

//#define int li
//const int mod = 1000000007;

struct Edge {
    int a, b;
    int id;
    int wei;
};

const int C = 500500;

vector<Edge> edges[C];

struct Query {
    int id;
    int index;
    bool operator < (const Query& ot) const {
        return id < ot.id;
    }
};

vector<Query> q[C];

vector<int> dsu;

void init(int n) {
    dsu.resize(n);
    for (int i = 0; i < n; ++i) {
        dsu[i] = i;
    }
}

int find_set(int v) {
    if (dsu[v] == v) {
        return v;
    }
    return dsu[v] = find_set(dsu[v]);
}

void merge(int q, int w) {
    q = find_set(q);
    w = find_set(w);
    dsu[w] = q;
}

int TIMER = 0;
vector<int> used;

vector<vector<int>> g;

bool dfs(int v, int p) {
    if (used[v] == TIMER) {
        return false;
    }
    used[v] = TIMER;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        if (used[to] == TIMER) {
            return true;
        }
        if (dfs(to, v)) {
            return true;
        }
    }
    return false;
}

void solve(bool read) {
    int n, m;
    cin >> n >> m;
    vector<Edge> all_edges;
    vector<int> pos_in_list(m);
    for (int i = 0; i < m; ++i) {
        Edge cur;
        cin >> cur.a >> cur.b;
        --cur.a; --cur.b;
        cur.id = i;
        int wei;
        cin >> wei;
        --wei;
        cur.wei = wei;
        pos_in_list[i] = (int)edges[wei].size();
        edges[wei].push_back(cur);
        all_edges.push_back(cur);
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int k;
        cin >> k;
        while (k--) {
            int index;
            cin >> index;
            --index;
            q[all_edges[index].wei].push_back({i, pos_in_list[index]});
        }
    }

    used.assign(n, 0);
    vector<int> ans(Q, 1);
    init(n);
    g.resize(n);
    for (int w = 0; w < C; ++w) {
        sort(all(q[w]));

        for (int i = 0; i < q[w].size(); ) {
            ++TIMER;
            vector<pair<int, int>> new_edges;
            int j = i;
            while (j < q[w].size() && q[w][j].id == q[w][i].id) {
                new_edges.emplace_back(find_set(edges[w][q[w][j].index].a), find_set(edges[w][q[w][j].index].b));
                ++j;
            }
            for (auto& item : new_edges) {
                if (item.first > item.second) {
                    swap(item.first, item.second);
                } else if (item.first == item.second) {
                    ans[q[w][i].id] = 0;
                }
            }
            sort(all(new_edges));
            for (int r = 0; r + 1 < new_edges.size(); ++r) {
                if (new_edges[r] == new_edges[r + 1]) {
                    ans[q[w][i].id] = 0;
                }
            }
            vector<int> vs;
            for (auto item : new_edges) {
                vs.push_back(item.first);
                vs.push_back(item.second);
            }
            make_unique(vs);
            for (int v : vs) {
                g[v].clear();
            }
            for (auto item : new_edges) {
                g[item.first].push_back(item.second);
                g[item.second].push_back(item.first);
            }
            for (int v : vs) {
                if (dfs(v, -1)) {
                    ans[q[w][i].id] = 0;
                    break;
                }
            }
            i = j;
        }

        for (auto e : edges[w]) {
            merge(e.a, e.b);
        }
    }

    for (int i = 0; i < Q; ++i) {
        if (ans[i]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }


}