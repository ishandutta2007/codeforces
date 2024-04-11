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


const int MaxVal = 1e6 + 10;

int nextPrime[MaxVal];

void sieve() {
  iota(nextPrime, nextPrime + MaxVal, 0);
  for (int p = 2; p < MaxVal; p++) {
    if (nextPrime[p] != p) { continue; }
    for (int i = p * 2; i < MaxVal; i += p) {
      nextPrime[i] = p;
    }
  }
}

const int MaxN = 5e5 + 10;

int N, X, Y;
long long result;
int numbers[MaxN];
LL costs[MaxVal];
int cnts[MaxVal];

LL check(int p) {
  LL res = 0;

  for (int i = 0; i < N; i++) {
    int howMuch = numbers[i] % p;
    if (!howMuch)
      continue;
    howMuch = p - howMuch;

    res += min(X, (LL)howMuch * Y);
  }

  return res;
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N >> X >> Y;
  result = N * X;

  sieve();

  if (X <= 2 * Y) {
    for (int i = 0; i < N; i++) {
      cin >> numbers[i];
      int a = numbers[i] + 1, b = a - 1;

      int lastp = -1;
      while (a > 1) {
        int p = nextPrime[a];
        if (p != lastp) {
          costs[p] += min(X, Y);
          cnts[p]++;
        }
        lastp = p;
        a /= p;
      }

      lastp = -1;
      while (b > 1) {
        int p = nextPrime[b];
        if (p != lastp) {
          cnts[p]++;
        }
        lastp = p;
        b /= p;
      }
    }
    for (int i = 2; i < MaxVal; i++) {
      if (nextPrime[i] == i) {
        if (i < 50)
          debug(i, costs[i], cnts[i]);
        mini(result, costs[i] + (LL)X * (N - cnts[i]));
      }
    }

    cout << result << "\n";
    return 0;
  }

  for (int i = 0; i < N; i++) {
    cin >> numbers[i];
    for (int a : {numbers[i], numbers[i] + 1}) {
      int lastp = -1;
      while (a > 1) {
        int p = nextPrime[a];
        if (p != lastp) {
          costs[p]++;
        }
        lastp = p;
        a /= p;
      }
    }
  }

  for (int j = 2; j < MaxVal; j++) {
    if (costs[j] * 2 >= N) {
      mini(result, check(j));
    }
  }

  cout << result << "\n";
}