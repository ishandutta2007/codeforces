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

const int N = 360360;
const int INF = 1001 * 1001;

VI kraw[2][N];
int dist[N];

int cykl=N;

void bfs(int f, int v){
  REP(i,N) dist[i] = INF;
  dist[v] = 0;
  VI q;
  q.PB(v);
  cykl = INF;
  REP(foo,SIZE(q)){
    v = q[foo];
    FOREACH(it, kraw[f][v]) {
      int x = *it;
      if (v != 0 && x == 0 && cykl == INF){
        cykl = dist[v]+1;
      }
      if (dist[x] == INF){
        dist[x] = dist[v]+1;
        q.PB(x);
      }
    }
  }
}

void dodaj(int a,int b){
  kraw[0][a].PB(b);
  kraw[1][b].PB(a);
}

LL licz(LL a, LL b){
  bfs(0,a%N);
  if (a-b < N) return dist[b%N];
  LL res = dist[0];
  a = a-(a%N);

  bfs(1,b%N);
  res += dist[0];
  if (b % N) b += N-(b%N);

  bfs(0,0);
  //printf("cykl=%d\n", cykl);
  res += (a-b)/N * cykl;

  return res;
}

int main(){
  LL a, b;
  int k;
  cin >> a >> b >> k;
  REP(i,N){
    if (i == 0) dodaj(0,N-1);
    else dodaj(i,i-1);
    FOR(x,2,k) dodaj(i,i-(i%x));
  }
  cout << licz(a,b) << endl;
  return 0;
}