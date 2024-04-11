#include <cassert>
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

const int N = 101 * 1001;
int licznosc[N], lewo[N], prawo[N];
int wartosc[N];
map<PII,pair<LL,int> > mapa;
int parent[N];

void ustaw(PII p, LL val,int ktory){
  if (mapa.count(p) == 0 || mapa[p].ST < val) mapa[p] = MP(val,ktory);
}

int main(){
  int n;
  scanf("%d",&n);
  REP(i,n){
    scanf("%d %d %d %d",wartosc+i,licznosc+i,lewo+i,prawo+i);
  }

  REP(i,n){
    if (lewo[i] == 0){
      PII p = MP(lewo[i]+licznosc[i], prawo[i]);
      ustaw(p,wartosc[i],i);
      parent[i] = -1;
    } else {
      PII p = MP(lewo[i], prawo[i]+licznosc[i]);
      if (mapa.count(p)){
        pair<LL,int> old = mapa[p];
        LL kand = wartosc[i] + old.ST; 
        parent[i] = old.ND;
        ustaw(MP(lewo[i]+licznosc[i], prawo[i]), kand, i);
      }
    }
  }

  LL res = 0;
  int ktory = -1;

  FOREACH(it, mapa) if (it->ST.ND == 0 && it->ND.ST > res){
    res = it->ND.ST;
    ktory = it->ND.ND;
  }
//  printf("res = %lld\n", res);
  VI v;
  while (ktory >= 0){
    v.PB(ktory);
    ktory = parent[ktory];
  }
  reverse(ALL(v));
  printf("%d\n", SIZE(v));
  REP(i,SIZE(v)){
    if (i) printf(" ");
    printf("%d", v[i]+1);
  }
  puts("");
  return 0;
}