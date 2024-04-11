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
const int INF = 1001 * 1001 * 1001;
int fu[N];

int fufind(int x){
  return fu[x] < 0 ? x : fu[x] = fufind(fu[x]);
}

int mam[N];

int dobra(int x){
  while (x){
    int c = x % 10;
    if (c != 4 && c != 7) return 0;
    x /= 10;
  }
  return 1;
}

PII q[N]; //(pozycja,wartosc)

//moge dostawic co od 0 do ile razy
void dostaw(int n, int co, int ile){
//  printf("dostaw n=%d co=%d ile=%d\n", n, co, ile);
  REP(reszta,co){
    int start = reszta;
    int qb = 0, qe = 0;
    int pos = 0;
    while (start <= n){
      //czyszcze kolejke
      while (qb < qe && pos - q[qb].ST > ile) qb++;
      
      //kandydat do poprawki dla mam[start]
      int kand = INF;
      if (qb < qe) kand = q[qb].ND + (pos - q[qb].ST);

      if (mam[start] < INF){
        while (qb < qe){
          if (q[qe-1].ND + (pos-q[qe-1].ST) >= mam[start]) qe--;
          else break;
        }
        q[qe++] = MP(pos, mam[start]);
      }

      //update
      mam[start] = min(mam[start], kand);
      start += co;
      pos++;
    }
  }
}

int krotnosc[N];

int main(){
  int n,m;
  scanf("%d %d",&n,&m);
  REP(i,n) fu[i] = -1;
  REP(foo,m){
    int a,b;
    scanf("%d %d",&a,&b); a--; b--;
    a = fufind(a); b = fufind(b);
    if (a != b){
      if (fu[a] < fu[b]) swap(a,b);
      fu[b] += fu[a];
      fu[a] = b;
    }
  }
  REP(i,n) if (fu[i] < 0) krotnosc[-fu[i]]++;
  REP(i,N) mam[i] = INF;
  mam[0] = 0;

  //FOR(i,0,n) printf("mam[%d]=%d\n",i,mam[i]);
  //puts("");

  FOR(d,1,n) if (krotnosc[d]){
    dostaw(n, d, krotnosc[d]);

  //  FOR(i,0,n) printf("mam[%d]=%d\n",i,mam[i]);
  //  puts("");
  }


  int best = INF;
  FOR(i,1,n) if (dobra(i)) best = min(best, mam[i]);
  if (best < INF) printf("%d\n",best-1);
  else puts("-1");
  return 0;
}