#include <bits/stdc++.h>

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

template<class C> void mini(C&a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C&a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<endl;}
template<class TH, class...TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<",";_dbg(sdbg+1, a...);
}

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
  os<<"[";for(auto vv:V)os<<vv<<","; os<<"]";
  return os;
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) {
  os<<"("<<P.first<<","<<P.second<<")";
  return os;
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif


const int MaxPrice = 2e5 + 5,
          MaxN = 2e5 + 5;

int price, N;
int cntCoins[MaxN];
int whoNow[MaxPrice];
int prevNow[MaxPrice];
bool isCorrect[MaxPrice];
vector<pair<int, int>> coinsElems;


bool simulate(int coin) {
  int toGet = price;
  int ptrCoin = 0;

  debug(coin);
  bool used = false;
  int who = price + 1;

  while (toGet > 0) {
    debug(prevNow[who], whoNow[toGet]);
    who = min(prevNow[who], whoNow[toGet]);
    if (who == -1) { return true; }

    debug(toGet, who);
    if (who <= coin && !used) {
      debug("!");
      if (toGet < coin) { return false; }
      toGet -= coin;
      used = true;
    }

    int numFit = min(cntCoins[who], toGet / who);
    toGet -= who * numFit;
    debug(numFit, toGet);
  }

  return toGet > 0;
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(12);
  cerr << fixed << setprecision(6);

  cin >> price >> N;
  for (int i = 0; i < N; i++) {
    int v;
    cin >> v;
    cntCoins[v]++;
  }

  whoNow[0] = prevNow[0] = -1;
  for (int i = 1; i <= price + 1; i++) {
    if (cntCoins[i]) {
      whoNow[i] = i;
      prevNow[i] = whoNow[i - 1];
    } else {
      whoNow[i] = whoNow[i - 1];
      prevNow[i] = prevNow[i - 1];
    }
  }
  prevNow[price + 1] = whoNow[price];

  for (int add = 1; add <= price; add++) {
    if (simulate(add)) {
      cout << add << "\n";
      return 0;
    }
  }

  cout << "Greed is good\n";
}