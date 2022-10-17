#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 52, D[] = {-1,1}, M=N*N, infty=1000000000;
int n,s,k,r[N],dist[N*N*M],qe,qb,q[N*N*M];
char str[N];

int main() {
  scanf("%d%d%d",&n,&s,&k); --s;
  REP(i,n) scanf("%d",&r[i]);
  scanf("%s",str);
  r[n] = -1; str[n] = 0;

  int ans = infty;
  int v = (0*(n+1) + n)*n + s;
  REP(i,n*(n+1)*M) dist[i] = infty;
  q[qe++] = v; dist[v] = 0;
  while (qe != qb) {
    int v = q[qb++];
    int pos = v % n;
    int lastpos = v/n % (n+1);
    int eaten = v/n/(n+1);
    REP(d,2) {
      int pos2 = pos + D[d];
      if (pos2 < 0 || pos2 >= n) continue;
      int v2 = (eaten*(n+1) + lastpos)*n + pos2;
      if (dist[v2] == infty) { dist[v2] = dist[v]+1; q[qe++] = v2; }

      if (r[pos] > r[lastpos] && str[pos] != str[lastpos]) {
        int eaten2 = eaten + r[pos];
        int v2 = (eaten2*(n+1) + pos)*n + pos2;
        if (dist[v2] == infty) { dist[v2] = dist[v]+1; q[qe++] = v2; }
      }
    }
    if (r[pos] > r[lastpos] && str[pos] != str[lastpos]
        && eaten + r[pos] >= k && dist[v] < ans) {
      ans = dist[v];
    }
  }
  REP(i,n*(n+1)*M) {
    int eaten = i/n/(n+1);
    if (eaten >= k && dist[i] < ans) { ans = dist[i]; }
  }
  printf("%d\n", ans == infty ? -1 : ans);
}