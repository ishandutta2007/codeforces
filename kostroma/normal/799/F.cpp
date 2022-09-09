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

//const int mod = 1000000007;

//#define int li

int get_prev_by_parity(int cur, int par) {
  if ((cur + par) & 1) {
    return cur - 1;
  } else {
    return cur - 2;
  }
}

struct Event {
  int l, r;
  int sign;
};

const int shift = 1 << 17;

const int INF = (int)1e9;

struct Node {
  int min;
  int cnt_mins;
  li sum_mins;
  int push_add;
  Node(): min(INF), sum_mins(0), push_add(0) {}
};

Node tree[2 * shift];

void push(int v) {
  Node& cur = tree[v];
  for (int h = 0; h < 2; ++h) {
    Node& child = tree[2 * v + h];
    child.push_add += cur.push_add;
    child.min += cur.push_add;
  }
  cur.push_add = 0;
}

Node merge(const Node& l, const Node& r) {
  Node res = l;
  if (res.min > r.min) {
    res = r;
  } else if (res.min == r.min) {
    res.sum_mins += r.sum_mins;
    res.cnt_mins += r.cnt_mins;
  }
  res.push_add = 0;
  return res;
}

Node rmq(int v, int tl, int tr, int l, int r) {
  if (tr <= l || r <= tl) {
    return Node();
  }
  if (l <= tl && tr <= r) {
    return tree[v];
  }
  push(v);
  int tm = (tl + tr) / 2;
  Node ans = merge(rmq(2 * v, tl, tm, l, r), rmq(2 * v + 1, tm, tr, l, r));
  return ans;
}


Node get_min(int l, int r) {
  return rmq(1, 0, shift, l, r);
}

void modify(int v, int tl, int tr, int l, int r, int val) {
  if (tr <= l || r <= tl) {
    return;
  }
  if (l <= tl && tr <= r) {
    tree[v].push_add += val;
    tree[v].min += val;
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  modify(2 * v, tl, tm, l, r, val);
  modify(2 * v + 1, tm, tr, l, r, val);
  tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
}

void update(int l, int r, int val) {
  return modify(1, 0, shift, l, r, val);
}

void build(int v, int tl, int tr, int m, int par) {
  if (tl >= m) {
    return;
  }
  if (tl + 1 == tr) {
    tree[v].min = 0;
    tree[v].cnt_mins = 1;
    tree[v].sum_mins = tl * 2 + par;
    tree[v].push_add = 0;
    return;
  }
  int tm = (tl + tr) / 2;
  build(2 * v, tl, tm, m, par);
  build(2 * v + 1, tm, tr, m, par);
  tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
}

void build(int m, int par) {
  return build(1, 0, shift, m, par);
}

void solve(bool read) {
  int n, m;
#ifdef AIM1
  read = false;
#endif
  if (read) {
    cin >> n >> m;
  } else {
    n = 200000;
    m = 200000;
  }
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    if (read) {
      cin >> a[i].first >> a[i].second;
      --a[i].first;
      --a[i].second;
    } else {
      a[i].first = 2 * (rand() % (m / 2));
      a[i].second = 2 * (rand() % (m / 2)) + 1;
      if (a[i].second < a[i].first) {
        swap(a[i].first, a[i].second);
      }
    }
  }
  vector<vector<Event>> events(m + 1);
  li res = 0;
  double sum_time = 0;
  for (int par_a = 0; par_a < 2; ++par_a) {
    for (int par_b = 0; par_b < 2; ++par_b) {
      for (int i=0;i<m;++i) events[i].clear();
      for (int i = 0; i < n; ++i) {
        int change = get_prev_by_parity(a[i].first, par_a) + 2;
        if ((a[i].first + par_b) & 1) {
          if ((a[i].first + a[i].second) & 1) {
            events[par_a].push_back({a[i].first, m - 1, 1});
            events[change].push_back({ a[i].first, m - 1, -1});
          } else {
            events[par_a].push_back({a[i].first, a[i].second, 1});
            events[change].push_back({a[i].first, a[i].second, -1});
          }
        } else if ((a[i].first + a[i].second) & 1) {
          events[par_a].push_back({a[i].second + 1, m - 1, 1});
          events[change].push_back({ a[i].second + 1, m - 1, -1});
        }
        int next_change = get_prev_by_parity(a[i].second, par_a) + 2;
        if ((par_b + par_a) & 1) {
          if ((a[i].second + par_a) & 1) {
            events[change].push_back({a[i].first, m - 1, 1});
            events[next_change].push_back({a[i].first, m - 1, -1});
          } else {
            events[change].push_back({a[i].first, a[i].second, 1});
            events[next_change].push_back({a[i].first, a[i].second, -1});
          }
        } else if ((a[i].second + par_a) & 1) {
          events[change].push_back({a[i].second + 1, m - 1, 1});
          events[next_change].push_back({a[i].second + 1, m - 1, -1});
        }
      }
      for (int i = 0; i < events.size(); ++i) {
        for (auto& e : events[i]) {
          //auto seg = get_parity_segment({e.l, e.r}, par_b);
          if ((e.l + par_b) & 1) {
            ++e.l;
          }
          if ((e.r + par_b) & 1) {
            --e.r;
          }
          e.l >>= 1;
          e.r >>= 1;
          //e.l = seg.first;
          //e.r = seg.second;
        }
      }
      int size = (m + 1 - par_b) >> 1;
      build(size, par_b);
      for (int i = 0; i < m; ++i) {
        if ((i + par_a) % 2) {
          assert(events[i].empty());
          continue;
        }
        //clock_t cur_time = clock();
        for (auto& e : events[i]) {
          update(e.l, e.r + 1, e.sign);
        }
        int min_index = (get_prev_by_parity(i, par_b) + 2) / 2;
        Node cur_sum = get_min(min_index, size);
        //sum_time += (clock() - cur_time) / 1.0 / CLOCKS_PER_SEC;
        if (cur_sum.min == 0) {
          li sum_add = cur_sum.sum_mins - cur_sum.cnt_mins * 1LL * i + cur_sum.cnt_mins;
          res += sum_add;
          //cout << par_a << " " << par_b << " " << i << " " << cur_sum.cnt_mins << " " << sum_add << endl;

        }
      }
    }
  }

  //cerr << "updates: " << sum_time << endl;

  vector<int> pref_add(m + 1);
  for (int i = 0; i < n; ++i) {
    ++pref_add[a[i].first];
    --pref_add[a[i].second + 1];
  }
  for (int i = 0; i < m; ++i) {
    pref_add[i + 1] += pref_add[i];
  }

  for (int i = 0; i < m; ) {
    if (pref_add[i]) {
      ++i;
      continue;
    }
    int j = i;
    while (j < m && pref_add[j] == 0) {
      ++j;
    }
    int len = j - i;
    for (int r = 1; r <= len; ++r) {
      res -= (len - r + 1) * 1LL * r;
    }
    i = j;
  }

  cout << res << endl;

}