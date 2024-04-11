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
//int timer = 1;

int testNumber = 1;

bool todo = true;

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
        //cerr << testNum << endl;
        //cout << "Case #" << testNum++ << ": ";
        solve(true);
        ++testNumber;
        //++timer;
    }
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

void precalc() {

}

//#define int li
//const int mod = 1000000007;

vector<vector<int>> g;
vector<int> rad;
vector<char> in_path;

void dfs(int v, int p, int cur_dist) {
  rad[v] = cur_dist;
  //cout << v << " " << cur_dist << endl;
  for (int to : g[v]) {
    if (in_path[to] || to == p) {
      continue;
    }
    dfs(to, v, cur_dist + 1);
  }
}

struct Query {
  int a, b;
  int id;
};

void solve(bool read) {
  //read = false;
  int n, m, Q;
  if (read) {
    cin >> n >> m >> Q;
  } else {
    n = 100000;
    m = n / 2 - 1;
    Q = m;
  }
  g.resize(n);
  if (read) {
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
  } else {
    for (int i = 0; i + 1 < n / 2; ++i) {
      g[i].push_back(i + 1);
      g[i + 1].push_back(i);
    }
  }
  rad.resize(n);
  vector<int> dist(n, -1);
  vector<int> pred(n, -1);
  vector<int> cur_comp;
  vector<vector<int>> comps;
  vector<int> diams;
  in_path.assign(n, false);
  for (int i = 0; i < n; ++i) {
    if (dist[i] != -1) {
      continue;
    }
    int start = i;
    for (int w = 0; w < 2; ++w) {
      queue<int> q;
      cur_comp.clear();
      q.push(start);
      cur_comp.push_back(start);
      dist[start] = 0;
      while (!q.empty()) {
        int v = q.front();
        q.pop();
        int cur_dist = dist[v];
        for (int to : g[v]) {
          if (dist[to] == -1) {
            cur_comp.push_back(to);
            dist[to] = cur_dist + 1;
            pred[to] = v;
            q.push(to);
          }
        }
      }
      int fin = start;
      for (int x : cur_comp) {
        if (dist[x] > dist[fin]) {
          fin = x;
        }
      }
      if (w == 1) {
        vector<int> path;
        int cur = fin;
        while (cur != start) {
          path.push_back(cur);
          cur = pred[cur];
        }
        path.push_back(start);
        for (int x : path) {
          in_path[x] = true;
        }
        for (int j = 0; j < path.size(); ++j) {
          int initial_dist = max(j, (int)path.size() - 1 - j);
          dfs(path[j], path[j], initial_dist);
        }
        diams.push_back(dist[fin]);
      } else {
        start = fin;
        comps.push_back(cur_comp);
        for (int x : cur_comp) {
          dist[x] = -1;
        }
      }
    }
  }

  vector<int> num_comp(n, -1);
  for (int i = 0; i < comps.size(); ++i) {
    for (int x : comps[i]) {
      num_comp[x] = i;
    }
  }

  vector<Query> q;
  vector<int> have(comps.size(), 0);
  map<pair<int, int>, vector<int>> q_list;
  for (int i = 0; i < Q; ++i) {
    Query cur_q;
    if (read) {
      cin >> cur_q.a >> cur_q.b;
      --cur_q.a; --cur_q.b;
    } else {
      cur_q.a = i + n / 2;
      cur_q.b = 0;
    }
    cur_q.a = num_comp[cur_q.a];
    cur_q.b = num_comp[cur_q.b];
    cur_q.id = i;
    if (cur_q.a > cur_q.b) {
      swap(cur_q.a, cur_q.b);
    }
    if (q_list[{cur_q.a, cur_q.b}].empty() && cur_q.a != cur_q.b) {
      ++have[cur_q.a];
      ++have[cur_q.b];
      q.push_back(cur_q);
    }
    q_list[{cur_q.a, cur_q.b}].push_back(i);
  }

  vector<vector<int>> list_by_rad(comps.size());
  vector<vector<li>> suf_sums(comps.size());
  for (int i = 0; i < comps.size(); ++i) {
    for (int x : comps[i]) {
      list_by_rad[i].push_back(rad[x]);
    }
    sort(all(list_by_rad[i]));
    suf_sums[i].resize(list_by_rad[i].size() + 1);
    for (int j = (int)list_by_rad[i].size() - 1; j >= 0; --j) {
      suf_sums[i][j] = suf_sums[i][j + 1] + list_by_rad[i][j];
    }
  }

  const int MAGIC = 500;

  for (auto& item : q) {
    if (have[item.a] > have[item.b]) {
      swap(item.a, item.b);
    }
  }

  vector<double> ans(Q);
  int sum_operations = 0;

  for (int w = 0; w < 2; ++w) {
    vector<Query> rem_q;
    for (auto &item : q) {
      if (have[item.a] < MAGIC) {
        double res = 0;
        int cur_diam = max(diams[item.a], diams[item.b]);
        int j = 0;
        for (int i = (int) list_by_rad[item.a].size() - 1; i >= 0; --i) {
          int j = lower_bound(all(list_by_rad[item.b]), cur_diam - list_by_rad[item.a][i]) - list_by_rad[item.b].begin();
          /*while (j < list_by_rad[item.b].size() && list_by_rad[item.b][j] + list_by_rad[item.a][i] < cur_diam) {
            ++j;
            sum_operations++;
          }*/
          res += j * 1LL * cur_diam / (double) list_by_rad[item.b].size() / (double) list_by_rad[item.a].size();
          res += (suf_sums[item.b][j] + (1 + list_by_rad[item.a][i]) * 1LL * ((int) list_by_rad[item.b].size() - j))
                 / (double) list_by_rad[item.b].size() / (double) list_by_rad[item.a].size();
        }

        ans[item.id] = res;
        --have[item.a];
        --have[item.b];
      } else {
        rem_q.push_back(item);
      }
    }
    q.swap(rem_q);
  }
  assert(q.empty());

  //cout << sum_operations << endl;

  for (auto& item : q_list) {
    for (int x : item.second) {
      if (item.first.first == item.first.second) {
        ans[x] = -1;
        continue;
      }
      if (x == item.second[0]) {
        continue;
      }
      ans[x] = ans[item.second[0]];
    }
  }

  double cur_sum = 0;
  for (int i = 0; i < Q; ++i) {
    if (read) {
      cout << ans[i] << "\n";
    } else {
      cur_sum += ans[i];
    }
  }

  if (!read) {
    cout << cur_sum << endl;
  }



}