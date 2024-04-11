#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FORE(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

#define MP make_pair


const int INF = 1000000001;
const int N=3100;
struct Edge{
  int v,rev,c,koszt;
  Edge(int vv,int rrev,int cc,int kkoszt) : v(vv), rev(rrev), c(cc), koszt(kkoszt) {}
  Edge() : v(0), rev(0), c(0), koszt(0) {}
};
vector<Edge> kraw[N];
int parent[N],parent_kraw[N];
int used[N];

LL dist[N],pot[N];
void AddEdge(int a,int b,int c,int koszt){
  kraw[a].PB(Edge(b,SIZE(kraw[b])+(a==b),c,koszt));
  kraw[b].PB(Edge(a,SIZE(kraw[a])-1,0,-koszt));
}

const LL DINF = (LL) 1e15l;

pair<int,LL> MinCostMaxFlow(int beg,int end,int n){
  int res=0;
  LL koszt=0;
  REP(i,n) if (i > 0) {
      FORE (it, kraw[i]) {
          if (it->c > 0) {
              pot[it->v] = min(pot[it->v], pot[i] + it->koszt);
          }
      }
  }
  while (1){
    REP(i,n) dist[i]=DINF,used[i]=0;
    dist[beg]=0;
    //algorytm Dijkstry, mozna zmienic na wersje z kopcem dla grafu rzadkiego
    REP(k,n){
      int best=-1;
      REP(i,n) if (!used[i] && (best==-1 || dist[i]<dist[best])) best=i;
      used[best]=1;
      if (dist[best]==DINF) break;
      FORE(it,kraw[best]) if (it->c>0){
        int x=it->koszt-pot[it->v]+pot[best];
        if (dist[it->v]>dist[best]+x){
          dist[it->v]=dist[best]+x;
          parent[it->v]=best;
          parent_kraw[it->v]=it-kraw[best].begin();
        }
      }
    }

    if (dist[end]==DINF) break; //brak sciezki powiekszajacej
    REP(i,n) dist[i]+=pot[i],pot[i]=dist[i]; //uaktualnienie potencjalu

    int cap=INF; //minimalna przepustowosc na sciezce
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
 //Begin of the code
int main(){
  int n, k;
  scanf("%d %d", &n, &k);
  AddEdge(0, 1, k, 0);
  vector<pair<PII, PII> > v(n);
  for (int i = 0; i < n; ++i) {
      scanf("%d %d %d", &v[i].ST.ST, &v[i].ST.ND, &v[i].ND.ST);
      v[i].ND.ND = i;
      v[i].ST.ND += v[i].ST.ST - 1;
  }
  int sz = 2 * n + 3;
  sort(ALL(v));
  AddEdge(1, sz - 1, k, 0);
  for (int i = 0; i < n; ++i) {
      AddEdge(1, 2 + 2 * i, 1, 0);
      AddEdge(2 + 2 * i, 2 + 2 * i + 1, 1, -v[i].ND.ST);
      AddEdge(2 + 2 * i + 1, sz - 1, 1, 0);
      for (int j = i + 1; j < n; ++j) {
          if (v[i].ST.ND < v[j].ST.ST) {
              AddEdge(2 + 2 * i + 1, 2 + 2 * j, 1, 0);
          }
      }
  }
  MinCostMaxFlow(0, sz - 1, sz);

  vector<bool> used(n, false);
  for (int i = 0; i < n; ++i) {
      FORE (it, kraw[2 + 2 * i]) {
          if (it->v == 2 + 2 * i + 1 && it->c == 0) {
              used[v[i].ND.ND] = true;
          }
      }
  }
  for (int i = 0; i < n; ++i) {
      printf("%d", (int) used[i]);
      if (i < n - 1) {
          printf(" ");
      } else {
          printf("\n");
      }
  }
  return 0;
}