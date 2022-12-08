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

inline PII para(int a,int b){
  if (a > b) swap(a,b);
  return MP(a,b);
}

int res = 0; //xor

int licz_zostalo(VPII v, int n){
  sort(ALL(v));
  int last = 0;
  int zostalo = 0;
  FOREACH(it, v){
    if (it->ST <= last) last = max(last, it->ND);
    else{
      zostalo += it->ST - last;
      last = it->ND;
    }
  }
  zostalo += n-last;
  return zostalo;
}

int gdzie_siega(VPII v, int chce){
  sort(ALL(v));
  int last = 0;
  FOREACH(it, v){
    if (it->ST <= last) last = max(last, it->ND);
    else {
      if (it->ST - last >= chce){
        return last + chce;
      } else chce -= it->ST - last;
      last = it->ND;
    }
  }
  return last + chce;
}

PII ciecie1, ciecie2;

//kod dla pionowych
int przetworz(vector<pair<int,PII> > v, int n, int m, int odetnij = 0){
  sort(ALL(v));
  int pos = 0;
  int last = 0;
  while (pos < SIZE(v)){
    if ((v[pos].ST-1 - last)%2) {
      int cel = odetnij ^ n;
      if (odetnij && cel < n){
        ciecie1 = MP(0,last+1);
        ciecie2 = MP(n-cel,last+1);
        return 1;
      }
      res ^= n;
    }
    int pos2 = pos+1;
    while (pos2 < SIZE(v) && v[pos2].ST == v[pos].ST) pos2++;
    VPII pom;
    FOR(i,pos,pos2-1) pom.PB(v[i].ND);
    int zostalo = licz_zostalo(pom, n);
    res ^= zostalo;

    int cel = odetnij ^ zostalo;
    if (cel < zostalo){
      int x = gdzie_siega(pom,cel);
      ciecie1 = MP(x,v[pos].ST);
      ciecie2 = MP(n,v[pos].ST);
      return 1;
    }

    last = v[pos].ST;
    pos = pos2;
  }
  if ((m-1-last)%2) {
    res ^= n;
    int cel = odetnij ^ n;
    if (odetnij && cel < n){
      ciecie1 = MP(0,last+1);
      ciecie2 = MP(n-cel,last+1);
      return 1;
    }
  }
  return 0;
}

int main(){
  int n,m,k;
  scanf("%d %d %d",&n,&m,&k);
  vector<pair<int,PII> > poziome, pionowe;
  REP(i,k){
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if (a == c) poziome.PB(MP(a,para(b,d)));
    else pionowe.PB(MP(b,para(a,c)));
  }
  przetworz(pionowe,n,m);
  przetworz(poziome,m,n);
  if (res == 0) printf("SECOND\n");
  else {
    printf("FIRST\n");
    int odetnij = res;
    if (przetworz(pionowe,n,m,odetnij)){
    } else {
      przetworz(poziome,m,n,odetnij);
      swap(ciecie1.ST, ciecie1.ND);
      swap(ciecie2.ST, ciecie2.ND);
    }
    printf("%d %d %d %d\n", ciecie1.ST, ciecie1.ND, ciecie2.ST, ciecie2.ND);
  }
  return 0;
}