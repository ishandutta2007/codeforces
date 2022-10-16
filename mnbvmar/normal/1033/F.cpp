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

const int Max = 531441;
const int MaxNum = 5000;

int W, N, M;

vector<int> occurs;
int vars_count[MaxNum];

const string kDescr = "AOXaox";
const vector<int> kBases = {0, 0, 0, 2, 1, 1};
const vector<vector<int>> kIncr = {VI{1}, VI{}, VI{2}, VI{}, VI{1}, VI{}};
vector<int> incrs;

int Solve(const string &s) {
  incrs.clear();
  incrs.PB(0);
  int base = 0;
  int b = 1;

  for (int i = 0; i < W; ++i) {
    int idx = 0;
    while (s[i] != kDescr[idx]) { ++idx; }
    base += b * kBases[idx];
    const auto v = kIncr[idx];
    if (SZ(v) == 1) {
      const int d = v[0] * b;
      const int olds = SZ(incrs);
      for (int z = 0; z < olds; ++z)
        incrs.PB(incrs[z] + d);
    }
    b *= 3;
  }

  debug(s, base, incrs);

  int total = 0;
  for (int inc : incrs)
    total += occurs[base + inc];
  return total;
}

void GetDescr(vector<int> &result, int a, int b) {
  result.resize(W);
  fill_n(result.begin(), W, 0);
  for (int i = 0; i < W; ++i) {
    result[i] += (a >> i) & 1;
    result[i] += (b >> i) & 1;
  }
}

int GetID(const vector<int> &descr) {
  int base = 1, r = 0;
  for (int i = 0; i < W; ++i) {
    r += base * descr[i];
    base *= 3;
  }
  return r;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> W >> N >> M;
  for (int i = 0; i < N; ++i) {
    int v;
    cin >> v;
    ++vars_count[v];
  }

  {
    int z = 1;
    for (int i = 0; i < W; ++i) { z *= 3; }
    occurs.resize(z);
  }

  for (int val = 0; val < (1 << W); ++val) {
    if (!vars_count[val]) { continue; }
    static vector<int> counts;
    GetDescr(counts, val, val);
    if (vars_count[val]) { debug(counts, val, val, GetID(counts)); }
    occurs[GetID(counts)] += vars_count[val] * vars_count[val];

    for (int other = val + 1; other < (1 << W); ++other) {
      if (!vars_count[other]) { continue; }
      GetDescr(counts, val, other);
      debug(counts, val, other, GetID(counts));
      occurs[GetID(counts)] += vars_count[val] * vars_count[other] * 2;
    }
  }
  debug(occurs);

  for (int i = 0; i < M; ++i) {
    string s;
    cin >> s;
    reverse(ALL(s));
    cout << Solve(s) << "\n";
  }
}