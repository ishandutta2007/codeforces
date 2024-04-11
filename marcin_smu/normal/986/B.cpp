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

int losuj(int n,int m){
  vector<int> p(n);
  vector<int> vis(n);
  R(i,n)p[i] = i;
  R(i,m){
    int a = rand()%n;
    int b = rand()%n;
    if(a == b)i--;
    swap(p[a], p[b]);
  }
  int res = 0;
  
  R(i,n){
    if(vis[i] == 0){
      res ++;
      int ak = i;
      while(vis[ak] == 0){
        vis[ak] = 1;
        ak = p[ak];
      }
    }
  }
  return res;
}

void spr(int n){
  debug(n);
  R(i,10){
    cerr << losuj(n,3*n) << " ";
  }
  cerr << "\n";
  R(i,10){
    cerr << losuj(n,7*n+1) << " ";
  }
  cerr << "\n";

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
//   spr(1000);
//   spr(1001);
//   spr(100000);
//   spr(1000000);
  int n;
  cin >> n;
  vector<int> p(n);
  vector<int> vis(n);
  R(i,n){
    cin >> p[i];
    p[i]--;  
  }
  int res = 1;
  R(i,n){
    if(vis[i] == 0){
      res = !res;
      int ak = i;
      while(vis[ak] == 0){
        vis[ak] = 1;
        ak = p[ak];
      }
    }
  }
  if(res){
    cout << "Petr\n";
  }else{
    cout << "Um_nik\n";
  }
}