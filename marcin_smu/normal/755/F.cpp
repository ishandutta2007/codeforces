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

const int MAX = 1e6 + 5;
bool odw[MAX];
int p[MAX];
int n,k;
map<int,int> cykl;
int ost[MAX];
int il[MAX];
bool licz(int m){
  if(m == 0)return 0;
  il[0] = 1;
  int xx = 0;
  for(PII ak:cykl){
    int a,kr;
    tie(a,kr) = ak;
    xx += a * kr;
    int lim = min(xx, m);
    for(int i = a;i <= lim;i++){
      if(!il[i] && il[i - a]){
        if(ost[i-a] != a){
          il[i] = 1;
        }else{
          il[i] = il[i-a] + 1;
        }
        ost[i] = a;
        if(il[i] > kr){
          il[i] = 0;
        } 
      }  
    }
    if(il[m])return 0;
  }
  return 1;
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> k;
  R(i,n){
    cin >> p[i];
    p[i]--;
  }
  R(i,n){
    if(odw[i] == 0){
      int ak = i;
      int dl = 0;
      while(!odw[ak]){
        odw[ak] = 1;
        ak = p[ak];
        dl++;
      }
      cykl[dl]++;
    }
  }
  int dwu = 0;
  int jed = 0;
  for(PII ak:cykl){
    dwu += (ak.FI / 2) * ak.SE;
    if(ak.FI & 1){
      jed += ak.SE;
    }
  }
  int pom = min(dwu, k);
  cout << k + licz(min(k, n - k)) << " " << 2 * pom + min(k - pom, jed) << "\n"; 
}