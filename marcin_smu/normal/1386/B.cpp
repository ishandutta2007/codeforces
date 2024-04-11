#pragma GCC optimize("O3")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// gp_hash_table<int, int> mapka;

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

template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
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

struct point3D{
  int x,y,z;
  bool scal(){
    int cd = abs(__gcd(__gcd(x,y),z));
    bool minus = 0;
    if(x < 0 || (x == 0 && y < 0) || (x == 0 && y == 0 && z < 0)){
      minus = 1;
      cd *= -1;
    }
    x/=cd;
    y/=cd;
    z/=cd;
    return minus;
  }
  void pob(){
    cin >> x >> y >> z;
    scal();
  }
  bool operator<(const point3D &b) const{
    if(x != b.x)return x < b.x;
    if(y != b.y)return y < b.y;
    return z < b.z;
  }
  bool operator!=(const point3D &b) const{
    return x != b.x || y != b.y || z != b.z;
  }
  bool operator==(const point3D &b) const{
    return x == b.x && y == b.y && z == b.z;
  }
}cel;
int n;
int il1 = 0;
int il2 = 0;

struct point{
  __int128_t x, y;
  bool operator<(const point &b) const{
    bool pa = (x > 0) || (x == 0 && y > 0);
    bool pb = (b.x > 0) || (b.x == 0 && b.y > 0);
    if(pa != pb)return pa < pb;
    return x * b.y > y * b.x;
  }
  friend ostream& operator<<(ostream& out, point p) {
    out << "(" << (int)p.x << ", " << (int)p.y << ")"; return out;
  }
};

vector<char> typ;
vector<point3D> t;
vector<int> kt;
point3D il_wek(point3D a, point3D b){
  return {
    a.y * b.z - a.z * b.y,
    a.z * b.x - a.x * b.z,
    a.x * b.y - a.y * b.x
  };
}

map<point3D,int> pluss, minuss;
void dodaj(point3D pom, bool jak, int mn){
  debug(pom.x, pom.y, pom.z, jak, mn);
  il2 -= pluss[pom] * minuss[pom];
  if(jak){
    minuss[pom] += mn;
  }else{
    pluss[pom] += mn;
  }
  il2 += pluss[pom] * minuss[pom];
}
vector<int> dp;
vector<int> tu;
vector<point> pocz,kon;
int nn;
void ak(int nr){
  dp[nr] = tu[nr] || (nr < nn && (dp[nr *2] && dp[nr * 2+1] ));
}
void add(int po,int ko, int mn){
  debug("add", po, ko ,mn);
  function<void(int,int,int)> rec = [&](int nr,int be,int en){
    debug(nr, be, en);
    if(be >= ko || po >= en)return;
    if(po <= be && en <= ko){
      tu[nr] += mn;
      ak(nr);
      return;
    }
    rec(nr * 2, be, (be + en) / 2);
    rec(nr * 2 + 1, (be + en) / 2, en);
    ak(nr);
  };
  if(po < ko){
    rec(1,0,nn);
  }else{
    int pompo = po;
    po = 0;
    rec(1,0,nn);
    po = pompo;
    ko = nn;
    rec(1,0,nn);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cel.pob();
  cin >> n;
  typ.resize(n);
  map<point,int> scal;
  R(i,n){
    cin >> typ[i];
    if(typ[i] == 'A'){
      point3D p;
      p.pob();
      t.PB(p);
      if(p != cel && cel.x != 0){
        point pom; 
        if(p.x){
          pom = {p.y * cel.x - p.x * cel.y, p.z * cel.x - p.x * cel.z};
        }else{
          pom = {p.y, p.z};
        }
        pocz.PB(pom);
        scal[pom] = 0;
        pom.x *= -1;
        pom.y *= -1;
        kon.PB(pom);
        scal[pom] = 0;
      }else{
        pocz.PB({0,0});
        kon.PB({0,0});
      }
    }else{
      int nr;
      cin >> nr;
      kt.PB(nr-1);
    }
  }
  int is = 0;
  for(auto &el:scal){
    el.SE = is;
    is++;
    debug(el);
  }
  debug(is);
  nn = 1;while(nn <= is)nn*=2;
  dp.resize(nn*2);
  tu.resize(nn*2);
  
  int ip = 0;
  int ikt = 0;
  R(_,n){
    if(typ[_] == 'A'){
      if(t[ip] == cel){
        il1++;
      }else{
        point3D x = il_wek(t[ip], cel);
        int jak = x.scal();
        dodaj(x,jak,1);
        if(cel.x){
          debug((int)pocz[ip].x, (int)pocz[ip].y);
          add(scal[pocz[ip]], scal[kon[ip]], 1);
        }
      }
      ip++;
    }else{
      int i = kt[ikt];ikt++;
      if(t[i] == cel){
        il1--;
      }else{
        point3D x = il_wek(t[i], cel);
        int jak = x.scal();
        dodaj(x,jak,-1);
        if(cel.x){
          add(scal[pocz[i]], scal[kon[i]], -1);
        }
      }
    }
    debug(il1,il2,dp[1]);
    if(il1){
      cout << "1\n";
    }else if(il2){
      cout << "2\n";
    }else{
      if(cel.x && dp[1]){
        cout << "3\n";
      }else{
        cout << "0\n";
      }
    }
  }
}