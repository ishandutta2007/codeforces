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

const int MAX = 51;
int m,n;
int sx[MAX],sy[MAX],tx[MAX],ty[MAX];
struct ruch{
  PII a,b;
};
vector<ruch> res;
void rusz(int nr,int dx,int dy){
  debug(nr,dx,dy);
  ruch pom;
  pom.a = MP(sx[nr],sy[nr]);
  sx[nr] += dx;
  sy[nr] += dy;
  pom.b = MP(sx[nr],sy[nr]);
  res.PB(pom);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  R(i,m){
    cin >> sx[i] >> sy[i];
  }
  R(i,m){
    cin >> tx[i] >> ty[i];
  }
  vector<int> px(m),py(m);
  R(i,m){
    px[i] = i;
    py[i] = i;
  }
  sort(ALL(px),[&](int a,int b){
    return sx[a] < sx[b];
  });
  R(kt,m){
    int i = px[kt];
    while(sx[i] > kt+1){
      rusz(i,-1,0);
    }
  }
  for(int kt = m-1; kt >= 0; kt--){
    int i = px[kt];
    while(sx[i] < kt+1){
      rusz(i,1,0);
    }
  }
  debug("krok1");
  sort(ALL(py),[&](int a,int b){
    return ty[a] < ty[b];
  });
  R(kt,m){
    int i = py[kt];
    while(sy[i] < kt+1){
      rusz(i,0,1);
    }
    while(sy[i] > kt+1){
      rusz(i,0,-1);
    }
  }
  
  debug("krok2");
  R(i,m){
    while(sx[i] < tx[i]){
      rusz(i,1,0);
    }
    while(sx[i] > tx[i]){
      rusz(i,-1,0);
    }
  }
  
  debug("krok3",sy[0],ty[0]);
  R(kt,m){
    int i = py[kt];
    while(sy[i] > ty[i]){
      rusz(i,0,-1);
    }
  }
  for(int kt = m-1; kt >= 0; kt--){
    int i = py[kt];
    while(sy[i] < ty[i]){
      rusz(i,0,1);
    }
  }
  cout << SZ(res) << "\n";
  for(auto el:res){
    cout << el.a.FI << " " << el.a.SE << " " << el.b.FI << " " << el.b.SE << "\n";
  }
  
}