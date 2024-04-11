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

const int MAX = 1001001;
const int P = 1e9 + 7;
int n,k;
int f[MAX],il[MAX],uz[MAX],cz[MAX];
int all[MAX];

void add(int &a,int b){
  a += b;
  if(a >= P)
    a -= P;
}

int find(int a){
  return f[a] == a ? a : f[a] = find(f[a]);
}
void uni(int a,int b){
  a = find(a);
  b = find(b);
  f[a] = b;
  il[b] += il[a];
  add(uz[b], uz[a]);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> k;
  vector<PII> x(n);
  R(i,n){
    cin >> x[i].FI;
    x[i].SE = i;
  }
  R(i,n + 2){
    if(i >= k){
      all[i] = all[i - k + 1];
    }
    add(all[i], i);
    f[i] = i;
    il[i] = 1;
    uz[i] = 1;
  }
  sort(ALL(x));
  int res = 0;
  R(i,n){
    int id = x[i].SE;
    if(id && cz[id-1]){
      uni(id,id-1);
    }
    if(cz[id+1]){
      uni(id,id+1);
    }
    cz[id] = 1;
    id = find(id);
    int pom = all[il[id]] - uz[id];
    if(pom < 0)pom += P;
    add(res, pom * x[i].FI % P);
    add(uz[id], pom);
  }
  cout << res << "\n";
}