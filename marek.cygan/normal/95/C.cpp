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
typedef pair<LL,LL> PLL;
typedef vector <PII> VPII;
typedef vector <PLL> VPLL;
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

const int N = 1100;
const int INF = 1001 * 1001 * 1001;

int dist[N][N];
int n;
VPII kraw[N];

void dijkstra(int x){
  priority_queue<PII,VPII,greater<PII> > q;
  REP(i,n) dist[x][i] = INF;
  dist[x][x] = 0;
  q.push(MP(0,x));
  while (!q.empty()){
    PII p = q.top(); q.pop();
    if (p.ST == dist[x][p.ND]){
      int v = p.ND;
      FOREACH(it, kraw[v]){
        if (dist[x][it->ST] > p.ST + it->ND){
          dist[x][it->ST] = p.ST + it->ND;
          q.push(MP(dist[x][it->ST],it->ST));
        }
      }
    }
  }
}

LL wynik[N];
int used[N];
int zasieg[N];
int koszt[N];
const LL INF2 = (LL)INF * INF;

int main(){
  int m;
  scanf("%d %d",&n,&m);
  int x,y;
  scanf("%d %d",&x,&y); x--; y--;
  REP(i,m){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c); a--; b--;
    kraw[a].PB(MP(b,c)); kraw[b].PB(MP(a,c));
  }
  REP(i,n) scanf("%d %d",&zasieg[i], &koszt[i]);
  REP(i,n) dijkstra(i);

  REP(i,n) wynik[i] = INF2;
  wynik[x] = 0;
  REP(foo,n){
    int best = -1;
    REP(i,n) if (!used[i] && (best == -1 || wynik[best] > wynik[i])) best = i;
    if (wynik[best] >= INF2) break;
    used[best] = 1;
    if (best == y) {
      cout << wynik[best] << endl;
      return 0;
    }

    REP(i,n) if (dist[best][i] <= zasieg[best]){
      LL kand = wynik[best] + koszt[best];
      if (kand < wynik[i]) wynik[i] = kand;
    }
  }
  cout << "-1" << endl;
  return 0;
}