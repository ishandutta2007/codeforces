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

const int MAX = 200100;
int n;
vector<int> d[MAX];
set<int> dzieci[MAX];
bool cz[MAX];
int deg[MAX];
void wyn(int i){
  debug("wyn",i);
  if(SZ(dzieci[i]) > 2){
    cout << "-1\n";
  }else{
    int sum = 0;
    for(int el:dzieci[i])
      sum += el;
    while(sum%2 == 0)sum/=2;
    cout << sum << "\n";
  }
  exit(0);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  R(i,n-1){
    int a,b;
    cin >> a >> b;
    a--;b--;
    d[a].PB(b);
    d[b].PB(a);
    deg[a]++;
    deg[b]++;
  }
  vector<int> s1,s2;
  R(i,n){
    if(deg[i] == 1){
      s1.PB(i);
      dzieci[i].insert(0);
    }
  }
  while(SZ(s1)){
    swap(s1,s2);
    s1.clear();
    for(int el:s2){
      debug(el);
      if(deg[el] == 0){
        wyn(el);
      }
      cz[el] = 1;
      for(int nei:d[el]){
        if(cz[nei])continue;
        dzieci[nei].insert(*dzieci[el].begin()+1);
        deg[nei]--;
        if(deg[nei] == 1 && SZ(dzieci[nei]) == 1){
          s1.PB(nei);
        }
      }
    }
  }
  int il = 0;
  R(i,n)if(!cz[i])il++;
  if(il > 1){
    cout << "-1\n";
    return 0;
  }
  R(i,n){
    if(!cz[i]){
      wyn(i);
    }
  }
}