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


vector<PII> hist;
vector<int> f,siz;
vector<int> par;
PII find(int a){
  int res = 0;
  while(f[a] != a){
    res ^= par[a];
    a = f[a];
  }
  return {a,res};
}
bool uni(int a,int b){
  int para,parb;
  tie(a, para) = find(a);
  tie(b, parb) = find(b);
  if(a == b){
    if(para == parb)return 0;
    return 1;
  }
  if(siz[a] > siz[b])swap(a,b);
  f[a] = b;
  if(para == parb)
    par[a] = 1;
  siz[b] += siz[a];
  hist.PB({a,b});
  return 1;
}

void cof(){
  int a,b;
  tie(a,b) = hist.back();
  hist.pop_back();
  siz[b] -= siz[a];
  par[a] = 0;
  f[a] = a;
}

void cofaj(int mom){
  while(SZ(hist) != mom)cof();
}
vector<int> a,b;
vector<int> res;
void ple(int po, int ko){
  debug(po,ko,res[ko]);
  if(po == ko)return;
  int m = (po + ko) / 2;
  int mom = SZ(hist);
  for(int i = po; i < m; i++){
    uni(a[i],b[i]);
  }
  int mom2 = SZ(hist);
  for(int i = res[ko];1;i--){
    if(m == 2)debug(i,f);
    if(!uni(a[i],b[i])){
      res[m] = i;
      break;
    }
  }
  cofaj(mom2);
  uni(a[m],b[m]);
  ple(m+1,ko);
  cofaj(mom);
  for(int i = res[m] + 1;i <= res[ko];i++){
    uni(a[i],b[i]);
  }
  ple(po,m);
  cofaj(mom);
}
int n,m,q;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m >> q;
  a.resize(m);
  b.resize(m);
  res.resize(m + 1, -1);
  f.resize(n);
  siz.resize(n);
  par.resize(n);
  R(i,n){
    f[i] = i;
    siz[i] = 1;
  }
  R(i,m){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  int ost = -1;
  R(i,m){
    if(!uni(a[i],b[i])){
      ost = i;
      break;
    }
  }
  if(ost == -1){
    R(i,q){
      cout << "NO\n";
    }
    return 0;
  }
  for(int i = m-1;i >= 0; i--){
    if(!uni(a[i],b[i])){
      res[ost] = i;
      break;
    }
  }
  debug(res[ost]);
  cofaj(0);
  for(int i = res[ost] + 1; i < m; i++){
    uni(a[i],b[i]);
  }
  ple(0,ost);
  R(i,q){
    int l,r;
    cin >> l >> r;
    l--;
    if(res[l] >= r || res[l] == -1){
      cout << "YES\n";
    }else{
      cout << "NO\n";
    }
  }
}