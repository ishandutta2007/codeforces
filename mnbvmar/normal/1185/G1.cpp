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

int n, T;
vi genre, len;

vector<vector<vector<vi>>> dp;
int binoms[70][70];
int facts[70];

int num_setups[52][52][52][3];

const int mod = 1e9 + 7;

inline void Add(int &a, int b) {
  a += b;
  if (a >= mod) { a -= mod; }
}

int32_t main() {
  scanf("%d%d", &n, &T);
  genre.resize(n); len.resize(n);
  vi cnts(3);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &len[i], &genre[i]);
    --genre[i];
    ++cnts[genre[i]];
  }
  
  binoms[0][0] = 1;
  for (int n = 1; n < 70; ++n) {
    binoms[n][0] = 1;
    for (int k = 1; k <= n; ++k) {
      binoms[n][k] = (binoms[n-1][k-1] + binoms[n-1][k]) % mod;
    }
  }
  
  facts[0] = 1;
  for (int n = 1; n < 70; ++n) {
    facts[n] = (ll)facts[n-1] * n % mod;
  }
  
  dp.resize(T+1,
      vector<vector<vi>>(cnts[0]+1,
      vector<vi>(cnts[1]+1,
      vi(cnts[2]+1))));
      
  dp[0][0][0][0] = 1;
  
  int cur_total = 0;
  fill(ALL(cnts), 0);
  
  for (int i = 0; i < n; ++i) {
    cur_total = min(T, cur_total + len[i]);
    const int L = len[i];
    const int G = genre[i];
    ++cnts[G];
    
    int min_a = G == 0;
    int min_b = G == 1;
    int min_c = G == 2;
    
    for (int t = cur_total; t >= L; --t) {
      for (int a = min_a; a <= cnts[0]; ++a) {
        for (int b = min_b; b <= cnts[1]; ++b) {
          for (int c = min_c; c <= cnts[2]; ++c) {
            Add(dp[t][a][b][c],
                dp[t-L][a-(G==0)][b-(G==1)][c-(G==2)]);
          }
        }
      }
    }
  }
  
  for (int a = 0; a <= cnts[0]; ++a) {
    for (int b = 0; b <= cnts[1]; ++b) {
      for (int c = 0; c <= cnts[2]; ++c) {
        if (!a && !b && !c) { continue; }
        if (a + b + c == 1) {
          num_setups[a][b][c][(b?1:0) + (c?2:0)] = 1;
          continue;
        }
        
        for (int last : {0, 1, 2}) {
          for (int prv : {0, 1, 2}) {
            if (last == prv) { continue; }
            if (last == 0) {
              if (!a) { continue; }
              Add(num_setups[a][b][c][last], num_setups[a-1][b][c][prv]);
            } else if (last == 1) {
              if (!b) { continue; }
              Add(num_setups[a][b][c][last], num_setups[a][b-1][c][prv]);
            } else if (last == 2) {
              if (!c) { continue; }
              Add(num_setups[a][b][c][last], num_setups[a][b][c-1][prv]);
            }
          }
        }
      }
    }
  }
  
  int ans = 0;
  for (int a = 0; a <= cnts[0]; ++a) {
    for (int b = 0; b <= cnts[1]; ++b) {
      for (int c = 0; c <= cnts[2]; ++c) {
        int coef = dp[T][a][b][c];
        int x = 0;
        for (int t : {0, 1, 2}) {
          Add(x, num_setups[a][b][c][t]);
        }
        coef = (ll)coef * x % mod;
        coef = (ll)coef * facts[a] % mod;
        coef = (ll)coef * facts[b] % mod;
        coef = (ll)coef * facts[c] % mod;
        Add(ans, coef);
      }
    }
  }
  
  printf("%d\n", ans);
}