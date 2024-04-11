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

void precalc() {

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
//const int mod = 1000000007;

struct Dsu {
  vector<int> dsu;
  vector<int> size;
  void init(int n) {
    dsu.resize(n);
    for (int i = 0; i < n; ++i) {
      dsu[i] = i;
    }
    size = vector<int>(n, 1);
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
    if (q == w) {
      return;
    }
    dsu[w] = q;
    size[q] += size[w];
    size[w] = 0;
  }
};

int n, k;
int get_index(int x, int y) {
  return x * n + y;
}

vector<vector<int>> pref_sum;

int get_sum(int x, int y) {
  int ans = pref_sum[x + k][y + k] - pref_sum[x][y + k] - pref_sum[x + k][y] + pref_sum[x][y];
  return ans;
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void solve(bool read) {
  cin >> n >> k;
  /*n = 500;
  k = 250;*/
  vector<string> matrix(n);
  for (int i = 0; i < n; ++i) {
    cin >> matrix[i];
    /*for (int j = 0; j < n; ++j) {
      if (rand() % 3 == 0) {
        matrix[i] += 'X';
      } else {
        matrix[i] += '.';
      }
    }*/
  }
  Dsu dsu;
  dsu.init(n * n);
  pref_sum.assign(n + 1, vector<int>(n + 1, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      pref_sum[i + 1][j + 1] = pref_sum[i][j + 1] + pref_sum[i + 1][j] - pref_sum[i][j];
      if (matrix[i][j] == 'X') {
        ++pref_sum[i + 1][j + 1];
      } else {
        for (int dir = 0; dir < 4; ++dir) {
          int x = i + dx[dir], y = j + dy[dir];
          if (x < 0 || x >= n || y < 0 || y >= n || matrix[x][y] == 'X') {
            continue;
          }
          dsu.merge(get_index(i, j), get_index(x, y));
        }
      }
    }
  }

  vector<int> cnt(n * n, 0);
  vector<int> used_border(n * n, 0);
  vector<char> inside(n * n, false);
  int TIMER = 1;
  vector<int> xs, ys;
  int ans = 0;
  for (int i = 0; i + k <= n; ++i) {
    cnt.assign(n * n, 0);
    inside.assign(n * n, false);
    int sum_inside = 0;
    for (int x = i; x < i + k; ++x) {
      for (int j = 0; j < k; ++j) {
        if (matrix[x][j] == 'X') {
          continue;
        }
        int comp_id = dsu.find_set(get_index(x, j));
        ++cnt[comp_id];
        if (cnt[comp_id] == 1 && !inside[comp_id]) {
          sum_inside += dsu.size[comp_id];
          inside[comp_id] = true;
          //cout << x << " " << j << " " << sum_inside << endl;
        }
      }
    }

    for (int j = 0; j + k <= n; ++j) {

      //cout << "look " << i << " " << j << " " << sum_inside << endl;

      ++TIMER;
      xs = {i - 1, i + k};
      ys = {j - 1, j + k};
      int cur_ans = sum_inside;
      for (int x : xs) {
        if (x < 0 || x >= n) {
          continue;
        }
        for (int y = j; y < j + k; ++y) {
          if (matrix[x][y] == '.') {
            int comp_id = dsu.find_set(get_index(x, y));
            if (!inside[comp_id] && used_border[comp_id] != TIMER) {
              used_border[comp_id] = TIMER;
              cur_ans += dsu.size[comp_id];
            }
          }
        }
      }
      for (int y : ys) {
        if (y < 0 || y >= n) {
          continue;
        }
        for (int x = i; x < i + k; ++x) {
          if (matrix[x][y] == '.') {
            int comp_id = dsu.find_set(get_index(x, y));
            if (!inside[comp_id] && used_border[comp_id] != TIMER) {
              used_border[comp_id] = TIMER;
              cur_ans += dsu.size[comp_id];
            }
          }
        }
      }
      //cout << "relax " << cur_ans << " " << get_sum(i, j) << endl;
      relax_max(ans, cur_ans + get_sum(i, j));

      for (int x = i; x < i + k; ++x) {
        if (matrix[x][j] == '.') {
          int comp_id = dsu.find_set(get_index(x, j));
          --cnt[comp_id];
          if (cnt[comp_id] == 0) {
            inside[comp_id] = false;
            sum_inside -= dsu.size[comp_id];
          }
        }
        if (j + k < n && matrix[x][j + k] == '.') {
          int comp_id = dsu.find_set(get_index(x, j + k));
          ++cnt[comp_id];
          if (cnt[comp_id] == 1) {
            inside[comp_id] = true;
            sum_inside += dsu.size[comp_id];
          }
        }
      }
    }
  }

  cout << ans << endl;

}