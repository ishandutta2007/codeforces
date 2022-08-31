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

int randCF(){
  return abs((rand() << 20) + rand());
}

int lim = 1000 * 1000 * 100;
int los(int a, int b){
  int res = randCF() % (b - a) + a;
  assert(a <= res && res < b);
  return res;
}

int xbez, ybez, ilbez = -1;
vector<int> XX;
vector<int> YY;
int ask(int x,int y){
  assert(x <= lim && x >= -lim);
  assert(y <= lim && y >= -lim);
  int res;
  cout << "0 " << x << " " << y << endl;

#ifdef LOCAL
  res = 2e18;
  for(int el:XX){
    mini(res,abs(el-x));
  }
  for(int el:YY){
    mini(res,abs(el-y));
  }
#else
  cin >> res;
#endif
  
  if(ilbez < res){
    ilbez = res;
    xbez = x;
    ybez = y;
    debug(xbez,ybez);
  }
  
  return res;
}


struct prze{
  int po, ko;
  bool operator< (const prze pom) const{
    if(ko - po != pom.ko - pom.po){
      return ko - po > pom.ko - pom.po;
    }
    return ko < pom.ko;
  }
  int mid(){
    int pom = (po + ko) >> 1;
    assert(po <= pom && pom < ko);
    return pom;
  }
  int len(){
    return ko - po;
  }
};
set<prze> a,b;
vector<int> resx,resy;
set<int> askedy, askedx;

void sprx(int x){
  if(x < -lim || x > lim)return;
  if(!askedx.insert(x).SE)return;
  debug("sprx");
  int pom = ask(x,ybez);
  if(pom == 0){
    resx.PB(x);
  }
}

void spry(int y){
  if(y < -lim || y > lim)return;
  if(!askedy.insert(y).SE)return;
  debug("spry");
  int pom = ask(xbez,y);
  if(pom == 0){
    resy.PB(y);
  }
}

void dodaj(prze ak,set<prze> &s,int pom){
  debug("dodaj",ak.po,ak.ko, pom);
  int m = ak.mid();
  prze nowy = {ak.po, m - pom};
  if(nowy.len() > 0){
    debug("nowy:",nowy.po,nowy.ko);
    s.insert(nowy);
  }
  nowy = {m + pom + 1, ak.ko};
  if(nowy.len() > 0){
    debug("nowy2:",nowy.po,nowy.ko);
    s.insert(nowy);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  
#ifdef LOCAL
  int pom;
  cin >> pom;
  R(i,pom){
    int pom2;
    cin >> pom2;
    XX.PB(pom2);
  }
  
  cin >> pom;
  R(i,pom){
    int pom2;
    cin >> pom2;
    YY.PB(pom2);
  }
#endif
  R(_,100){
    int x = los(-lim, lim+1);
    int y = los(-lim, lim+1);
    int pom = ask(x,y);
  }
  
  a.insert({-lim,lim+1});
  b.insert({-lim,lim+1});
  
  while(SZ(a) || SZ(b)){
    if(SZ(a)){
      prze xx = *a.begin();
      assert(xx.po >= -lim && xx.ko <= lim + 1);
      a.erase(a.begin());
      int pom = ask(xx.mid(), ybez);
      sprx(xx.mid() - pom);
      sprx(xx.mid() + pom);
      dodaj(xx,a,pom);
    }
    if(SZ(b)){
      prze yy = *b.begin();
      assert(yy.po >= -lim && yy.ko <= lim + 1);
      b.erase(b.begin());
      int pom = ask(xbez, yy.mid());
      spry(yy.mid() - pom);
      spry(yy.mid() + pom);
      dodaj(yy,b,pom);
    }
  }
  
  cout << "1 " << SZ(resx) << " " << SZ(resy) << "\n";
  sort(ALL(resx));
  sort(ALL(resy));
  for(int ak:resx){
    cout << ak << " ";
  }
  cout << "\n";
  for(int ak:resy){
    cout << ak << " ";
  }
  cout << endl;
}