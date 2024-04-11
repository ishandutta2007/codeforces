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

int query(vector<int> &x){
  if(SZ(x) <= 1)return 0;
  cout << "? " << SZ(x) << "\n";
  for(int ak:x){
    cout << ak + 1 << " ";
  }
  cout << endl;
  int res;
  cin >> res;
  return res;
}


vector<vector<int>> d;
vector<int> kol;
vector<int> cykl;
int dfs(int nr,int c){
  if(kol[nr] == 0){
    kol[nr] = c;
  }else{
    if(kol[nr] != c)return 1;
    return 0;
  }
  for(int el:d[nr]){
    int pom = dfs(el,3-c);
    if(pom){
      if(pom == 1){
        cykl.PB(el);
        if(nr == cykl[0])return 2;
        return 1;
      }
      return 2;
    }
  }
  return 0;
}
int n;
void nie(){
  debug(d);
  R(i,n){
    if(kol[i] == 0)dfs(i,1);
    if(SZ(cykl)){
      cout << "N " << SZ(cykl) << "\n";
      R(j,SZ(cykl)){
        cout << cykl[j] + 1 << " ";
      }
      cout << "\n";
      exit(0);
    }
  }
  assert(0);
}


bool get_edge(vector<int> &a,vector<int> &b){
  debug("get_edge",a,b);
  if(SZ(a) == 0 || SZ(b) == 0)return 0;
  vector<int> all;
  vector<int> a1;
  vector<int> a2;
  R(i,SZ(a)){
    if(i * 2 < SZ(a)){
      a1.PB(a[i]);
    }else{
      a2.PB(a[i]);
    }
    all.PB (a[i]);
  }
  vector<int> b1;
  vector<int> b2;
  R(i,SZ(b)){
    if(i * 2 < SZ(b)){
      b1.PB(b[i]);
    }else{
      b2.PB(b[i]);
    }
    
    all.PB (b[i]);
  }
  if(query(all) == 0)return 0;
  if(SZ(all) == 2){
    debug(all);
    d[all[0]].PB(all[1]);
    d[all[1]].PB(all[0]);
    return 1;
  }
  if(get_edge(a1,b1))return 1;
  if(get_edge(a1,b2))return 1;
  if(get_edge(a2,b1))return 1;
  if(get_edge(a2,b2))return 1;
  return 0;
}

struct bi{
  vector<int> a;
  vector<int> b;
  int ile;
  void lacz(bi &pom,int nile){
    ile = nile;
    bool aa = get_edge(a,pom.a);
    bool ab = get_edge(b,pom.a);
    bool ba = get_edge(a,pom.b);
    bool bb = get_edge(b,pom.b);
    if((aa || bb) && (ab || ba)){
      nie();
    }
    if(aa || bb){
      for(int el:pom.a){
        b.PB(el);
      }
      for(int el:pom.b){
        a.PB(el);
      }
    }else if(ab || ba){
      for(int el:pom.a){
        a.PB(el);
      }
      for(int el:pom.b){
        b.PB(el);
      }
    }else assert(0);
    debug(ile,a,b);
  }
};

vector<bi> x;

bool szu2(int po1,int ko1,int po2,int ko2){
  debug("szu2",po1,ko1,po2,ko2);
  vector<int> zap;
  int sum = 0;
  for(int i = po1; i < ko1; i++){
    for(int ak:x[i].a){
      zap.PB(ak);
    }
    for(int ak:x[i].b){
      zap.PB(ak);
    }
    sum += x[i].ile;
  }
  for(int i = po2; i < ko2; i++){
    for(int ak:x[i].a){
      zap.PB(ak);
    }
    for(int ak:x[i].b){
      zap.PB(ak);
    }
    sum += x[i].ile;
  }
  int res = query(zap);
  if(sum == res)return 0;
  if(po1 + 1 == ko1 && po2 + 1 == ko2){
    x[po1].lacz(x[po2],res);
    x[po2] = x.back();
    x.pop_back();
    return 1;
  }
  int m1 = (po1 + ko1) / 2;
  int m2 = (po2 + ko2) / 2;
  if(szu2(po1,m1,po2,m2))return 1;
  if(szu2(po1,m1,m2,ko2))return 1;
  if(szu2(m1,ko1,po2,m2))return 1;
  if(szu2(m1,ko1,m2,ko2))return 1;
  assert(0);
}

bool szu1(int po,int ko){
  debug("szu1",po,ko);
  vector<int> zap;
  int sum = 0;
  for(int i = po; i < ko; i++){
    for(int ak:x[i].a){
      zap.PB(ak);
    }
    for(int ak:x[i].b){
      zap.PB(ak);
    }
    sum += x[i].ile;
  }
  int res = query(zap);
  if(res == sum)return 0;
  int m = (po + ko) / 2;
  if(szu1(po,m))return 1;
  if(szu1(m,ko))return 1;
  assert(szu2(po,m,m,ko));
  return 1;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  x.resize(n);
  d.resize(n);
  kol.resize(n);
  R(i,n){
    x[i].a.PB(i);
  }
  while(szu1(0,SZ(x)));
  vector<int> res;
  R(i,SZ(x)){
    R(j,SZ(x[i].a)){
      res.PB(x[i].a[j]);
    }
  }
  cout << "Y " << SZ(res) << "\n";
  sort(ALL(res));
  R(i,SZ(res)){
    cout << res[i] + 1 << " ";
  }
  cout << endl;
}