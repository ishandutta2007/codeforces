#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <numeric>
#include <cmath>
using namespace std;

typedef vector <int > VI;
typedef vector < VI > VVI;
typedef long long LL;
typedef vector < LL > VLL;
typedef vector < double > VD;
typedef vector < string > VS;
typedef pair<int,int> PII;
typedef vector <PII> VPII;
typedef istringstream ISS;

#define ALL(x) x.begin(),x.end()
#define REP(i,n) for (int i=0; i<(n); ++i)
#define FOR(var,pocz,koniec) for (int var=(pocz); var<=(koniec); ++var)
#define FORD(var,pocz,koniec) for (int var=(pocz); var>=(koniec); --var)
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define PB push_back
#define PF push_front
#define MP(a,b) make_pair(a,b)
#define ST first
#define ND second
#define SIZE(x) (int)x.size()

const int N = 101000;
const LL P = 143235139LL;
int t[N];
LL hasz[N];
LL potega[N];
VI byly[N];
int cotobylo[N];

map<int,int> mapa;

int numer(int x){
  if (mapa.count(x)) return mapa[x];
  int res = SIZE(mapa);
  cotobylo[res] = x;
  return mapa[x] = res;
}

LL daj_hasz(int a,int d){
  return hasz[a] - hasz[a+d] * potega[d];
}

int pasuje(int a,int b,int d){
  return daj_hasz(a,d) == daj_hasz(b,d);
}

int main(){
  int n;
  scanf("%d",&n);
  REP(i,n) scanf("%d",t+i), t[i] = numer(t[i]);
  potega[0] = 1;
  FOR(i,1,N-1) potega[i] = potega[i-1] * P;
  FORD(i,n-1,0) hasz[i] = hasz[i+1] * P + t[i];

  set<PII> zbior;

  REP(i,n){
    FOREACH(it, byly[t[i]]){
      int d = i - *it;
      if (*it-d+1>=0 && pasuje(*it-d+1, *it+1, d)) zbior.insert(MP(d,*it-d+1));
    }
    byly[t[i]].PB(i);
  }

//  FOREACH(it, zbior) cout << it->ST << " " << it->ND << " " ;
//  puts("");

  int beg = 0;
  while (!zbior.empty()){
    PII p = *zbior.begin();
    zbior.erase(zbior.begin());
    if (p.ND >= beg){
      beg = p.ND+p.ST;
    }
  }

  printf("%d\n", n-beg);
  FOR(i,beg,n-1){
    if (i > beg) printf(" ");
    printf("%d", cotobylo[t[i]]);
  }
  puts("");
  return 0;
}