#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#pragma GCC optimize("O3")

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
// #define int LL
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

int ALFA = 0;
const int inf = 1e9;
const int MAX = 1e5 + 5;

string s;
int n;
struct lit{
  vector<int> gd;
  vector<int> nast;
  vector<int> pop;
  vector<int> kt;
  vector<int> xors;
  void preproc(){
    nast.resize(n+1,inf);
    pop.resize(n+1,-inf);
    kt.resize(n+1,inf);
    xors.PB(0);
    
    R(i,SZ(gd)){
      int el = gd[i];
      nast[el] = el;
      pop[el + 1] = el;
      kt[el] = i;
    }
    for(int i = SZ(nast) - 2; i>=0; i--){
      mini(nast[i],nast[i+1]);
    }
    for(int i = 0; i < SZ(pop) - 1; i++){
      maxi(pop[i+1],pop[i]);
    }
  }
  
  int get(int a,int b);
  
};
vector<lit> t;

gp_hash_table<int, int> res[MAX];
int licz(int l,int r){
  if(l == r)return 0;
  auto xxx = res[l].find(r);
  if(xxx != res[l].end())return xxx->SE;
  int nimb = 0;
  R(i,ALFA){
    int pom = t[i].nast[l];
    if(pom < r){
      int pom2 = t[i].pop[r];
      nimb |= 1 << (licz(l,pom) ^ licz(pom2 + 1, r) ^ t[i].get(pom,pom2));
    }
  }
  return res[l][r] = __builtin_ctz(~nimb);
}

int lit::get(int a,int b){
  if(a == b)return 0;
  a = kt[a];
  b = kt[b];
  while(SZ(xors) <= b){
    int i = SZ(xors);
    xors.PB(xors.back() ^ licz(gd[i-1]+1,gd[i]));
  }
  return xors[b] ^ xors[a];
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> s;
  n = SZ(s);
  R(i,n){
    if(s[i] - 'a' >= ALFA){
      ALFA = s[i] - 'a' + 1;
      t.resize(ALFA);
    }
    t[s[i] - 'a'].gd.PB(i);
  }
  R(i,ALFA){
    t[i].preproc();
  }
  int m;
  cin >> m;
  R(i,m){
    int l,r;
    cin >> l >> r;
    l--;
    cout << (licz(l,r) ? "Alice" : "Bob") << "\n";
  }
}