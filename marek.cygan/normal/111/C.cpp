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

const int N = 70;
int t[N][N][N]; //(wiersz,mozna wysylac,spadaja)

int main(){
  int n,m;
  scanf("%d %d",&n,&m);
  if (m > n) swap(n,m);
  int ile = 1<<m;
  REP(i,n+2) REP(mask,ile) REP(mask2,ile) t[i][mask][mask2] = -N;
  t[0][0][0] = 0;

  REP(i,n) REP(mask,ile) REP(mask2,ile) if (t[i][mask][mask2] >= 0){
//    printf("i=%d mask=%d mask2=%d t=%d\n",i,mask,mask2,t[i][mask][mask2]);
    REP(zostaly,ile)
      REP(mask3,ile){ //nowe spadaja
        int ok = 1;
        int wolne = 0;
        REP(j,m) if (!(zostaly&(1<<j))) {
          if (mask2&(1<<j)){
            //spadlo a nic nie ma
            ok = 0;
            break;
          }
          if ((mask&(1<<j))==0 
              && (mask3&(1<<j))==0 
              && (j==0 || (zostaly&(1<<(j-1)))==0) 
              && (j==m-1 || (zostaly&(1<<(j+1)))==0)){
            ok = 0;
            break;
          }
          wolne++;
        }
        if (ok) t[i+1][zostaly][mask3] = max(t[i+1][zostaly][mask3], t[i][mask][mask2]+wolne);
    }
  }
  int res = 0;
  REP(mask,ile) res = max(res, t[n][mask][0]);
  printf("%d\n",res);
  return 0;
}