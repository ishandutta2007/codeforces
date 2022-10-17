#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

const int N = 100100, K=110, infty = 1000000000;
int n,m,k,s;
vector<int> adj[N];
vector<int> cities[K];
int dist[N][K];
int qe,qb,q[N],d[N];

int main() {
  scanf("%d%d%d%d",&n,&m,&k,&s);
  REP(i,n) {
    int t; scanf("%d",&t);
    cities[t-1].push_back(i);
  }
  REP(i,m) {
    int a,b; scanf("%d%d",&a,&b); --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  REP(typ,k) {
    qe=qb=0;
    REP(i,n) d[i] = infty;
    FORE(i,cities[typ]) { d[*i] = 0; q[qe++] = *i; }
    while (qe!=qb) {
      int v = q[qb++];
      FORE(i,adj[v]) if (d[*i] == infty) {
        d[*i] = d[v]+1; q[qe++] = *i;
      }
    }
    REP(i,n) dist[i][typ] = d[i];
  }
  REP(i,n) {
    nth_element(dist[i], dist[i]+s, dist[i]+k);
    int sum = 0;
    REP(j,s) sum += dist[i][j];
    printf("%d ",sum);
  }
  printf("\n");
}