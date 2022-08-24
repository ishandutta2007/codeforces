#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;

#define right zhopaafasfafafa
#define left zhopfafafafa2

int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}

int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}

int mult(int a, int b) {
    return (1LL * a * b) % mod;
}

struct Fenwick{
    vector < int > f;
    int n;

    Fenwick() {}

    Fenwick(int _n) {
        n = _n;
        f.resize(n + 2);
    }
    void upd(int v, int d) {
        while (v <= n) {
            f[v] = sum(f[v], d);
            v = (v | (v - 1)) + 1;
        }
    }
    int get(int r) {
        int ans = 0;
        while (r > 0) {
            ans = sum(ans, f[r]);
            r &= (r - 1);
        }
        return ans;
    }
    int get(int l, int r) {
        if (l > r) return 0;
        return sub(get(r), get(l - 1));
    }
};

struct SG{
  int n;
  vector < pair < int, int > > t;
  vector < int > lazy;
  vector < int > my_vals;
  // sum b_i * c_i, sum b_i

  SG() {}

  SG(vector < int >& vals) {
      n = vals.size();
      t.resize(4 * n + 1);
      lazy.resize(4 * n + 1);
      my_vals = vals;
  }


  void update(int v, int x) {
      lazy[v] = sum(lazy[v], x);
      t[v].first = sum(t[v].first, mult(t[v].second, x));
  }

  void push(int v, int tl, int tr) {
      if (tl != tr && lazy[v]) {
          update(2 * v, lazy[v]);
          update(2 * v + 1, lazy[v]);
      }
      lazy[v] = 0;
  }

  void merge(int v) {
      t[v].first = sum(t[2 * v].first, t[2 * v + 1].first);
      t[v].second = sum(t[2 * v].second, t[2 * v + 1].second);
  }

  void add(int v, int tl, int tr, int l, int r, int x) {
      if (l <= tl && tr <= r) {
          update(v, x);
          return;
      }
      if (r < tl || l > tr) return;
      push(v, tl, tr);
      int tm = (tl + tr) / 2;
      add(2 * v, tl, tm, l, r, x);
      add(2 * v + 1, tm + 1, tr, l, r, x);
      merge(v);
  }

  int get(int v, int tl, int tr, int l, int r) {
      if (l <= tl && tr <= r) {
          return t[v].first;
      }
      if (r < tl || l > tr) return 0;
      push(v, tl, tr);
      int tm = (tl + tr) / 2;
      return sum(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
  }

  void add(int l, int r, int x) {
      add(1, 1, n, l, r, x);
  }

  int get(int l, int r) {
      return get(1, 1, n, l, r);
  }

  void change_to(int v, int tl, int tr, int pos, int new_val, bool add) {
      if (tl == tr) {
          if (add) {
              t[v].second = my_vals[tl - 1];
          }
          else {
              t[v].second = 0;
          }
          t[v].first = new_val;
          return;
      }
      push(v, tl, tr);
      int tm = (tl + tr) / 2;
      if (pos <= tm) change_to(2 * v, tl, tm, pos, new_val, add);
      else change_to(2 * v + 1, tm + 1, tr, pos, new_val, add);
      merge(v);
  }

  void change_to(int pos, int new_val, bool add) {
      change_to(1, 1, n, pos, new_val, add);
  }

};

int n;
const int maxN = (int)1e5 + 100;
int a[maxN];
int b[maxN];
int c[maxN];
vector < int > byId[maxN];
int his_pos[maxN];
vector < Fenwick > forCnt;
vector < Fenwick > forB, forC;
vector < SG > right, left;
int max_sz;
int tot_sz[maxN];
void compress_and_get() {
    vector < int > all;
    for (int i = 1; i <= n; i++) {
        all.emplace_back(a[i]);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    max_sz = all.size();
    for (int i = 1; i <= n; i++) {
        int id = lower_bound(all.begin(), all.end(), a[i]) - all.begin() + 1;
        a[i] = id;
        byId[id].push_back(i);
        his_pos[i] = byId[id].size();
    }
    Fenwick fw(n);
    for (int i = 1; i <= n; i++) {
        for (int v : byId[i]) {
            fw.upd(v, +1);
        }
        for (int v : byId[i]) {
            b[v] = fw.get(v - 1);
            c[v] = fw.get(v + 1, n);
//            cout << b[v] << " " << c[v] << '\n';
        }
    }
    forCnt.resize(max_sz + 1);
    forB.resize(max_sz + 1);
    forC.resize(max_sz + 1);
    right.resize(max_sz + 1);
    left.resize(max_sz + 1);
    for (int i = 1; i <= max_sz; i++) {
        tot_sz[i] = byId[i].size();
        forCnt[i] = Fenwick(tot_sz[i]);
        forB[i] = Fenwick(tot_sz[i]);
        forC[i] = Fenwick(tot_sz[i]);
        vector < int > bs, cs;
        for (int v : byId[i]) {
            bs.push_back(b[v]);
            cs.push_back(c[v]);
        }
        right[i] = SG(cs);
        left[i] = SG(bs);
    }
}

int TOT = 0;

// FIRST UPDATE THEN CHANGE!

int calc(int i) {
    // always active!
    int where = a[i];
    int pos = his_pos[i];
    int b_pref = forB[where].get(pos - 1);
    int c_suf = forC[where].get(pos + 1, tot_sz[where]);
    int f1 = mult(b_pref, c_suf);
    int tot_r = right[where].get(pos + 1, tot_sz[where]);
    // c[r]
    int his_cnt = forCnt[where].get(pos);
    int fr = sub(tot_r, mult(sum(his_cnt, 1), c_suf));
    // 0 1 2 3 4
    // 1 2 3
    int tot_l = left[where].get(1, pos - 1);
    int fl = sub(mult(sub(his_cnt, 1), b_pref), tot_l);
    return sum(f1, sum(mult(fl, c[i]), mult(fr, b[i])));
}

const int minus_one = mod - 1;

void add(int i) {
    int where = a[i];
    int pos = his_pos[i];
    forCnt[where].upd(pos, +1);
    forB[where].upd(pos, b[i]);
    forC[where].upd(pos, c[i]);
    int his_cnt = forCnt[where].get(pos);
    right[where].add(pos + 1, tot_sz[where], +1);
    right[where].change_to(pos, mult(c[i], his_cnt), true);
    left[where].add(pos + 1, tot_sz[where], +1);
    left[where].change_to(pos, mult(b[i], his_cnt), true);
    TOT = sum(TOT, calc(i));
    //TODO
}

void del(int i) {
    int where = a[i];
    int pos = his_pos[i];
    TOT = sub(TOT, calc(i));
    forCnt[where].upd(pos, minus_one);
    forB[where].upd(pos, mult(b[i], minus_one));
    forC[where].upd(pos, mult(c[i], minus_one));
    right[where].add(pos + 1, tot_sz[where], minus_one);
    right[where].change_to(pos, 0, false);
    left[where].add(pos + 1, tot_sz[where], minus_one);
    left[where].change_to(pos, 0, false);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    compress_and_get();
    for (int i = 1; i <= n; i++) {
        add(i);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int tp, x;
        cin >> tp >> x;
        if (tp == 1) {
            del(x);
        }
        else {
            add(x);
        }
        cout << TOT << '\n';
    }
    return 0;
}