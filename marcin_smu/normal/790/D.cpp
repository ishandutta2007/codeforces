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

const int MAX = 3e5 + 100;
int n;
int t[3][MAX];

vector<PII> licz(int *k){
  map<int,int> x;
  vector<PII> res;
  int sum = 0;
  R(i,n){
    debug(k[i]);
    x[sum] = i;
    sum += k[i];
    auto xxx = x.find(sum);
    if(xxx != x.end()){
      debug("??");
      int pom = xxx->SE;
      if(!SZ(res) || res.back().FI < pom){
        res.PB({pom, i + 1});
      }
    }
  }
  return res;
}

vector<PII> a,b,c;
map<pair<PII,int>, int> pam;
int szu(vector<PII>& x,int co){
  int po = -1, ko = SZ(x);
  while(po + 1 != ko){
    int m = (po + ko) / 2;
    if(x[m].FI >= co){
      ko = m;
    }else
      po = m;
  }
  return ko;
}
int licz(int i,int j,int k){
  if(i == SZ(a) && j == SZ(b) && k == SZ(c))return 0;
  auto xxx = pam.find({{i,j},k});
  if(xxx != pam.end())return xxx->SE;
  int &res = pam[{{i,j},k}];
  if(i < SZ(a) || j < SZ(b)){
    if(j == SZ(b) || (i != SZ(a) && a[i].SE < b[j].SE)){
      maxi(res, 1 + licz(szu(a, a[i].SE), j, szu(c, a[i].SE)));
    }else
      maxi(res, 1 + licz(i, szu(b, b[j].SE), szu(c, b[j].SE)));
  }
  if(k < SZ(c)){
    maxi(res, 1 + licz(szu(a, c[k].SE), szu(b, c[k].SE), szu(c, c[k].SE)));
  }
  return res;
}



int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  R(i,2){
    R(j,n){
      cin >> t[i][j];
      t[2][j] += t[i][j];
    }
  }
  a = licz(t[0]);
  b = licz(t[1]);
  c = licz(t[2]);
  debug(a, b, c);
  cout << licz(0,0,0) << "\n";
}