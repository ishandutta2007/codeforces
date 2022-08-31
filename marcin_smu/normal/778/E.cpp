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

string a;
string t[1111];
int war[11];
vector<int> dp,dp2;
vector<int> kol;
vector<int> xx[11];
int n;
void dodaj(int el,int c){
  if(el < 10) debug("dodaj", el , c);
  int res = 0;
  int prze = 0;
  R(i,n){
    if(SZ(t[i]) > el || el < SZ(a)){
      int pom = (SZ(t[i]) > el ? t[i][el] : 0) + c;
      if(pom >= 10){
        prze ++;
        pom-=10;
      }
      res += war[pom];
    }     
  }
  if(el < 10)debug(res);
  R(i,n+1){
    if(el < 10)debug(prze,res);
    maxi(dp[prze], dp2[i] + res);
    if(i!=n){
      int x = kol[i];
      if(SZ(t[x]) > el || el < SZ(a)){
        int pom = (SZ(t[x]) > el ? t[x][el] : 0) + c;
        if(pom >= 10){
          prze --;
          pom-=10;
        }
        res -= war[pom];
      }
      
      int pom = (SZ(t[x]) > el ? t[x][el] : 0) + c + 1;
      if(pom >= 10){
        prze++;
        pom-=10;
      }
      res += war[pom];
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> a >> n;
  reverse(ALL(a));
  R(i,n){
    cin >> t[i];
    reverse(ALL(t[i]));
    for(char &el:t[i])el -= '0';
  }
  R(i,10){
    cin >> war[i];
  }
  R(i,n)kol.PB(i);
  dp.resize(n+1, -1e15);
  dp[0] = 0;
  R(i,1002){
    dp2.clear();
    swap(dp,dp2);
    dp.resize(n+1,-1e15);
    
    
    if(i < 4)debug("----------------------------", kol);
    int pom = SZ(a) > i ? a[i] - '0' : 0;
    if(pom == '?' - '0'){
      debug(" ????????????????????????????????");
      R(j,10){
        if(j != 0 || i != SZ(a) - 1)
          dodaj(i,j);
      }
    }else
      dodaj(i,pom);
    if(i < 4) debug(dp);
    R(j,11)xx[j].clear();
    for(int el:kol){
      int pom = SZ(t[el]) > i ? t[el][i] : 0;
      xx[pom].PB(el);
    }
    kol.clear();
    for(int j = 10;j>=0;j--)for(int el:xx[j])kol.PB(el);
  }
  int res = -1e15;
  for(int el:dp){
    maxi(res,el);
  }
  cout << res << "\n";
}