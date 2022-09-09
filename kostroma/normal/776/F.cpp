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

  /*while (true) {
      solve(false);
  }*/

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

vector<vector<int>> diag;

int n;
map<pair<int, int>, int> diag_index;

vector<vector<int>> dsu;
vector<int> num_comp;

void merge(int q, int w) {
  q = num_comp[q];
  w = num_comp[w];
  if (dsu[q].size() > dsu[w].size()) {
    swap(q, w);
  }
  if (q == w) {
    return;
  }
  for (int x : dsu[q]) {
    num_comp[x] = w;
    dsu[w].push_back(x);
  }
  dsu[q].clear();
}

int get_second_index(int a, int b) {
  int res = diag_index[{a, b}] * 2;
  if (a > b) {
    res ^= 1;
  }
  return res;
}

int get_first_index(int a, int b) {
  int res = diag_index[{a, b}] * 2;
  if (a < b) {
    res ^= 1;
  }
  return res;
}

vector<vector<int>> g;
vector<char> used;
vector<int> cnt, max_cnt;
vector<int> have;

void dfs_center(int v, int p) {
  cnt[v] = 1;
  have.push_back(v);
  max_cnt[v] = 0;
  for (int to : g[v]) {
    if (to == p || used[to]) {
      continue;
    }
    dfs_center(to, v);
    cnt[v] += cnt[to];
    max_cnt[v] = max(max_cnt[v], cnt[to]);
  }
}

vector<int> res;

void decompose(int v, int depth) {
  if (used[v]) {
    return;
  }
  have.clear();
  dfs_center(v, v);
  int center = -1;
  for (int x : have) {
    if (cnt[v] - cnt[x] <= cnt[v] / 2 && max_cnt[x] <= cnt[v] / 2) {
      center = x;
      break;
    }
  }
  assert(center != -1);

  v = center;
  res[v] = depth;
  used[v] = true;
  for (int to : g[v]) {
    if (used[to]) {
      continue;
    }
    decompose(to, depth + 1);
  }
}

void solve(bool read) {
  //read = false;
  int m;
  if (read) {
    cin >> n >> m;
  } else {
    n = 100000;
    m = n / 2 - 2;
  }
  if (m == 0) {
    cout << "1\n";
    return;
  }
  diag.resize(n);
  vector<pair<int, int>> all_diags;
  for (int i = 0; i < m; ++i) {
    int a, b;
    if (read) {
      cin >> a >> b;
    } else {
      a = 2 * i + 1;
      b = 2 * i + 2 + 1;
      //cout << a << " " << b << endl;
    }
    --a; --b;
    diag[a].push_back(b);
    diag[b].push_back(a);
    if (a > b) {
      swap(a, b);
    }
    diag_index[{a, b}] = i;
    diag_index[{b, a}] = i;
    all_diags.push_back({a, b});
  }
  int SIZE = 2 * m + n;
  dsu.resize(SIZE);
  num_comp.resize(SIZE);
  for (int i = 0; i < SIZE; ++i) {
    dsu[i].push_back(i);
    num_comp[i] = i;
  }
  for (int i = 0; i < n; ++i) {
    sort(all(diag[i]));
    int cnt = 0;
    while (cnt < diag[i].size() && diag[i][cnt] < i) {
      ++cnt;
    }
    for (int j = 0; j < cnt; ++j) {
      diag[i].push_back(diag[i][j]);
    }
    diag[i].erase(diag[i].begin(), diag[i].begin() + cnt);
    int nex = i;
    int prev = (i + n - 1) % n;
    if (diag[i].empty()) {
      merge(nex + 2 * m, prev + 2 * m);
      continue;
    }
    merge(nex + 2 * m, get_second_index(i, diag[i][0]));
    merge(get_first_index(i, diag[i].back()), prev + 2 * m);
    for (int j = 0; j + 1 < diag[i].size(); ++j) {
      merge(get_first_index(i, diag[i][j]), get_second_index(i, diag[i][j + 1]));
    }
  }
  vector<vector<int>> faces;
  for (int i = 0; i < SIZE; ++i) {
    if (dsu[i].empty()) {
      continue;
    }
    faces.push_back(vector<int>());
    for (int x : dsu[i]) {
      if (x < 2 * m) {
        faces.back().push_back(all_diags[x / 2].first);
        faces.back().push_back(all_diags[x / 2].second);
      } else {
        faces.back().push_back(x - 2 * m);
        faces.back().push_back((x - 2 * m + 1) % n);
      }
    }
    sort(all(faces.back()));
    faces.back().erase(unique(all(faces.back())), faces.back().end());
    reverse(all(faces.back()));
  }
  sort(all(faces), [&](const vector<int>& a, const vector<int>& b) {
    for (int i = 0; i < a.size() && i < b.size(); ++i) {
      if (a[i] != b[i]) {
        return a[i] < b[i];
      }
    }
    return a.size() < b.size();
  });

  map<pair<int, int>, vector<int>> adj;
  for (int i = 0; i < faces.size(); ++i) {
    for (int j = 0; j < faces[i].size(); ++j) {
      int cur = faces[i][j], nex = faces[i][(j + 1) % faces[i].size()];
      if (cur > nex) {
        swap(cur, nex);
      }
      //cout << cur << " " << nex << endl;
      adj[{cur, nex}].push_back(i);

      //cout << faces[i][j] + 1 << " ";
    }
    //cout << endl;
  }

  g.resize(faces.size());
  for (auto& item : adj) {
    int diff = (item.first.first - item.first.second + n) % n;
    if (diff != 1 && diff != n - 1) {
      assert(item.second.size() == 2);
    } else {
      continue;
    }
    g[item.second[0]].push_back(item.second[1]);
    g[item.second[1]].push_back(item.second[0]);
  }

  used.assign(faces.size(), false);
  cnt.assign(faces.size(), 0);
  max_cnt.assign(faces.size(), 0);
  res.assign(faces.size(), -1);
  decompose(0, 0);

  for (int i = 0; i < res.size(); ++i) {
    cout << res[i] + 1 << " ";
  }
  cout << endl;

}