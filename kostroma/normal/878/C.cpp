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
  freopen("/home/alexandero/CLionProjects/ACM/input.txt", "r", stdin);
  //freopen("/home/alexandero/CLionProjects/ACM/output.txt", "w", stdout);
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
  cout.precision(20);
  cout << fixed;
  //cin >> t;
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

void precalc() {

}

//#define int li
//const int mod = 1000000007;

vector<int> dsu;
vector<int> size;

void init(int n) {
  dsu.resize(n);
  size.assign(n, 1);
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

vector<vector<int>> out_edges, in_edges;

void merge(int q, int w) {
  q = find_set(q);
  w = find_set(w);
  if (q == w) {
    return;
  }
  if (in_edges[q].size() < in_edges[w].size()) {
    swap(w, q);
  }
  dsu[w] = q;
  size[q] += size[w];
  for (int x : in_edges[w]) {
    in_edges[q].push_back(x);
  }
}

void solve(bool read) {
  //read = false;
  int n, k;
  if (read) {
    cin >> n >> k;
  } else {
    n = 50000;
    k = 10;
  }
  init(n);
  vector<vector<int>> a(n, vector<int>(k));
  for (int i = 0; i < n; ++i) {
    set<int> have;
    for (int j = 0; j < k; ++j) {
      if (read) {
        cin >> a[i][j];
      } else {
        do {
          a[i][j] = rand();
        } while (have.count(a[i][j]));
        have.insert(a[i][j]);
      }
    }
  }
  vector<set<pair<int, int>>> have(k);
  out_edges.resize(n);
  in_edges.resize(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      pair<int, int> item(a[i][j], i);
      auto it = have[j].lower_bound(item);
      if (it != have[j].begin()) {
        auto prev_it = prev(it);
        out_edges[i].push_back(prev_it->second);
      }
      if (it != have[j].end()) {
        in_edges[i].push_back(it->second);
      }
      have[j].insert(item);
    }
  }

  cout << "1\n";
  int root = 0;
  vector<int> used(n, 0);
  int TIMER = 1;
  int sum_ans = 0;
  for (int v = 1; v < n; ++v) {
    ++TIMER;
    bool in_root = false;
    for (int to : out_edges[v]) {
      in_edges[find_set(to)].push_back(v);
      if (find_set(to) == root) {
        in_root = true;
      }
    }
    bool from_root = !in_edges[v].empty();
    if (in_root && from_root) {
      queue<int> q;
      q.push(v);
      used[v] = TIMER;
      vector<int> to_merge;
      while (!q.empty()) {
        int cur_v = q.front();
        to_merge.push_back(cur_v);
        q.pop();
        for (int to : in_edges[cur_v]) {
          int new_to = find_set(to);
          if (new_to == root) {
            continue;
          }
          if (used[new_to] != TIMER) {
            used[new_to] = TIMER;
            q.push(new_to);
          }
        }
      }
      for (int x : to_merge) {
        merge(root, x);
        root = find_set(root);
      }
    } else if (in_root) {
      root = v;
      assert(find_set(root) == root);
    } else {
      assert(from_root);
    }
    if (read) {
      cout << size[root] << "\n";
    } else {
      sum_ans += size[root];
    }
  }

  if (!read) {
    cout << sum_ans << endl;
  }

}