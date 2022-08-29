#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define R(i,n) for(int i = 0; i < (n); i++)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
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

template<class T> ostream &operator<<(ostream& os, set<T> V) {
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

const int MAX = 10001;
int n,q;
int nn;
vector<int> to_add[(1 << 16) + 5];
bitset<MAX> res;
void dfs(int nr,bitset<MAX> x){
  debug(nr);
  for(int el:to_add[nr]){
    debug(x);
    x |= x << el;
  }
  if(nr < nn){
    dfs(nr * 2,x);
    dfs(nr * 2+1,x);
  }else{
    res |= x;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> q;
  nn = 1;while(nn <= n)nn *= 2;
  R(i,q){
    int l,r,x;
    cin >> l >> r >> x;
    l--;
    
    function<void(int,int,int)> add = [&](int nr, int po,int ko){
      if(po >= r || l >= ko)return;
      if(l <= po && ko <= r){
        to_add[nr].PB(x);
        return;
      }
      add(nr * 2, po , (po + ko)/ 2);
      add(nr * 2 + 1,(po + ko)/2, ko);
    };
    add(1,0,nn);
  }
  res[0] = 1;
  dfs(1,res);
  vector<int> wyn;
  R(i,n+1)if(i){
    if(res[i])wyn.PB(i);
  }
  cout << SZ(wyn) << "\n";
  for(int el:wyn){
    cout << el << " ";
  }
  cout << "\n";
}