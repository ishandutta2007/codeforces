#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define RE(i,n) FOR(i,1,n)
#define R(i,n) REP(i,n)
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define VI vector<int>
#define PII pair<int,int>
#define LD long double

template<class C> void mini(C& a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C& a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream &os, vector<T> V){
  os<<"[";for(auto vv:V)os<<vv<<",";return os<<"]";
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


const int MaxBits = 20;
const int X = 32;

int Sprague[1 << MaxBits];
bool Seen[X];

int N;
map<int, unsigned> Factors;


inline unsigned mkMove(unsigned mask, int rem) {
  unsigned what = mask >> rem;
  unsigned newMask = (mask ^ (what << rem)) | (what >> 1);
  return newMask;
}

int brute(unsigned mask) {
  if (mask < (1 << MaxBits)) { return Sprague[mask]; }
  bool xseen[X];
  fill_n(xseen, X, false);

  for (int i = 0; (1U << i) <= mask; i++) {
    xseen[brute(mkMove(mask, i))] = true;
  }

  for (int i = 0; i < X; i++) {
    if (!xseen[i]) {
      return i;
    }
  }

  assert(false);
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  for (unsigned mask = 1; mask < (1U << MaxBits); mask++) {
    fill_n(Seen, X, false);
    for (int rem = 0; (1U << rem) <= mask; rem++) {
      Seen[Sprague[mkMove(mask, rem)]] = true;
    }

    int which = -1;
    for (int i = 0; i < X; ++i) {
      if (!Seen[i]) { which = i; break; }
    }
    assert(which >= 0);

    Sprague[mask] = which;
  }

  //for (int i = 0; i < 15; ++i) { cout << Sprague[i] << " | " << i << "\n"; }

  cin >> N;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;

    for (int p = 2; p * p <= num; p++) {
      if (num % p == 0) {
        int cnt = 0;
        while (num % p == 0) {
          cnt++; num /= p;
        }
        Factors[p] |= (1U << cnt);
      }
    }

    if (num > 1) {
      Factors[num] |= (1U << 1);
    }
  }

  int result = 0;

  for (auto F : Factors) {
    unsigned mask = F.second >> 1;
    if (mask >= (1U << MaxBits)) {
      result ^= brute(mask);
    } else {
      result ^= Sprague[mask];
    }
  }

  cout << (result ? "Mojtaba\n" : "Arpa\n");
}