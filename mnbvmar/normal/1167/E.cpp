#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
//#define int LL
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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int N, X;
  cin >> N >> X;

  vector<int> data(N);
  for (int &v : data) { cin >> v; }

  vector<int> first_occur(X+2, 1e9), last_occur(X+1, -1);
  for (int i = 0; i < N; ++i) {
    const int v = data[i];
    mini(first_occur[v], i);
    maxi(last_occur[v], i);
  }

  vector<int> pref_len(X + 2);
  for (int i = 1; i <= X; ++i) {
    if (last_occur[i] == -1) {
      pref_len[i] = pref_len[i - 1];
      continue;
    }
    if (first_occur[i] < pref_len[i - 1]) {
      pref_len[i] = 1e9;
      continue;
    }
    pref_len[i] = last_occur[i] + 1;
  }

  vector<int> suf_len(X + 2);
  for (int i = X; i >= 1; --i) {
    if (last_occur[i] == -1) {
      suf_len[i] = suf_len[i + 1];
      continue;
    }
    if (last_occur[i] + suf_len[i + 1] >= N) {
      suf_len[i] = 1e9;
      continue;
    }

    suf_len[i] = N - first_occur[i];
  }

  debug(pref_len, suf_len);

  int rptr = 0;
  LL ans = 0;
  for (int lptr = 0; lptr < X; ++lptr) {
    maxi(rptr, lptr + 2);
    if (pref_len[lptr] > N) { break; }
    while (pref_len[lptr] + suf_len[rptr] > N) {
      ++rptr;
    }

    debug(lptr, rptr);

    ans += (X + 2 - rptr);
  }
  cout << ans << "\n";
}