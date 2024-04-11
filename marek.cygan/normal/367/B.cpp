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

map<int,int> mapa;
map<int,int> mapab;

const int N = 210 * 1001;
int a[N], b[N];

int zle = 0;
int dobre = 0;

void dodaj(int x){
  if (mapab.count(x)) {
    if (mapa[x] == mapab[x]) dobre--;
    mapa[x]++;
    if (mapa[x] == mapab[x]) dobre++;
  } else {
    zle++;
  }
}

void usun(int x){
  if (mapab.count(x)) {
    if (mapa[x] == mapab[x]) dobre--;
    mapa[x]--;
    if (mapa[x] == mapab[x]) dobre++;
  } else {
    zle--;
  }
}

int dobrze() {
  return zle == 0 && dobre == SIZE(mapab);
}

int main(){
  int n,m,p;
  scanf("%d %d %d",&n,&m,&p);
  REP(i,n) scanf("%d",a+i);
  REP(i,m){
    scanf("%d",b+i);
    mapab[b[i]]++;
  }
  
  VI res;

  for (int off = 0; off < min(p, n); off++) {
    int i, j;
    int mam = 0;
    i = j = off;
    while (i < n) {
      while (j < n && mam < m) {
        dodaj(a[j]);
        j += p;
        mam++;
      }
      if (mam == m && dobrze()) res.PB(i);
      usun(a[i]); i += p; mam--;
    }
  }

  sort(ALL(res));
  printf("%d\n", SIZE(res));
  FOREACH(it, res) printf("%d ",*it+1); puts("");
  return 0;
}