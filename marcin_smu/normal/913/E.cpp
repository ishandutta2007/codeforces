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

const int MAX = 1000;
string e[3][MAX];
set<pair<int,PII>> todo;
void add(int typ,int mb, string z){
  if(e[typ][mb] == "" || (SZ(e[typ][mb]) > SZ(z)) || (SZ(e[typ][mb]) == SZ(z) && z < e[typ][mb])){
//     if(e[typ][mb] == "" || (SZ(e[typ][mb]) > SZ(z))){
      todo.insert({SZ(z),MP(typ,mb)});
 //   }
   // debug(typ,mb,z);
    e[typ][mb] = z;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  add(2,15,"x");
  add(2, 3 + 3 * 16,"y");
  add(2, 1 + 4 + 16 + 64, "z");
  while(!todo.empty()){
    auto pom = *todo.begin();
    todo.erase(todo.begin());
    int typ = pom.SE.FI;
    int mb = pom.SE.SE;
    int dl = pom.FI;
    string z = e[typ][mb];
    if(SZ(z) != dl)continue;
  //  debug(typ,mb,z);
    if(typ == 0){
      add(2, mb, '(' + z + ')');
      R(mb2, 1 << 8){
        if(e[1][mb2] != ""){
          add(0, mb | mb2, z + '|' + e[1][mb2]);
        }
      }
    }else if(typ == 1){
      add(0, mb, z);
      
      R(mb2, 1 << 8){
        if(e[0][mb2] != ""){
          add(0, mb | mb2, e[0][mb2] + '|' + z);
        }
      }
      
      R(mb2, 1 << 8){
        if(e[2][mb2] != ""){
          add(1, mb & mb2, z + '&' + e[2][mb2]);
        }
      }
    }else{
      add(2, (~mb) & ((1<<8) - 1), '!' + z);
      add(1, mb, z);
      
      R(mb2, 1 << 8){
        if(e[1][mb2] != ""){
          add(1, mb & mb2, e[1][mb2] + '&' + z);
        }
      }
    }
  }
  int n;
  cin >> n;
  R(i,n){
    string z;
    cin >> z;
    int pom = 0;
    R(j,8){
      pom *= 2;
      pom += z[j] - '0';
    }
    cout << e[0][pom] << "\n";
  }
}