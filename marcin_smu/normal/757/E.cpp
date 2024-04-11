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

const int MAX = 1e6 + 100;

int32_t mn[MAX][22];
int np[MAX];
const int P = 1e9 + 7;
int r,n;
int res;
void zap(){
  cin >> r >> n;
  res = 1;
  while(n != 1){
    int pom = np[n];
    int il = 0;
    while(n % pom == 0){
      il++;
      n /= pom;
    }
    if(r != 0){
      //debug(pom,il,r,spo[r+il][il+1], po[r + il-1][il]);
     // res *= (2 * spo[r+il][il+1] - po[r + il-1][il]);
     res *= mn[r+il][il+1];
    }else{
      res *= 2;
    }
    res %= P;
    
  }
  cout << (res%P+P)%P << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  vector<int> po(22);
  vector<int> spo(22);
  R(i,MAX-1){
    vector<int> ppo(22);
    vector<int> pspo(22);
    R(j,min(i+1, 21ll)){
      
      if(j == 0)
        ppo[j] = 1;
      else{
        ppo[j] = po[j-1] + po[j];
        if(ppo[j] >= P)
          ppo[j] -= P;
      }
      pspo[j+1] = spo[j] + po[j];
      if(pspo[j+1] >= P)
        pspo[j+1] -= P;
    }
    swap(ppo,po);
    swap(pspo,spo);
    R(j,22)if(j)
      mn[i][j] = 2 * spo[j] - ppo[j-1];
  }
  for(int i=2;i<MAX;i++){
    if(np[i] == 0){
      for(int j = 1; j * i < MAX; j++){
        if(np[i*j] == 0)
          np[i*j] = i;
      }
    }
  }
  int q;
  cin >> q;
  R(i,q)zap();
    
}