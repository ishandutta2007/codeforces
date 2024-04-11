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

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream& operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto& vv : V) os << vv << ","; os << "]";
  return os;
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int MAX = 1e6 + 5;
const int P = 1e9 + 7;
int n;
int sil[MAX];
int np[MAX];
int dziel[MAX];
int bezkw[MAX];
int ilpow[MAX];
void zero(){
  cout << "0\n";
  exit(0);
}
int setsize[MAX];
int war[MAX];
bool czwar[MAX];
int get_set(int a){
  return a == 1 ? 1 : n/a;
}
void ustal(int a,int b){
  debug("ustal",a,b);
  if(war[a] != 0 && war[a] != b)zero();
  if(war[a] == 0 && czwar[b])zero();
  if(get_set(a) != get_set(b))zero();
  if(war[a] == 0)setsize[get_set(a)]--;
  war[a] = b;
  czwar[b] = 1;
  
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  sil[0] = 1;
  setsize[1] = 1;
  R(i,n)sil[i+1] = sil[i] * (i+1) % P;
  np[1] = 1;
  for(int i = 2;i <= n;i++){
    if(!np[i]){
      setsize[get_set(i)]++;
      for(int j = 1;j * i <= n;j++){
        np[i*j] = i;
      }
    }
    debug(i,np[i]);
  }
  for(int i = 1; i<= n;i++){
    int ak = i;
    bezkw[i] = 1;
    while(ak != 1){
      int pom = np[ak];
      bezkw[i] *= pom;
      while(ak % pom == 0)
        ak/=pom;
    }
    ilpow[bezkw[i]]++;
    debug(i,bezkw[i]);
  }
  for(int i = 1; i<= n;i++){
    int pom = 0;
    cin >> pom;
    if(pom == 0)continue;
    pom = bezkw[pom];
    ilpow[pom]--;
    if(bezkw[i]/np[i] != pom/np[pom])zero();
    ustal(np[pom], np[bezkw[i]]);
  }
  int res = 1;
  R(i,n+1){
    debug(i,ilpow[i],setsize[i]);
    res = res * sil[ilpow[i]] % P;
    res = res * sil[setsize[i]] % P;
  }
  cout << res << "\n";
}