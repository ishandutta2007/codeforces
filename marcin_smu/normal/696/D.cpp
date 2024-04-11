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

#define MAX 401
int n,l;
int war[MAX];
string z[MAX];
map<string,int> ma;
int il = 0;
void add(string x){
  auto xx = ma.find(x);
  if(xx == ma.end()){
    debug(x,il);
    ma[x] = il;
    il++;
  }
}
int szu(string z){
  while(1){
    auto xx = ma.find(z);
    if(xx != ma.end()){
      return xx->SE;
    }
    z = z.substr(1);
  }
    
}
int ww[MAX];
int t[MAX][MAX],pom2[MAX][MAX],res[MAX],pom[MAX];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> l;
  R(i,n){
    cin >> war[i];
  }
  R(i,n){
    cin >> z[i];
    R(j,SZ(z[i])+1){
      add(z[i].substr(0,j));
    }
  }
  R(i,n){
    for(auto& x:ma){
      if(SZ(z[i]) > SZ(x.FI))continue;
      if(z[i] == x.FI.substr(SZ(x.FI) - SZ(z[i]), SZ(z[i])))
        ww[x.SE] += war[i];
    }
  }
 // R(i,il)debug(i,ww[i]);
  R(i,il)R(j,il)t[i][j] = -1e18;
  for(auto& x:ma){
    for(char k = 'a'; k <= 'z'; k++){
      string pom = x.FI + k;
      int gd = szu(pom);
   //   debug(x.SE,gd,ww[gd]);
      maxi(t[x.SE][gd], ww[gd]);
    }
  }
  R(i,il)res[i] = -1e18;
  res[0] = 0;
  while(l){
    if(l&1){
      R(i,il)pom[i] = -1e18;
      R(i,il)R(j,il)maxi(pom[j], res[i] + t[i][j]);
      R(i,il)res[i] = pom[i];
    }
    l/=2;
    R(i,il)R(j,il)pom2[i][j] = -1e18;
    R(i,il)R(j,il)R(k,il)maxi(pom2[i][k], t[i][j] + t[j][k]);
    R(i,il)R(j,il)t[i][j] = pom2[i][j];
  }
  int out = 0;
  R(i,il)maxi(out, res[i]);
  cout << out << "\n";
  
}
/*
x=,il=0
x=h,il=1
x=he,il=2
x=hea,il=3
x=hear,il=4
x=heart,il=5
x=e,il=6
x=ea,il=7
x=ear,il=8
x=eart,il=9
x=earth,il=10
x=a,il=11
x=ar,il=12
x=art,il=13
 * */