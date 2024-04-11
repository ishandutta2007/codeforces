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

int io = 0;
vector<int> a,b;
vector<int> odl;
vector<int> pre,post;
vector<int> val;
vector<vector<PII>> d;
int n;
int root = 0;
void licz_odl(int v,int oj,int od){
  odl[v] = od;
  if(od > odl[root])root = v;
  for(PII el:d[v])if(el.FI != oj){
    licz_odl(el.FI,v,od+1);
  }
}

void ord(int v,int oj,int x){
  pre[v] = io;
  val[v] = x;
  io++;
  for(PII el:d[v])if(el.FI != oj){
    ord(el.FI, v, x^el.SE);
  }
  post[v] = io;
}
int nn;

vector<int> naj0;
vector<int> naj1;
vector<int> flip;

void ustaw(int i){
  naj0[i] = max(naj0[i * 2], naj0[i * 2 + 1]);
  naj1[i] = max(naj1[i * 2], naj1[i * 2 + 1]);
}
void flipuj(int i){
  flip[i]^=1;
  swap(naj0[i], naj1[i]);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  d.resize(n);
  pre.resize(n);
  post.resize(n);
  val.resize(n);
  a.resize(n);
  b.resize(n);
  odl.resize(n);
  R(i,n-1){
    int c;
    cin >> a[i] >> b[i] >> c;
    a[i]--;b[i]--;
    d[a[i]].PB({b[i],c});
    d[b[i]].PB({a[i],c});
  }
  root = 0;
  nn = 1;
  while(nn <= n) nn *= 2;
  naj0.resize(nn * 2);
  naj1.resize(nn * 2);
  flip.resize(nn * 2);
  
  int m;
  cin >> m;
  vector<int> zap(m);
  vector<int> out(m);
  R(i,m){
    cin >> zap[i];
    zap[i]--;
  }
  
  R(_,3){
    odl.resize(n);
    int xx = root;
    licz_odl(xx, -1, 0);
    if(_ == 0)continue;
    io = 0;
    ord(xx,-1,0);
    R(i,n){
      debug(i,pre[i]);
      if(val[i] == 0){
        naj0[pre[i] + nn] = odl[i];
        naj1[pre[i] + nn] = 0;
      }else{
        naj1[pre[i] + nn] = odl[i];
        naj0[pre[i] + nn] = 0;
      }
    }
    for(int i = nn-1;i > 0;i--){
      ustaw(i);
      flip[i] = 0;
    }
    R(i,m){
      int pom = zap[i];
      if(pre[a[pom]] < pre[b[pom]])swap(a[pom],b[pom]);
      int be = pre[a[pom]];
      int en = post[a[pom]];
      debug(be,en);
      function<void(int,int,int)> rec = [&](int v,int po,int ko){
        if(po >= en || be >= ko)return;
        if(be <= po && ko <= en){
          flipuj(v);
          return;
        }
        if(flip[v]){
          flipuj(v * 2);
          flipuj(v * 2 + 1);
          flip[v] = 0;
        }
        rec(v * 2, po, (po + ko) / 2);
        rec(v * 2 + 1, (po + ko) / 2, ko);
        ustaw(v);
      };
      rec(1,0,nn);
      maxi(out[i], naj0[1]);
    }
    debug(xx,out);
  }
  R(i,m){
    cout << out[i] << "\n";
  }
}