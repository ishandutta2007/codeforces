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
  return os << "(" << P.FI << "," << P.SE << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int MAX = 1e5 + 100;
int n,m,s,k;
vector<int> d[MAX];
vector<int> res[MAX];
int t[MAX];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m >> k >> s;
  R(i,n){
    cin >> t[i];
    t[i]--;
  }
  R(i,m){
    int a,b;
    cin >> a >> b;
    a--;b--;
    d[a].PB(b);
    d[b].PB(a);
  }
  R(kt,k){
    vector<int> s1,s2;
    vector<int> vis(n);
    R(i,n){
      if(t[i] == kt){
        s1.PB(i);
        vis[i] = 1;
      }
    }
    int odl = 0;
    while(SZ(s1)){
      for(int el:s1){
        res[el].PB(odl);
        for(int ak:d[el]){
          if(!vis[ak]){
            vis[ak] =1;
            s2.PB(ak);
          }
        }
      }
      odl++;
      swap(s1,s2);
      s2.clear();
    }
//     R(i,n){
//       debug(res[i]);
//     }
  }
  R(i,n){
    nth_element(res[i].begin(),res[i].begin()+s,res[i].end());
    int wyn = 0;
    R(j,s){
      wyn += res[i][j];
    }
    cout << wyn << " ";
  }
  cout << "\n";
}