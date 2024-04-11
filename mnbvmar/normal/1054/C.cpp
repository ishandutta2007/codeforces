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

const int MaxN = 1024;

int fst_left[MaxN], fst_right[MaxN];
int num_left[MaxN];
int num_right[MaxN];
bool remaining[MaxN];
int answer[MaxN];

void Fail() {
  cout << "NO\n";
  exit(0);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int N;
  cin >> N;

  for (int i = 0; i < N; ++i) {
    cin >> num_left[i];
    fst_left[i] = num_left[i];
  }
  for (int i = 0; i < N; ++i) {
    cin >> num_right[i];
    fst_right[i] = num_right[i];
  }

  int rem = N;
  fill(remaining, remaining + N, true);

  int value = N;
  while (rem) {
    vector<int> zeros;
    for (int i = 0; i < N; ++i)
      if (remaining[i] && !num_left[i] && !num_right[i])
        zeros.PB(i);

    debug(zeros, rem);

    if (zeros.empty())
      Fail();

    for (int v : zeros) {
      answer[v] = value;
      remaining[v] = false;
    }

    for (int v : zeros) {
      for (int i = 0; i < N; ++i) {
        if (!remaining[i]) { continue; }
        debug(v, i);
        if (i < v)
          --num_right[i];
        else
          --num_left[i];
      }
      --rem;
    }
      --value;
  }

  for (int i = 0; i < N; ++i)
    if (num_left[i] != 0 || num_right[i] != 0)
      Fail();

  for (int i = 0; i < N; ++i)
    for (int j = i + 1; j < N; ++j) {
      if (answer[i] < answer[j]) {
        debug("iiii", i, j);
        --fst_right[i];
      }
      if (answer[i] > answer[j]) {
        debug("jjjj", i, j);
        --fst_left[j];
      }
    }

  for (int i = 0; i < N; ++i) {
    debug(i, fst_left[i], fst_right[i]);
    if (fst_left[i] || fst_right[i])
      Fail();
  }

  cout << "YES\n";
  for (int i = 0; i < N; ++i)
    cout << answer[i] << " ";
  cout << "\n";
}