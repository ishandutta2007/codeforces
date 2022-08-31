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

set<int> male;
int n;
vector<int> blok;
vector<int> aa;
vector<int> ak;
vector<int> duzy;
vector<int> czymaly;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
#ifdef LOCAL
  int sq = 2;
#else
  int sq = 200;
#endif
  int q;
  cin >> n >> q;
  czymaly.resize(n + sq);
  aa.resize(n + sq);
  ak.resize(n + sq);
  duzy.resize(n + sq);
  blok.resize(n + sq);
  duzy[0] = 0;
  for(int i = 1; i < n; i++){
    cin >> aa[i];aa[i]--;
    if(i / sq == aa[i] / sq){
      male.insert(i);
      czymaly[i] = 1;
      ak[i] = aa[i];
      duzy[i] = duzy[aa[i]]; 
    }else{
      duzy[i] = i;
    }
  }
  male.insert(n * 2 + sq * 2);
  R(i,q){
    int typ;
    cin >> typ;
    if(typ == 1){
      int l,r,x;
      cin >> l >> r >> x;
      l--;
      auto xxx = male.lower_bound(l);
      int pier = l / sq + 1;
      int ost = r / sq;
      debug(pier,ost);
      if(pier > ost){
        for(int j = l; j < r; j++){
          aa[j] -= x;
        }
      }else{
        for(int j = pier; j < ost; j++){
          blok[j] += x;
          debug(j);
        }
        for(int j = l; j < pier * sq; j++){
          aa[j] -= x;
          debug(j,aa[j]);
        }
        for(int j = ost * sq; j < r; j++){
          debug(j,aa[j]);
          aa[j] -= x;
        }
      }
      
      while(*xxx < r){
        auto yyy = xxx; yyy ++;
        int pom = *xxx;
        ak[pom] -= x;
        if(ak[pom] < 0)ak[pom] = 0;
        if(pom / sq != ak[pom] / sq){
          czymaly[pom] = 0;
          male.erase(xxx);
          duzy[pom] = pom;
        }else{
          duzy[pom] = duzy[ak[pom]];
        }
        xxx = yyy;
      }
      int lim = ((r-1) / sq) * sq + sq;
      while(*xxx < lim){
        duzy[*xxx] = duzy[ak[*xxx]];
        xxx++;
      }
    }else{
      int a,b;
      cin >> a >> b;
      a--;b--;
      while(a != b){
        debug(a,b);
        if(a < b)swap(a,b);
        if(czymaly[a]){
          if(duzy[a] > b){
            a = duzy[a];
          }else{
            if(czymaly[b]){
              if(duzy[a] == duzy[b]){
                a = ak[a];
              }else{
                a = duzy[a];
                b = duzy[b];
              }
            }else{
              a = duzy[a];
            }
          }
        }else{
          debug("tu",aa[a],blok[a/sq]);
          a = max(0ll, aa[a] - blok[a/sq]);
        }
      }
      
      cout << a + 1 << "\n";
    }
  }
}