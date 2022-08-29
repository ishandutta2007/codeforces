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
#define MAX 101001
int n;
int a[MAX],b[MAX],c[MAX];

int mis,mas,mir,mar;
PII licz(int m){
  mis = mir = 4.5e18;
  mas = mar = -4.5e18;
  R(i,n){
    int d = abs(c[i] - m);
    mini(mis,a[i] + b[i] - d);
    maxi(mas,a[i] + b[i] + d);
    mini(mir,a[i] - b[i] - d);
    maxi(mar,a[i] - b[i] + d);
  }
  PII pom = {mas - mis, mar - mir};
  if(pom.FI < pom.SE)
    swap(pom.FI,pom.SE);
  return pom;
}
int calc(int x,int y,int z){
  int res = 0;
  R(i,n){
    maxi(res,abs(a[i]-x) + abs(b[i]-y) + abs(c[i]-z));
  }
  return res;
}
void test(){
  cin >> n;
  R(i,n){
    cin >> a[i] >> b[i] >> c[i];
  }
  int po = -1.1e18, ko = 1.1e18;
  while(po+1 != ko){
    int mi = (po + ko)/2;
    if(licz(mi - 1) < licz(mi))
      ko = mi;
    else
      po = mi;
  }
  int wyn = 4e18;
  int xx,yy,zz;
  for(int z = po-2; z <= po+2; z++){
    licz(z);
    int sum = mas + mis;
    int roz = mar + mir;
    int x = (sum + roz)/4;
    int y = (sum - roz)/4;
    R(i,3)R(j,3){
      int pom = calc(x+i-1,y+j-1,z);
      debug(pom);
      if(pom < wyn){
        xx = x + i-1;
        yy = y + j-1;
        zz = z;
        wyn = pom;
      }
    }
  }
  cout << xx << " " << yy << " " << zz << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int t;cin >> t;while(t--)test();
}