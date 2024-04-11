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


const int MaxN = 76;

string s;
int N;
int dp[MaxN][MaxN][MaxN][2];
vector<int> posV, posK, posOther;
int NV, NK, NO;


int numBigger(int num, const vector<int> &V, int cntV) {
  int res = 0;
  for (int i = cntV - 1; i >= 0; i--) {
    if (V[i] > num) { res++; } else { break; }
  }
  return res;
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N >> s;
  for (int i = 0; i < N;i ++) {
    if (s[i] == 'V') {
      posV.push_back(i);
    } else if (s[i] == 'K') {
      posK.push_back(i);
    } else {
      posOther.push_back(i);
    }
  }

  NV = SZ(posV);
  NK = SZ(posK);
  NO = SZ(posOther);

  for (int i = 0; i <= NV; i++) {
    for (int j = 0; j <= NK; j++) {
      for (int k = 0; k <= NO; k++) {
        for (int lastV : {0, 1}) {
          if (!i && !j && !k && !lastV) { continue; }

          dp[i][j][k][lastV] = 1e9;

          if (i && lastV) {
            mini(dp[i][j][k][lastV], min(dp[i - 1][j][k][0], dp[i - 1][j][k][1]) +
                                     numBigger(posV[i - 1], posK, j) +
                                     numBigger(posV[i - 1], posOther, k));
          }

          if (j && !lastV) {
            mini(dp[i][j][k][lastV], dp[i][j - 1][k][0] +
                                     numBigger(posK[j - 1], posV, i) +
                                     numBigger(posK[j - 1], posOther, k));
          }

          if (k && !lastV) {
            mini(dp[i][j][k][lastV], min(dp[i][j][k - 1][0], dp[i][j][k - 1][1]) +
                                     numBigger(posOther[k - 1], posV, i) +
                                     numBigger(posOther[k - 1], posK, j));
          }

        }
      }
    }
  }

  cout << min(dp[NV][NK][NO][0], dp[NV][NK][NO][1]) << "\n";
}