#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;
typedef pair<int,int> pii;

const int N = 210000;
int n,m,k,s,a[N],b[N],gn[N];
pii gad[2][N];
int glob_i;

bool is_ok(int mid) {
  int mina = *min_element(a,a+mid);
  int minb = *min_element(b,b+mid);
  ll cost = 0;

  REP(i,k) { cost += ll(gad[1][i].first) * minb; }

  REP(i,k+1) {
    if (i <= gn[0] && k-i <= gn[1]) {
      if (cost <= s) {
        glob_i = i;
        return true;
      }
    }
    cost += ll(gad[0][i].first) * mina;
    cost -= ll(gad[1][k-1-i].first) * minb;
  }
  return false;
}

int main() {
  scanf("%d%d%d%d",&n,&m,&k,&s);
  REP(i,n) { scanf("%d",&a[i]); }
  REP(i,n) { scanf("%d",&b[i]); }
  REP(i,m) {
    int t,c; scanf("%d%d",&t,&c);
    gad[t-1][gn[t-1]++] = make_pair(c, i);
  }
  REP(i,2) sort(gad[i],gad[i]+gn[i]);

  int lb=1, ub=n;
  while (lb != ub) {
    int mid = (lb+ub)/2;
    if (is_ok(mid)) { ub = mid; }
    else { lb = mid+1; }
  }

  if (!is_ok(lb)) {
    puts("-1");
  } else {
    printf("%d\n",lb);
    int mina = min_element(a,a+lb)-a;
    int minb = min_element(b,b+lb)-b;
    REP(i,glob_i) { printf("%d %d\n", gad[0][i].second+1, mina+1); }
    REP(i,k-glob_i) { printf("%d %d\n", gad[1][i].second+1, minb+1); }
  }



}