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

char **mapa;
char **oldmapa;
int ****fu;
int n,m;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

inline int between(int a,int b,int c){
  return a >= b && a <= c;
}

void idz(int &a,int &b,int r){
  if (!between(a,0,n-1) || !between(b,0,m-1)) return;
  if (mapa[a][b] != '.') return;
  int olda = a, oldb = b;

  if (fu[r][a][b][0] == a && fu[r][a][b][1] == b){
    a += dx[r];
    b += dy[r];
  } else {
    a = fu[r][olda][oldb][0];
    b = fu[r][olda][oldb][1];
  }

  idz(a,b,r);
  fu[r][olda][oldb][0] = a;
  fu[r][olda][oldb][1] = b;
}

int main(){
  scanf("%d %d",&n,&m);
  mapa = new char*[n+10];
  REP(i,n+10) mapa[i] = new char[m+10];

  oldmapa = new char*[n+10];
  REP(i,n+10) oldmapa[i] = new char[m+10];

  fu = new int***[4];
  REP(r,4){
    fu[r] = new int**[n];
    REP(i,n){
      fu[r][i] = new int*[m];
      REP(j,m) fu[r][i][j] = new int[2];
    }
  }

  REP(i,n) scanf("%s",mapa[i]);
  int best = 0, ruchy = 0;
  REP(aa,n) REP(bb,m){
    REP(i,n) REP(j,m) oldmapa[i][j] = mapa[i][j];

    REP(ruch,4) REP(i,n) REP(j,m) fu[ruch][i][j][0] = i, fu[ruch][i][j][1] = j;
    int kand = 0;
    int a = aa, b = bb;
    while (between(a,0,n-1) && between(b,0,m-1) && mapa[a][b] != '.'){
      kand++;
      int r;
      if (mapa[a][b] == 'L') r = 0;
      else if (mapa[a][b] == 'R') r = 1;
      else if (mapa[a][b] == 'U') r = 2;
      else r = 3;
      mapa[a][b] = '.';

      idz(a,b,r);
    }
    if (kand > best) best = kand, ruchy = 1;
    else if (kand == best) ruchy++;

    REP(i,n) REP(j,m) mapa[i][j] = oldmapa[i][j];
  }
  printf("%d %d\n",best,ruchy);
  return 0;
}