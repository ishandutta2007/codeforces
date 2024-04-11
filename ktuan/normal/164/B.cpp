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

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, int> PLI;
typedef vector<int> VI;

int m, n;
int a[2000010], b[1000010], pos[1000010];
int c[2000010];
int F[2000010];

int main() {
  scanf("%d%d", &m, &n);
  Rep (i, m) scanf("%d", &a[i]);
  memset(pos, -1, sizeof(pos));
  Rep (i, n) {
    scanf("%d", &b[i]);
    pos[b[i]] = i;
  }
  Rep (i, m) a[i + m] = a[i];
  Rep (i, 2 * m) {
    F[i] = 0;
    if (pos[a[i]] >= 0) {
      F[i] = 1;
      if (i > 0 && pos[a[i - 1]] >= 0 && pos[a[i]] > pos[a[i - 1]]) {
        F[i] = F[i - 1] + 1;
      }
    }
  }
  // Rep (i, 2 * m) cout << F[i] << " "; cout << endl;
  Rep (i, 2 * m) c[i] = pos[a[i]];
  int best = 0;
  Rep (i, 2 * m) {
    int z = F[i];
    best = max(best, z);
    if (z > 0 && i - z >= 0 && F[i - z] > 0) {
      if (i == 2 * m - 1 || F[i + 1] <= F[i]) {
        int u = i - z - F[i - z] + 1;
        int v = i - z + 1;
        for (int j = u; j <= i - z; ++j) {
          while (v <= i && c[v] < c[j]) ++v;
          best = max(best, (i - z - j + 1) + (v - (i - z + 1)));
        }
      }
    }
  }
  cout << best << endl;
  return 0;
}