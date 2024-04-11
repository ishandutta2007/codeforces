#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define Fit(i,v) for(typeof(v.begin()) i=v.begin();i!=v.end();++i)
#define fi first
#define se second
#define pb push_back

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, int> PLI;
typedef vector<int> VI;

int n, k;
VI ke[50050];
int fa[50050];
int F[50050][555];
int G[50050][555];

int main() {
  scanf("%d%d", &n, &k);
  Rep (i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    ke[u].pb(v);
    ke[v].pb(u);
  }
  VI q;
  q.pb(1);
  fa[1] = -1;
  Rep (kk, q.size()) {
    int i = q[kk];
    Fit (it, ke[i]) {
      int j = *it;
      if (fa[j] == 0) {
        fa[j] = i;
        q.pb(j);
      }
    }
  }
  Ford (kk, (int) q.size() - 1, 0) {
    int i = q[kk];
    F[i][0] = 1;
    Fit (it, ke[i]) {
      int j = *it;
      if (fa[j] == i) {
        Rep (d, k) F[i][d + 1] += F[j][d];
      }
    }
  }
  long long res = 0;
  Rep (kk, q.size()) {
    int i = q[kk];
    int fi = fa[i];
    if (fi != -1) {
      For (d, 1, k) {
        G[i][d] += G[fi][d - 1];
        G[i][d] += F[fi][d - 1] - (d >= 2 ? F[i][d - 2] : 0);
      }
    }
    res += F[i][k] + G[i][k];
  }
  cout << res / 2 << endl;
  return 0;
}