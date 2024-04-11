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

const int MAX = 3e5;
int n,m,s;

vector<int> d2[MAX];
int gl[MAX];
int res = 0;
int dfs(int a){
  int siz = 1;
  for(int ak:d2[a])
    siz += dfs(ak); 
  if(a != s)maxi(res,siz);
  return siz;
}

vector<int> jp[MAX];

int skocz(int x,int il){
  int k = 0;
  while(il){
    if(il & 1){
      x = jp[x][k];
    }
    il/=2;
    k++;
  }
  return x;
}

int lca(int a,int b){
  if(gl[a] < gl[b]){
    b = skocz(b, gl[b] - gl[a]);
  }
  if(gl[a] > gl[b]){
    a = skocz(a, gl[a] - gl[b]);
  }
  
  for(int i = SZ(jp[a]); i > 0; i--){
    if(SZ(jp[a]) > i){
      if(jp[a][i] != jp[b][i]){
        a = jp[a][i];
        b = jp[b][i];
      }
    }
  }
  while(a != b){
    a = jp[a][0];
    b = jp[b][0];
  }
  return a;
}


int odl[MAX];
vector<PII> d[MAX];
vector<int> topo;
int dom[MAX];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m >> s;s--;
  R(i,m){
    int a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    d[a].PB({b,c});
    d[b].PB({a,c});
  }
  R(i,n)odl[i] = 1e18;
  set<PII> secik;
  auto add = [&](int v,int od){
    if(od < odl[v]){
      odl[v] = od;
      secik.insert({od,v});
    }
  };
  add(s,0);
  while(!secik.empty()){
    int nr,od;
    auto xxx = secik.begin();
    tie(od,nr) = *xxx;
    secik.erase(xxx);
    if(odl[nr] != od)continue;
    debug(nr, odl[nr]);
    if(nr!=s)topo.PB(nr);
    for(PII el:d[nr]){
      add(el.FI, od + el.SE);
    }
  }
  for(int ak:topo){
    vector<int> pom;
    for(PII el:d[ak]){
      if(odl[ak] == odl[el.FI] + el.SE){
        pom.PB(el.FI);
      }
    }
    debug(ak,pom);
    int dom;
    R(i,SZ(pom)){
      if(i)
        dom = lca(dom,pom[i]);
      else
        dom = pom[i];
    }
    gl[ak] = gl[dom] + 1;
    d2[dom].PB(ak);
    jp[ak].PB(dom);
    while(jp[jp[ak].back()].size() >= jp[ak].size()){
      jp[ak].PB(jp[jp[ak].back()][jp[ak].size()-1]);
    }
  }
  dfs(s);
  cout << res << "\n";
}