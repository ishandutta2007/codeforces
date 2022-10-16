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

const int Mod = 1e9 + 7;

struct Tree {
  vector<LL> vals;
  int base;

  Tree(int n) : base(1) {
    while (base < n + 2) { base *= 2; }
    vals.resize(base * 2);
  }

  void Add(int p, LL val) {
    p += base;
    while (p) {
      vals[p] += val;
      p /= 2;
    }
  }

  LL GetSum(int L, int R) const {
    L += base; R += base;
    if (L > R) { return 0; }
    if (L == R) { return vals[L]; }
    LL ans = vals[L] + vals[R];
    while (L / 2 != R / 2) {
      if (L % 2 == 0) { ans += vals[L + 1]; }
      if (R % 2 == 1) { ans += vals[R - 1]; }
      L /= 2; R /= 2;
    }
    return ans;
  }
};

int n;
unique_ptr<Tree> just_sum, dec_sum, inc_sum;

void AddElem(int v) {
  //just_sum->Add(v, 1);
  dec_sum->Add(v, n - v);
  inc_sum->Add(v, v + 1);
}

/*LL GetPref(int v) {
  if (v == 0) { return 0; }
  return inc_sum->GetSum(0, v);
}*/

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> n;

  //just_sum = unique_ptr<Tree>(new Tree(n));
  dec_sum = unique_ptr<Tree>(new Tree(n));
  inc_sum = unique_ptr<Tree>(new Tree(n));

  vector<int> elems(n);
  for (int i = 0; i < n; ++i) {
    cin >> elems[i];
  }

  vector<int> ordah(n);
  iota(ALL(ordah), 0);
  sort(ALL(ordah), [&](int lptr, int rptr) { return elems[lptr] < elems[rptr]; });

  int ans = 0;

  for (int pos : ordah) {
    int v = pos;
    //LL pref_cnt = just_sum->GetSum(0, v);
    //LL suf_cnt = just_sum->GetSum(v, n - 1);
    LL pref = inc_sum->GetSum(0, v) * (n - v);// * suf_cnt;
    LL suf = dec_sum->GetSum(v, n - 1) * (v + 1);// * pref_cnt;
    LL nintvs = (LL)(v + 1) * (n - v);
    LL total = pref + suf + nintvs;
    debug(pos, total, pref, suf, nintvs);

    total %= Mod;
    ans = (ans + total * elems[pos]) % Mod;

    AddElem(pos);
  }
  cout << ans << "\n";
}