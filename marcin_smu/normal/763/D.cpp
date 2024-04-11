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

#define ULL unsigned long long

const int MAX = 1e5 + 7;
int res = 0;
int naj = -1;
int kt = 0;
map<ULL, int> kr;

void add(ULL x){
  if(1 == ++kr[x]){
    res++;
  }
}
void sub(ULL x){
  if(0 == --kr[x]){
    res--;
  }
}

ULL kw[MAX],cub[MAX],xo[MAX],ha[MAX];
vector<int> d[MAX];


ULL liczh(ULL a,ULL b,ULL c){
  return ((a ^ b) + (c * c * c) + 12344121) ^ 4372321658131;
}

void dfs2(int v,ULL nast,int oj){
  sub(ha[v]);
  debug(v,res);
  if(naj < res || (naj == res && rand() % 2)){
    naj = res;
    kt = v;
  }
  for(int el:d[v])if(el != oj){
    ULL h = ha[el];
    ULL pom = liczh(kw[v] - h*h + nast * nast,
                    cub[v] - h*h*h + nast * nast * nast,
                    xo[v] ^ h ^ nast);
    add(pom);
    dfs2(el,pom,v);
    sub(pom);
  }
  add(ha[v]);
}

ULL dfs(int v,int oj){
  for(int el:d[v])if(el != oj){
    ULL h = dfs(el,v);
    kw[v] += h * h;
    cub[v] += h * h * h;
    xo[v] ^= h;
  }
  ha[v] = liczh(kw[v],cub[v],xo[v]); 
  debug(v, ha[v]); 
  add(ha[v]);
  return ha[v];
}

int n;  
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  R(i,n)kw[i] = 432781477312874ll;
  R(i,n)cub[i] = 347582818888181ll;
  R(i,n)xo[i] = 4321478328667919ll;
  
  R(i,n-1){
    int a,b;
    cin >> a >> b;
    a--;b--;
    d[a].PB(b);
    d[b].PB(a);
  }
  dfs(0,-1);
  dfs2(0, 0,-1);
  debug(naj);
  cout << kt + 1 << "\n";
}