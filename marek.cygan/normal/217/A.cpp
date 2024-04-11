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

map<int,int> mapa[2];

int numer(int r, int x){
  if (mapa[r].count(x)) return mapa[r][x];
  int res = SIZE(mapa[r]);
  return mapa[r][x] = res;
}

const int N = 11000;
VI kraw[N];
int vis[N];

void dfs(int x){
  vis[x] = 1;
  FOREACH(it, kraw[x]) if (!vis[*it]) dfs(*it);
}

void dodaj(int a,int b){
  kraw[a].PB(b);
  kraw[b].PB(a);
}

int main(){
  int k;
  scanf("%d",&k);
  VPII v;
  REP(i,k){
    int a,b;
    scanf("%d %d",&a,&b);
    v.PB(MP(numer(0,a), numer(1,b)));
  }
  int n0=SIZE(mapa[0]), n1=SIZE(mapa[1]);
  FOREACH(it, v) dodaj(it->ST, it->ND+n0);
  int n = n0+n1;
  int res = -1;
  REP(i,n) if (!vis[i]){
    res++;
    dfs(i);
  }
  printf("%d\n", res);
  return 0;
}