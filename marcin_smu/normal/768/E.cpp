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

map<pair<int,vector<int>>,int> pam;
int licz(int n,vector<int> zak){
  sort(ALL(zak));
  while(zak.back() > n)zak.pop_back();
  auto xxx = pam.find({n,zak});
  if(xxx != pam.end())return xxx->SE;
  int &res = pam[{n,zak}];
  vector<int> pom;
  int j = 0;
  R(i,n+1){
    if(j < SZ(zak) && zak[j] == i){
      j ++;
    }else{
      zak.PB(i);
      pom.PB(licz(n - i, zak));
      zak.pop_back();
    }
  }
  sort(ALL(pom));
  res = 0;
  for(int ak:pom){
    if(ak == res)res++;
  }
  return res;
}

int nimb[62];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  //~ R(i,61){
    //~ cout << "nimb[" << i << "]=" << licz(i,{0}) << ";\n";
  //~ }
  nimb[1]=1;
nimb[2]=1;
nimb[3]=2;
nimb[4]=2;
nimb[5]=2;
nimb[6]=3;
nimb[7]=3;
nimb[8]=3;
nimb[9]=3;
nimb[10]=4;
nimb[11]=4;
nimb[12]=4;
nimb[13]=4;
nimb[14]=4;
nimb[15]=5;
nimb[16]=5;
nimb[17]=5;
nimb[18]=5;
nimb[19]=5;
nimb[20]=5;
nimb[21]=6;
nimb[22]=6;
nimb[23]=6;
nimb[24]=6;
nimb[25]=6;
nimb[26]=6;
nimb[27]=6;
nimb[28]=7;
nimb[29]=7;
nimb[30]=7;
nimb[31]=7;
nimb[32]=7;
nimb[33]=7;
nimb[34]=7;
nimb[35]=7;
nimb[36]=8;
nimb[37]=8;
nimb[38]=8;
nimb[39]=8;
nimb[40]=8;
nimb[41]=8;
nimb[42]=8;
nimb[43]=8;
nimb[44]=8;
nimb[45]=9;
nimb[46]=9;
nimb[47]=9;
nimb[48]=9;
nimb[49]=9;
nimb[50]=9;
nimb[51]=9;
nimb[52]=9;
nimb[53]=9;
nimb[54]=9;
nimb[55]=10;
nimb[56]=10;
nimb[57]=10;
nimb[58]=10;
nimb[59]=10;
nimb[60]=10;
int n;
  cin >> n;
  int res = 0;
  R(i,n){
    int pom;
    cin >> pom;
    res ^= nimb[pom];
  }
  cout << (res ? "NO\n" : "YES\n");
}