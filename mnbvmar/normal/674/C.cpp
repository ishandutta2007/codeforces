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

template<class C> void mini(C& _a4, C _b4) { _a4 = min(_a4, _b4); }
template<class C> void maxi(C& _a4, C _b4) { _a4 = max(_a4, _b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr << sdbg << '=' << h << endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream&operator<<(ostream&os, vector<T> V) {
  os << "["; for(auto vv : V) os << vv << ","; return os << "]";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(CC) {cerr<<#CC<<"=";for(auto&cc:CC)cerr<<cc<<",";cerr<<endl;}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(CC) {}
#define cerr if(0)cout
#endif

const int MaxN = 200005,
          MaxK = 55;
const LD Infty = 1e29;
          
int tokens[MaxN];
LD dp[MaxK][MaxN];
LD prefInv[MaxN];
LL prefSum[MaxN];
LD prefSumInv[MaxN];
int N, K;

vector<LD> funcA, funcB, funcStart;

LD cutTop(LD a, LD b) {
  LD aa = funcA.back(), bb = funcB.back();
  a -= aa; b -= bb;
  return -b / a;
}

void addFunc(LD a, LD b) {
  while (true) {
    LD x = cutTop(a, b);
    if (x < funcStart.back()) {
      funcA.pop_back(); funcB.pop_back(); funcStart.pop_back();
    } else {
      break;
    }
  }
  
  LD x = cutTop(a, b);
  funcA.push_back(a);
  funcB.push_back(b);
  funcStart.push_back(x);
  
  debug(funcA, funcB, funcStart, a, b);
}

LD evalFunc(LD x) {
  debug(funcA, funcB, funcStart);
  int dist = upper_bound(ALL(funcStart), x) - funcStart.begin() - 1;
  LD y= funcA[dist] * x + funcB[dist];
  debug(y);
  return y;
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  
  cin >> N >> K;
  for (int i = 1; i <= N; i++) {
    cin >> tokens[i];
    prefSum[i] = prefSum[i - 1] + tokens[i];
    prefInv[i] = prefInv[i - 1] + (LD)1 / tokens[i];
    prefSumInv[i] = prefSumInv[i - 1] + (LD)prefSum[i] / tokens[i];
  }
  
  fill(dp[0], dp[0] + N + 1, Infty);
  dp[0][0] = 0;
  
  for (int layer = 1; layer <= K; layer++) {
    debug(layer);
    funcA.clear(); funcB.clear(); funcStart.clear();
    funcA.push_back(0);
    funcB.push_back(dp[layer - 1][0]);
    funcStart.push_back(-Infty);
    
    for (int i = 1; i <= N; i++) {
      dp[layer][i] = evalFunc(prefInv[i]) + prefSumInv[i];
      debug(i, dp[layer][i]);
      if (dp[layer - 1][i] < Infty / 2) {
        addFunc(-prefSum[i], prefSum[i] * prefInv[i] - prefSumInv[i] + dp[layer - 1][i]);
      }
    }
  }
  
  cout << dp[K][N] << "\n";
}