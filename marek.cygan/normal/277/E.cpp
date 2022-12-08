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


const LL INF = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000;

const int N=815;
struct Edge{
  int v,rev,c;
  LL koszt;
  Edge(int vv,int rrev,int cc,LL kkoszt) : v(vv), rev(rrev), c(cc), koszt(kkoszt) {}
  Edge(){}
};
vector<Edge> kraw[N];
int parent[N],parent_kraw[N];
LL used[N],dist[N],pot[N];
void AddEdge(int a,int b,int c,LL koszt){
  kraw[a].PB(Edge(b,SIZE(kraw[b])+(a==b),c,koszt));
  kraw[b].PB(Edge(a,SIZE(kraw[a])-1,0,-koszt));
}

pair<int,LL> MinCostMaxFlow(int beg,int end,int n){
  int res=0;
  LL koszt=0;
  REP(i,n) pot[i]=0; //poczatkowy potencjal, zakladam, ze poczatkowo
                     //wszystkie wagi sa nieujemne, jesli moba byc ujemne,
                     //to trzeba obliczyc poczatkowe potencjaly Bellmanem-Fordem
  while (1){
    REP(i,n) dist[i]=INF,used[i]=0; 
    dist[beg]=0;
    //algorytm Dijkstry, mozna zmienic na wersje z kopcem dla grafu rzadkiego
    REP(k,n){
      int best=-1;
      REP(i,n) if (!used[i] && (best==-1 || dist[i]<dist[best])) best=i;
      used[best]=1;
      if (dist[best]==INF) break;
      FOREACH(it,kraw[best]) if (it->c>0){
        LL x=it->koszt-pot[it->v]+pot[best];
        if (dist[it->v]>dist[best]+x){
          dist[it->v]=dist[best]+x;
          parent[it->v]=best;
          parent_kraw[it->v]=it-kraw[best].begin();
        }
      }
    }

    if (dist[end]==INF) break; //brak sciezki powiekszajacej
    REP(i,n) dist[i]+=pot[i],pot[i]=dist[i]; //uaktualnienie potencjalu

    int cap=1000000; //minimalna przepustowosc na sciezce
    int x=end;
    do{
      cap=min(cap,kraw[parent[x]][parent_kraw[x]].c);
      x=parent[x];
    } while (x!=beg);
    res+=cap;

    x=end;
    do{
      koszt+=kraw[parent[x]][parent_kraw[x]].koszt*(LL)cap;
      kraw[parent[x]][parent_kraw[x]].c-=cap;
      kraw[x][kraw[parent[x]][parent_kraw[x]].rev].c+=cap;
      x=parent[x];
    } while (x!=beg);
  }
  return MP(res,koszt);
}

const LL skala = 100000000;

LL dajkoszt(PII a, PII b){
  return (long long)(hypotl(a.ST-b.ST,a.ND-b.ND) * skala);
}

int main(){
  int n;
  scanf("%d",&n);
  VPII v;
  REP(i,n){
    int a,b;
    scanf("%d %d",&a,&b);
    v.PB(MP(a,b));
  }

  REP(i,n) AddEdge(0,i+1,2,0);
  REP(i,n) AddEdge(i+(n+1),2*n+1,1,0);
  REP(i,n) REP(j,n) if (v[i].ND > v[j].ND) AddEdge(i+1,j+(n+1),1,dajkoszt(v[i],v[j]));

  pair<int,LL> p=MinCostMaxFlow(0,2*n+1,2*n+2);
  if (p.ST != n-1) printf("-1\n");
  else printf("%.12lf\n", (double)p.ND / skala);
  return 0;
}