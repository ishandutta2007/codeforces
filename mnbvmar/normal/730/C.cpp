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
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

template<class C> void mini(C& a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C& a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h) {cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
  os << "["; for (auto v : V) os << v << ","; os << ']'; return os;
}

template<class L, class R> ostream &operator<<(ostream &os, pair<L, R> P ){
  return os << "(" << P.st << ", " << P.nd << ")";
}


#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int MAX = 5001;

int n,m;
vector<int> d[MAX];
vector<PII> sk[MAX];

void test(){
  int id,chce,kasa;
  cin >> id >> chce >> kasa;
  id--;
  debug("zap",id,chce,kasa);
  vector<int> s1,s2;
  vector<int> odw(n);
  auto dod = [&](int a){
    if(odw[a])return;
    odw[a] = 1;
    s2.PB(a);
  };
  multiset<PII> x;
  int mam = 0;
  int za_ile = 0;
  
  int odl = -1;
  dod(id);
  while(SZ(s2)){
    odl++;
    swap(s1,s2);
    s2.clear();
    for(int ak:s1){
      debug("dodaje",ak);
      for(int el:d[ak])
        dod(el);
      for(PII el:sk[ak]){
        x.insert(el);
        mam += el.SE;
        za_ile += el.FI * el.SE;
        while(mam > chce){
          el = *x.rbegin();
          x.erase(x.find(el));
          mam -= el.SE;
          za_ile -= el.FI * el.SE;
          debug("??");
          if(mam < chce){
            el.SE = chce - mam;
            mam = chce;
            za_ile += el.FI * el.SE;
            x.insert(el);
          }
        }
        if(chce == mam && za_ile <= kasa){
          cout << odl << "\n";
          return;
        }
      }
    }
  }
  cout << "-1\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  R(i,m){
    int a,b;
    cin >> a >> b;
    a--;b--;
    d[a].PB(b);
    d[b].PB(a);
  }
  int w;
  cin >> w;
  R(i,w){
    int a,il,cen;
    cin >> a >> il >> cen;
    a--;
    sk[a].PB({cen,il});
  }
  int q;
  cin >> q;
  while(q--)test();
}