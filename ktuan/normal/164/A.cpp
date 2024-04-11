#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
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

int n, m;
int f[100010];
VI ke[100010], ke2[100010];
bool vs[100010];
bool mark[100010];

int main() {
  scanf("%d%d", &n, &m);
  Rep (i, n) scanf("%d", &f[i]);
  Rep (i, m) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u; --v;
    ke[v].pb(u);
    ke2[u].pb(v);
  }
  Rep (i, n) if (f[i] == 2 && !vs[i]) {
    VI q;
    q.pb(i);
    vs[i] = true;
    Rep (j, q.size()) {
      int u = q[j];
      Rep (k, ke[u].size()) {
        int v = ke[u][k];
        if (!vs[v]) {
          vs[v] = true;
          if (f[v] != 1) {
            q.pb(v);
          }
        }
      }
    }
  }
  Rep (i, n) if (f[i] == 1 && !mark[i]) {
    VI q;
    q.pb(i);
    mark[i] = true;
    Rep (j, q.size()) {
      int u = q[j];
      Rep (k, ke2[u].size()) {
        int v = ke2[u][k];
        if (!mark[v]) {
          mark[v] = true;
          q.pb(v);
        }
      }
    }
  }
  Rep (i, n)
    if (vs[i] && mark[i]) printf("1\n");
    else printf("0\n");
  return 0;
}