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

map<int,vector<PII>> mapka;
map<PII,int> res;

PII normuj(int x,int y){
  int pom = __gcd(x, y);
  return {x/pom, y/pom};
}

void add(vector<PII>& x,PII a){
  for(PII el:x){
    res[normuj(el.FI + a.FI, el.SE + a.SE)] += 2;
  }
  res[normuj(a.FI,a.SE)]++;
  x.PB(a);
}
void rem(vector<PII>& x,PII a){
  R(i,SZ(x)){
    if(x[i] == a){
      x[i] = x.back();
      x.pop_back();
      break;
    }
  }
  res[normuj(a.FI,a.SE)]--;  
  for(PII el:x){
    res[normuj(el.FI + a.FI, el.SE + a.SE)] -= 2;
  }
}

int n;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  int size = 0;
  R(i,n){
    int t,x,y;
    cin >> t >> x >> y;
    if(t == 1){
      size++;
      add(mapka[x * x + y * y], {x,y});
    }else if(t == 2){
      size--;
      rem(mapka[x * x + y * y], {x,y});
    }else{
      cout << size - res[normuj(x,y)] << "\n";
    }
  }
}