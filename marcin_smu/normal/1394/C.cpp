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

const int inf = 1e7;
int maxB = -inf; 
int maxN = -inf;
int maxR = -inf;
int minB = inf; 
int minN = inf;
int minR = inf;
int glN = 123;
int licz2(int ilB,int ilN){
  int res = -inf;
  maxi(res, maxB - ilB);
  maxi(res, ilB - minB);
  maxi(res, maxN - ilN);
  maxi(res, ilN - minN);
  maxi(res, maxR - (ilB - ilN));
  maxi(res, (ilB - ilN) - minR);
  return res;
  
}
int licz1(int ilB){
  int poN = 0,koN = 1e6;
  while(poN + 10 < koN){
    int mN1 = (poN + koN) / 2;
    int mN2 = (poN + koN) / 2 + 2;
    int resmN1 = licz2(ilB,mN1);
    int resmN2 = licz2(ilB,mN2);
    if(resmN1 < resmN2){
      koN = mN2;
    }else{
      poN = mN1;
    }
  }
  int naj = inf;
  int resN = 345;
  for(int NN = poN; NN <= koN; NN++){
    int resNN = licz2(ilB,NN);
    if(resNN <= naj){
      naj = resNN;
      resN = NN;
    }
  }
  glN = resN;
  return naj;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int n;
  cin >> n;
  R(i,n){
    string s;
    cin >> s;
    int ilB = 0,ilN = 0;
    for(char z:s){
      if(z == 'B'){
        ilB++;
      }else{
        ilN++;
      }
    }
    maxi(maxB,ilB);
    maxi(maxN,ilN);
    maxi(maxR,ilB-ilN);
    
    mini(minB,ilB);
    mini(minN,ilN);
    mini(minR,ilB-ilN);
  }
  debug(minB,maxB,minN,maxN,minR,maxR);
  int poB = 0,koB = 1e6;
  while(poB + 10 < koB){
    int mB1 = (poB + koB) / 2;
    int mB2 = (poB + koB) / 2 + 2;
    int resmB1 = licz1(mB1);
    int resmB2 = licz1(mB2);
    if(resmB1 < resmB2){
      koB = mB2;
    }else{
      poB = mB1;
    }
  }
  int naj = inf;
  int resB = 234, resN = 123;
  for(int BB = poB; BB <= koB; BB++){
    int resBB = licz1(BB);
    if(resBB <= naj){
      naj = resBB;
      resB = BB;
      resN = glN;
    }
  }
  debug(naj,resB,resN);
 string res(resB,'B');
 res += string(resN,'N');
  cout << naj << "\n" << res << "\n";
  
}