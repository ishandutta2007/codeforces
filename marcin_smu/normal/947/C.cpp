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

const int MAX = 301001;

int n;
struct node{
  int il;
  node *r,*l;
  node():il(0),r(0),l(0){};
  ~node(){
    delete l;
    delete r;
  }
}*root;
int a[MAX];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  R(i,n){
    cin >> a[i];
  }
  root = new node();
  R(i,n){
    int pom;
    cin >> pom;
    node* ak = root;
    for(int j = 30; j >= 0; j--){
      if((pom >> j)&1){
        if(!ak->r){
          ak->r = new node();
        }
        ak = ak->r;
      }else{
        if(!ak->l){
          ak->l = new node();
        }
        ak = ak->l;
      }
      ak->il++;
    }
  }
  R(i,n){
    node* ak = root;
    for(int j = 30; j >= 0; j--){
      bool right = (a[i] >> j)&1;
      if(right && (!ak->r || ak->r->il == 0))right = 0;
      if(!right && (!ak->l || ak->l->il == 0))right = 1;
      if(right){
        a[i] ^= 1ll << j;
        ak = ak->r;
      }else{
        ak = ak->l;
      }
      assert(ak);
      ak->il--;
    }
    cout << a[i] << " ";
  }
  cout << "\n";
}