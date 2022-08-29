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

const int ALFA = 'z' - 'a' + 1;
struct Aho{
  vector<VI> t;
  VI ds, kt;
  vector<set<int>> gd;
  Aho():t(1, VI(ALFA)), ds(1), kt(1,-1), gd(1){}
  int new_node(){
    t.PB(VI(ALFA));
    ds.PB(0);
    kt.PB(-1);
    gd.PB({});
    return SZ(ds) - 1;
  }
  void add(VI &a,int i){
    int ak = 0;
    for(int z:a){
      if(t[ak][z] == 0){
        t[ak][z] = new_node();
      }
      ak = t[ak][z];
    }
    kt[ak] = i;
  }
  void add(string &z,int i){
    vector<int> pom;
    for(char el:z) pom.PB(el - 'a');
    add(pom,i);
  }
  vector<int> todo{0};
  void aho(){
    R(i,SZ(todo)){
      int v = todo[i];
      //il[v] += il[ds[v]];
      R(a,ALFA){
        if(t[v][a]){
          ds[t[v][a]] = v ? t[ds[v]][a] : 0;
          todo.PB(t[v][a]);
        }else
          t[v][a] = t[ds[v]][a];
      }
    }
  }
  int licz(VI &a){
    int res = 0, ak = 0;
    R(i,SZ(a)){
      int el = a[i];
      ak = t[ak][el];
      gd[ak].insert(i);
    }
    return res;
  }
  int licz(string& z){
    VI pom;
    for(char el:z)pom.PB(el - 'a');
    return licz(pom);
  }
  void go();
  
};

int liczres(set<int>& secik,int il){
  if(SZ(secik) < il)return -1;
  auto xxx = secik.begin();
  R(i,il-1)xxx++;
  auto yyy = secik.begin();
  int res = 1e9;
  while(xxx != secik.end()){
    mini(res,*xxx - *yyy);
    xxx++;
    yyy++;
  }
  return res;
}

void lacz(set<int> &a,set<int> &b){
  if(SZ(a) < SZ(b))swap(a,b);
  for(int el:b)a.insert(el);
  set<int> pom;
  swap(b,pom);
}

const int MAX = 100100;
string z;
int n;
Aho aho;
int il[MAX],res[MAX];

void Aho::go(){
  reverse(ALL(todo));
  for(int ak:todo)if(ak){
    if(kt[ak] != -1){
      int x = liczres(gd[ak],il[kt[ak]]);
      if(x == -1){
        res[kt[ak]] = -1;
      }else{
        res[kt[ak]] += x;
      }
    }
    if(ds[ak] != 0)
      lacz(gd[ds[ak]],gd[ak]);
  }  
      
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> z >> n;
  R(i,n){
    string pom;
    cin >> il[i] >> pom;
    res[i] = SZ(pom);
    aho.add(pom,i);
  }
  aho.aho();
  aho.licz(z);
  aho.go();
  R(i,n){
    cout << res[i] << "\n";
  }
}