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

const int L = 17;
vector<vector<int>> parent, parts;
vector<vector<int>> g;
vector<int> tin, tout, depth;
int TIMER = 0;

vector<int> comp_id;
int cnt_comps = 0;

void dfs(int v, int d = 0) {
    tin[v] = TIMER++;
    comp_id[v] = cnt_comps;
    depth[v] = d;
    for (int to : g[v]) {
        dfs(to, d + 1);
    }
    tout[v] = TIMER++;
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

int get_sum(int v, int last) {
    assert(upper(last, v));
    if (v == last) {
        return 0;
    }
    int res = 0;
    for (int i = L - 1; i >= 0; --i) {
        if (!upper(parent[i][v], last)) {
            res += parts[i][v];
            v = parent[i][v];
        }
    }
    assert(parent[0][v] == last);
    res += parts[0][v];
    return res;
}

void solve(bool read) {
    //read = false;
    int n;
    if (read) {
        cin >> n;
    } else {
        n = 100000;
    }
    vector<int> type(n);
    parent.assign(L, vector<int>(n));
    parts.assign(L, vector<int>(n, 0));
    g.resize(n);
    for (int i = 0; i < n; ++i) {
        int par;
        if (read) {
            cin >> par >> type[i];
        } else {
            if (i == 0 || rand() % 5 == 0) {
                par = -1;
                type[i] = -1;
            } else {
                par = 1 + rand() % i;
                type[i] = rand() % 2;
            }
        }
        if (par != -1) {
            --par;
            g[par].push_back(i);
            parent[0][i] = par;
            parts[0][i] = (type[i] == 1);
        } else {
            parent[0][i] = i;
        }
    }
    for (int i = 1; i < L; ++i) {
        for (int j = 0; j < n; ++j) {
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
            parts[i][j] = parts[i - 1][j];
            if (parent[i - 1][j] != parent[i][j]) {
                parts[i][j] += parts[i - 1][parent[i - 1][j]];
            }
        }
    }

    tin.resize(n);
    tout.resize(n);
    depth.resize(n);
    comp_id.resize(n);
    for (int i = 0; i < n; ++i) {
        if (parent[0][i] == i) {
            dfs(i);
            ++cnt_comps;
        }
    }

    int Q;
    if (read) {
        cin >> Q;
    } else {
        Q = 100000;
    }
    while (Q--) {
        int t, u, v;
        if (read) {
            cin >> t >> u >> v;
        } else {
            t = 1 + rand() % 2;
            u = rand() % n + 1;
            v = rand() % n + 1;
        }
        --u; --v;
        if (comp_id[u] != comp_id[v]) {
            cout << "NO\n";
            continue;
        }
        if (t == 1) {
            //cout << upper(u, v) << " " << get_sum(v, u) << endl;
            if (u != v && upper(u, v) && get_sum(v, u) == 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            int a = lca(u, v);
            assert(upper(a, u) && upper(a, v));
            if (a == v) {
                cout << "NO\n";
                continue;
            }
            if (get_sum(u, a) == 0 && get_sum(v, a) == depth[v] - depth[a]) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

}