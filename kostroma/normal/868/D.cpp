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

const int MAGIC = 13;

struct Item {
  string pref, suf;
  int len;
  vector<set<int>> occurences;
  Item(const string& s) {
    len = (int)s.length();
    for (int i = 0; i < MAGIC && i < s.length(); ++i) {
      pref += s[i];
      suf += s[s.length() - 1 - i];
    }
    reverse(all(suf));
    occurences.resize(MAGIC);
    for (int i = 0; i < s.length(); ++i) {
      int cur = 0;
      for (int len = 0; i + len < s.length() && len + 1 < MAGIC; ++len) {
        cur = cur * 2 + (s[i + len] - '0');
        occurences[len + 1].insert(cur);
      }
    }
    /*for (int len = 1; len < MAGIC; ++len) {
      cout << s << " " << len << " " << occurences[len].size() << endl;
    }*/
  }
};

Item merge(const Item& q, const Item& w) {
  Item res("");
  res.len = min(q.len + w.len, 2 * MAGIC);
  res.pref = q.pref;
  res.suf = w.suf;
  int uk = 0;
  while (res.pref.length() < MAGIC && res.pref.length() < res.len) {
    res.pref += w.pref[uk++];
  }
  uk = 0;
  reverse(all(res.suf));
  while (res.suf.length() < MAGIC && res.suf.length() < res.len) {
    res.suf += q.suf[q.suf.length() - 1 - uk];
    ++uk;
  }
  reverse(all(res.suf));
  res.occurences = q.occurences;
  for (int i = 0; i < MAGIC; ++i) {
    for (int x : w.occurences[i]) {
      res.occurences[i].insert(x);
    }
  }

  string s = q.suf + w.pref;
  for (int i = 0; i < s.length(); ++i) {
    int cur = 0;
    for (int len = 0; i + len < s.length() && len + 1 < MAGIC; ++len) {
      cur = cur * 2 + (s[i + len] - '0');
      res.occurences[len + 1].insert(cur);
    }
  }
  return res;
}

void solve(bool read) {
  vector<Item> items;
  //read = false;
  int n;
  if (read) {
    cin >> n;
  } else {
    n = 100;
  }
  for (int i = 0; i < n; ++i) {
    string s;
    if (read) {
      cin >> s;
    } else {
      s = string(100, '0');
      for (int i = 0; i < s.length(); ++i) {
        if (rand() & 1) {
          s[i] = '1';
        }
      }
    }
    items.push_back(Item(s));
  }
  int m;
  if (read) {
    cin >> m;
  } else {
    m = 100;
  }
  for (int i = 0; i < m; ++i) {
    int a, b;
    if (read) {
      cin >> a >> b;
      --a;
      --b;
    } else {
      a = (int)items.size() - 1;
      b = a;
    }
    Item new_item = merge(items[a], items[b]);
    items.push_back(new_item);
    int res = 0;
    for (int len = MAGIC - 1; len > 0; --len) {
      if (new_item.occurences[len].size() == (1 << len)) {
        res = len;
        break;
      }
    }
    cout << res << endl;
  }

}