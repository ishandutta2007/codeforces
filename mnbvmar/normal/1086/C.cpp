#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

#define unordered_map __fast_unordered_map
template<class Key, class Value, class Hash = std::hash<Key>>
using unordered_map = __gnu_pbds::gp_hash_table<Key, Value, Hash>;

template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

struct Testcase {
  string s, a, b;
  int K;
  string mapping;
  vector<bool> taken;

  bool Bt(int pos, bool is_a, bool is_b) {
    debug(pos, is_a, is_b);
    if (pos == SZ(s) || (!is_a && !is_b)) {
      return true;
    }

    bool new_ch = true;
    char min_ch = is_a ? a[pos] : 'a';
    char max_ch = is_b ? b[pos] : 'a' + K - 1;
    if (mapping[s[pos] - 'a']) {
      const char val_new_ch = mapping[s[pos] - 'a'];
      if (val_new_ch < min_ch || val_new_ch > max_ch) { return false; }
      min_ch = max_ch = val_new_ch;
      new_ch = false;
    }
    for (char ch = min_ch; ch <= max_ch; ++ch) {
      if (new_ch) {
        if (taken[ch - 'a']) { continue; }
        taken[ch - 'a'] = true;
        mapping[s[pos] - 'a'] = ch;
      }

      if (Bt(pos + 1, is_a && ch == a[pos], is_b && ch == b[pos])) {
        return true;
      }

      if (new_ch) {
        taken[ch - 'a'] = false;
        mapping[s[pos] - 'a'] = 0;
      }
    }

    return false;
  }

  void Run() {
    cin >> K >> s >> a >> b;
    mapping.resize(K);
    taken.resize(K);

    if (Bt(0, true, true)) {
      cout << "YES\n";

      string unused;
      for (int i = 0; i < K; ++i)
        if (!taken[i]) {
          unused += 'a' + i;
        }

      for (char &ch : mapping) {
        if (!ch) {
          ch = unused.back();
          unused.pop_back();
        }
      }
      cout << mapping << "\n";
    } else {
      cout << "NO\n";
    }
  }
};


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int T;
  cin >> T;
  for (int i = 0; i < T; ++i)
    Testcase().Run();
}