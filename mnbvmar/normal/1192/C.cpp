#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
#define PB push_back
#define MP make_pair
#define st first
#define nd second
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

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using ld = long double;

const int mod = 998244353;
const int kMaxLen = 11;
const string kAlpha =
  "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const int kAlphaSz = 62;

map<char, int> alpha_map;

void Add(int &dst, int src) {
  dst += src; if (dst >= mod) { dst -= mod; }
}

int ntrans[kAlphaSz][kAlphaSz];
int tri[kAlphaSz][kAlphaSz][kAlphaSz];
int ans = 0;

void MakeLen() {
#define FORLEN(i) for (int i = 0; i < kAlphaSz; ++i)
  FORLEN(a) FORLEN(b) FORLEN(c) {
    ll tri_val = 0;
    FORLEN(x) {
      tri_val += (ll)ntrans[a][x] * ntrans[b][x] * ntrans[c][x];
    }
    tri[a][b][c] = tri_val % mod;
  }
  
  FORLEN(a) FORLEN(b) FORLEN(c) {
    if (a > b || b > c) { continue; }
    int m = 1;
    if (a < b && b < c) {
      m = 6;
    } else if (a < b || b < c) {
      m = 3;
    }
    
    int coef_p = 0;
    
    FORLEN(p) {
      int x = (ll)tri[a][b][p] * tri[b][c][p] % mod;
      coef_p = (coef_p + (ll)x * tri[c][a][p]) % mod;
    }
    
    ans = (ans + (ll)coef_p * tri[a][b][c] * m) % mod;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  
  int n;
  cin >> n;
  vector<map<pair<char, char>, set<string>>> words(kMaxLen);
  
  for (int i = 0; i < n; ++i) {
    string w;
    cin >> w;
    const int len = w.size();
    for (int j : {0, 1}) {
      (void)j;
      words[len][make_pair(w[0], w.back())].insert(w);
      reverse(ALL(w));
    }
  }
  
  for (int i = 0; i < kAlphaSz; ++i) {
    alpha_map[kAlpha[i]] = i;
  }
  
  for (int len = 3; len < kMaxLen; ++len) {
    if (words[len].empty()) { continue; }
    memset(ntrans, 0, sizeof(ntrans));
    for (auto &&[p, wds] : words[len]) {
      ntrans[alpha_map[p.st]][alpha_map[p.nd]] = SZ(wds);
    }
    
    MakeLen();
  }
  
  cout << ans << "\n";
}