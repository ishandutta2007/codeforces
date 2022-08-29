#pragma GCC optimize("O3")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// gp_hash_table<int, int> mapka;

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

const int MAX = 100010;
int t[MAX];
vector<vector<int>> res;
void rusz(int a,int krok){
  vector<int> pom = {a, a - krok, a - krok * 2};
  for(int el:pom){
    t[el-1]^=1;
  }
  res.PB(pom);
}

vector<vector<int>> res2;
void dodaj(int a,int krok){
  a++;
  vector<int> pom = {a, a + krok, a + krok * 2};
  for(int el:pom){
    t[el-1]^=1;
  }
  res2.PB(pom);
}
void usun(){
  vector<int> pom = res2.back();
  res2.pop_back();
  for(int el:pom){
    t[el-1]^=1;
  }
}
int n;
void licz(int i){
  if(i == n - 2){
    if(t[i] == 1 || t[i+1] == 1)return;
    cout << "YES\n";
    cout << SZ(res) + SZ(res2) << "\n";
    for(auto el : res){
      for(int pom : el){
        cout << pom << " ";
      }
      cout << "\n";
    }
    for(auto el : res2){
      for(int pom : el){
        cout << pom << " ";
      }
      cout << "\n";
    }
    exit(0);
  }
  if(t[i] == 0){
    licz(i+1);
    if(i + 6 < n){
      dodaj(i,1);
      dodaj(i,3);
      licz(i+1);
      usun();
      usun();
    }
  }else{
    dodaj(i,1);
    licz(i+1);
    usun();
    if(i + 6 < n){
      dodaj(i,3);
      licz(i+1);
      usun();
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  R(i,n){
    cin >> t[i];
  }
  while(n > 8){
    if(t[n-1] != 0){
      if(t[n-2] == 0){
        if(t[n-3] == 0){
          rusz(n,3);
        }else{
          rusz(n,2);
        }
      }else{
        if(t[n-3] == 1 || n < 12){
          rusz(n,1);
        }else{
          vector<int> pom;
          for(int i = 4; i <= 6; i++){
            if(t[n-i] == 1){
              pom.PB(i);
            }
          }
          if(SZ(pom) == 3){
            rusz(n,4);
            rusz(n-1,2);
          }else if(SZ(pom) == 1){
            rusz(n,pom[0]-1);
            rusz(n-1,5);//sprawdzic
          }else if(SZ(pom) == 0){
            rusz(n,4);
            rusz(n-1,3);
          }else{
            rusz(n,pom[1]-1);
            rusz(n-1,pom[0]-2);
          }
        }
      }
    }
    n--;
  }
  licz(0);
  cout << "NO\n";
}