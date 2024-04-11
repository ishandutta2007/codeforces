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
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
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


const int P = 1e9 + 7;
void add(int &a,int b){
  a += b;
  if(a >= P)
    a-=P;
}
void sub(int &a,int b){
  a -= b;
  if(a < 0)
    a += P;
}
int mul(int a,int b){
  return a * b % P;
}
int n;
struct info{
  vector<vector<int>> t;
  info(int x){
    t.resize(x,vector<int>(x,0));
  }
};

info lacz(info a,info b){
  info res(SZ(a.t) + SZ(b.t));
  R(i,SZ(a.t))R(j,SZ(a.t))R(ii,SZ(b.t))R(jj,SZ(b.t)){
    add(res.t[i + ii][j + jj], mul(a.t[i][j],b.t[ii][jj]));
    add(res.t[i + SZ(b.t)][j + jj + 1], mul(mul(a.t[i][j],b.t[ii][jj]),SZ(b.t) - ii));
  }
  return res;
}

const int MAX = 201;
int newt[MAX][MAX];
vector<int> d[MAX];
info dfs(int a,int oj){
  info pom(1);
  pom.t[0][0] = 1;
  for(int el:d[a])if(el != oj){
    pom = lacz(pom, dfs(el,a));
  }
  return pom;
}

int wyn[MAX];
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
  }
  info res = dfs(0,-1);
  R(i,n-1){
    R(j,n){
      add(wyn[i], mul(res.t[j][n - i - 1], n - j));
    }
    R(j,n-i-2){
      wyn[i] = mul(wyn[i],n);
    }
    cerr << wyn[i] << " ";
  }
  wyn[n-1] = 1;
  cerr << "\n";
  R(i,MAX)R(j,i+1){
    if(j == 0){
      newt[i][j] = 1;
    }else{
      newt[i][j] = newt[i-1][j];
      add(newt[i][j], newt[i-1][j-1]);
    }
  }
  debug("wtf");
  for(int i = n - 2; i >= 0; i--){
    for(int j = i + 1; j <= n-1; j++){
      sub(wyn[i], mul(newt[j][i],wyn[j]));
    }
  }
  R(i,n){
    cout << wyn[i] << " ";
  }
  cout << "\n";

}