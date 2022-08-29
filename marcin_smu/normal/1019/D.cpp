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

const int MAX = 2010;
int n,S;
struct odc{
  int x,y;
  int a,b;
};
vector<odc> t; 
int x[MAX],y[MAX];
vector<int> pts;
vector<int> gd;
void pri(int v){
  cout << x[v] << " " << y[v] << "\n";
}
int spr(int a,int b,int c){
  int area = abs((x[b] - x[a]) * (y[c] - y[a]) -
                 (x[c] - x[a]) * (y[b] - y[a]));
  if(area == S){
    cout << "Yes\n";
    pri(a);
    pri(b);
    pri(c);
    exit(0);
  }
  return area < S;
}
void szu(int a,int b,int po,int ko){
  while(abs(po - ko) != 1){
    int m = (po + ko) / 2;
    if(spr(a,b,pts[m])){
      ko = m;
    }else{
      po = m;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> S;S*=2;
  pts.resize(n);
  gd.resize(n);
  R(i,n){
    pts[i] = i;
    cin >> x[i] >> y[i];
  }
  sort(ALL(pts), [](int a,int b){
    if(x[a] != x[b])
      return x[a] < x[b];
    return y[a] < y[b];
  });
  R(i,n){
    gd[pts[i]] = i;
  }
  R(i,n)R(j,i){
    odc pom{x[i] - x[j],y[i] - y[j], j, i};
    if(pom.x < 0 || (pom.x == 0 && pom.y < 0)){
      pom.x *= -1;
      pom.y *= -1;
      swap(pom.a,pom.b);
    }
    t.PB(pom);
  }
  sort(ALL(t),[](const odc& a,const odc& b){
    return a.x * b.y < a.y * b.x;
  });
  for(auto el:t){
    szu(el.a,el.b,-1,gd[el.a]);
    szu(el.a,el.b,n,gd[el.b]);
    assert(gd[el.a] + 1 == gd[el.b]);
    swap(gd[el.a], gd[el.b]);
    pts[gd[el.a]] = el.a;
    pts[gd[el.b]] = el.b;
  }
  cout << "No\n";
}