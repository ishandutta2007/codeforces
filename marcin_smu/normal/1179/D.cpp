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

int po2(int a){
  return a * (a - 1) / 2;
}

const int MAX = 500100;
int n;
vector<int> d[MAX];
int siz[MAX];
int licz_siz(int v,int oj){
  siz[v] = 1;
  for(int el:d[v])if(el != oj){
    siz[v] += licz_siz(el, v);
  }
  debug(v, siz[v]);
  return siz[v];
}
int wyn = 1e18;
int res[MAX];
int eval(PII l,int x){
  return l.FI * x + l.SE; 
}
int licz_res(int v,int oj){
  debug(v, oj);
  if(SZ(d[v]) == 1){
    return res[v] = 0;
  }
  res[v] = 1e18;
  vector<PII> t;
  for(int el:d[v])if(el != oj){
    int pom = licz_res(el, v);
    mini(res[v], pom + po2(siz[v] - siz[el]));
    t.PB({siz[el],
          pom - siz[el] * n + po2(siz[el] + 1)});
  }
  sort(ALL(t),[](PII a,PII b){
    if(a.FI != b.FI){
      return a.FI > b.FI;
    }
    return a.SE < b.SE;
  });
  debug(v,t,oj);
  //ax + b
  vector<pair<PII,int> > stos;
  R(i,SZ(t)){
    debug(stos);
    if(i != 0){
      int po = 0;
      int ko = SZ(stos);
      while(po + 1 != ko){
        int m = (po + ko) / 2;
        if(stos[m].SE <= t[i].FI){
          po = m;
        }else{
          ko = m;
        }
      }
      mini(wyn, t[i].SE + eval(stos[po].FI, t[i].FI));
      debug(wyn);
    }
    while(SZ(stos) && 
      eval(stos.back().FI,stos.back().SE) >=
      eval(t[i], stos.back().SE)
    ){
      stos.pop_back();
    }
    debug("???", stos);
    if(stos.empty()){
      stos.PB({t[i],0});
    }else{
      int po = -1;
      int ko = n + 1;
      while(po + 1 != ko){
        int m = (po + ko) / 2;
        if(eval(stos.back().FI, m) > eval(t[i], m)){
          ko = m;
        }else{
          po = m;
        }
      }
      if(ko != n + 1){
        stos.PB({t[i], ko});
      }
    }
  }
  return res[v];
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  if(n == 2){
    cout << "2\n";
    return 0;
  }
  R(i,n-1){
    int a,b;
    cin >> a >> b;
    a--;b--;
    d[a].PB(b);
    d[b].PB(a);
  }
  int root = 0;
  while(SZ(d[root]) == 1){
    root++;
  }
  debug(root);
  licz_siz(root,-1);
  licz_res(root,-1);
  cout << po2(n)-wyn << "\n";
}