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

const int INF = 1000 * 1000 * 1001;
const int N = 200;
int koszt[N]; 
int n,k;

VI kraw[N];

int t[N][N][N];
int t_bez_obietnic[N][N];
int gdzie_stawia[N][N][N];
int bez_stawiania[N][N];
int parent[N];
int gleboko[N];

void daj_potomkow(int d,int x,VI &v){
  v.PB(d);
  FOREACH(it, kraw[x]) if (*it != parent[x]){
    daj_potomkow(d+1,*it,v);
  }
}

//gora - odleglosc idac poza poddrzewo, jesli = n to nie ma gdzie isc
//dol - obietnica zbudowania centrum na glebokosci nie wiekszej niz dol, obietnia musi byc spelniona
void licz(int x){
  FOREACH(it, kraw[x]) if (*it != parent[x]) licz(*it);
  
  //licze bez stawiania
  {
    VI v;
    daj_potomkow(0,x,v);
    FOR(gora,0,n){
      int kand = 0;
      FOREACH(it,v){
        if (*it + gora >= n) kand = INF;
        else kand += koszt[*it + gora];
        kand = min(kand, INF);
      }
      bez_stawiania[x][gora] = kand;
    }
  }

  FOR(gora,1,n) {
    FOR(dol,0,gleboko[x]) {
      int &res = t[x][gora][dol];
      res = k;
      gdzie_stawia[x][gora][dol] = -1; //u siebie
      int mam_syna = 0;
      FOREACH(it, kraw[x]) if (*it != parent[x]){
        res += t_bez_obietnic[*it][1];
        mam_syna = 1;
      }


      if (dol == 0 || mam_syna == 0) continue;

      //nie stawiam w x
      LL suma = 0;
      int nowa_gora = min(gora+1,min(n, dol+1));
      FOREACH(it, kraw[x]) if (*it != parent[x]) suma += t_bez_obietnic[*it][nowa_gora];

      FOREACH(it, kraw[x]) if (*it != parent[x]){
        suma -= t_bez_obietnic[*it][nowa_gora];

        LL kand = suma + t[*it][min(n,gora+1)][dol-1];

        if (min(gora,dol) < n) kand += koszt[min(gora,dol)];
        else kand += INF;

        if (kand < res){
          res = kand;
          gdzie_stawia[x][gora][dol] = *it;
        }

        suma += t_bez_obietnic[*it][nowa_gora];
      }
    }
  }

  FOR(gora,0,n){
    int kand = INF;
    FOR(dol,0,gleboko[x]) kand = min(kand, t[x][gora][dol]);
    kand = min(kand, bez_stawiania[x][gora]);
    t_bez_obietnic[x][gora] = kand;
  }
}

int dfs(int x,int par){
  gleboko[x] = 0;
  parent[x] = par;
  FOREACH(it, kraw[x]) if (*it != par){
    dfs(*it, x);
    gleboko[x] = max(gleboko[x], gleboko[*it]+1);
  }
  return gleboko[x];
}

int dist[N][N];

void odtworz_bez_obietnic(int x,int gora,VI &v);

void odtworz(int x,int gora,int dol,VI &v){
  if (gdzie_stawia[x][gora][dol] == -1){
    v.PB(x);
    FOREACH(it, kraw[x]) if (*it != parent[x]) odtworz_bez_obietnic(*it, 1, v);
    return;
  }
  int nowa_gora = min(gora+1,min(n, dol+1));
  FOREACH(it, kraw[x]) if (*it != parent[x] && *it == gdzie_stawia[x][gora][dol]){
    FOREACH(it2, kraw[x]) if (*it2 != parent[x] && *it2 != *it){
      odtworz_bez_obietnic(*it2, nowa_gora, v);
    }
    odtworz(gdzie_stawia[x][gora][dol], min(n,gora+1), dol-1, v);
    return;
  }
  printf("x=%d gora=%d dol=%d gdzie_stawia=%d res=%d\n",x,gora,dol,gdzie_stawia[x][gora][dol],t[x][gora][dol]);
  assert(0);
}

void odtworz_bez_obietnic(int x,int gora,VI &v){
  int res = t_bez_obietnic[x][gora];
  if (bez_stawiania[x][gora] == res) return;
  FOR(dol,0,gleboko[x]) if (t[x][gora][dol] == res){
    odtworz(x,gora,dol,v);
    return;
  }
  assert(0);
}

int main(){
  scanf("%d %d",&n,&k);
  FOR(i,1,n-1) scanf("%d",koszt+i);
  REP(i,n) REP(j,n) dist[i][j] = n-1;
  REP(i,n) dist[i][i] = 0;
  REP(i,n-1){
    int a,b;
    scanf("%d %d",&a,&b);
    a--; b--;
    kraw[a].PB(b);
    kraw[b].PB(a);
    dist[a][b] = dist[b][a]=1;
  }
  REP(i,N) REP(j,N) REP(k,N) t[i][j][k] = INF;
  REP(i,N) REP(j,N) t_bez_obietnic[i][j] = bez_stawiania[i][j] = INF;

  REP(k,n) REP(i,n) REP(j,n) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  dfs(0,-1);
  licz(0);
  int res = t_bez_obietnic[0][n];
  VI v;
  odtworz_bez_obietnic(0,n,v);
  printf("%d\n", res);
  int foo = 0;
  REP(i,n){
    if (i) printf(" ");
    int best = v[0];
    FOREACH(it,v) if (dist[i][*it] < dist[i][best]) best = *it;
    if (best == i) foo += k;
    else foo += koszt[dist[i][best]];
    printf("%d",best+1);
  }
  assert(foo == res);
  puts("");
  return 0;
}