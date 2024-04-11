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

bool GetColor(int x, int y) {
  cout << x << " " << y << endl;
  string s;
  cin >> s;
  return s == "black";
}

bool GetColor(PII x) {
  return GetColor(x.st, x.nd);
}

void Answer(int x1, int y1, int x2, int y2) {
  cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
  exit(0);
}

const int kMax = 9e8;
const int kBase = 100;

PII GetPointAt(int t) {
  if (t <= kMax) {
    return PII{kBase + t, kBase};
  } else {
    t -= kMax;
    assert(t <= kMax);
    return PII{kBase + kMax, kBase + t};
  }
}

int32_t main() {
  int N;
  cin >> N;

  if (N == 1) {
    GetColor(0, 0);
    Answer(1, 0, 2, 1);
  }

  int from = 0, to = kMax * 2;
  bool first_color = GetColor(GetPointAt(0));

  for (int i = 2; i <= N; ++i) {
    assert(to - from >= 2);
    const int mid = ((LL)from + to) / 2;
    const bool mid_color = GetColor(GetPointAt(mid));
    if (mid_color == first_color)
      from = mid;
    else
      to = mid;
  }

  const auto pt_from = GetPointAt(from);
  // const auto pt_to = GetPointAt(to);

  if (from < kMax) {
    Answer(pt_from.st, pt_from.nd + 1, pt_from.st + 1, pt_from.nd - 1);
  } else {
    Answer(pt_from.st - 1, pt_from.nd + 1, pt_from.st + 1, pt_from.nd);
  }
}