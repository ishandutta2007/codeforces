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

typedef pair<int,int> PII;

int ra[1010][1010], rb[1010][1010];

int main() {
  int m, n;
  scanf("%d%d", &m, &n);
  vector<PII> a(m), b(n);
  Rep (i, m) scanf("%d%d", &a[i].fi, &a[i].se);
  Rep (j, n) scanf("%d%d", &b[j].fi, &b[j].se);
  vector<int> ca(1010, 0), cb(1010, 0);
  Rep (i, m) ++ca[a[i].se];
  Rep (j, n) ++cb[b[j].se];
  int total = 0;
  Rep (i, 1010) total += min(ca[i], cb[i]);
  Rep (i, m) ++ra[a[i].fi][a[i].se];
  Rep (j, n) ++rb[b[j].fi][b[j].se];
  int result = 0;
  Rep (i, 1010) Rep (j, 1010) result += min(ra[i][j], rb[i][j]);
  cout << total << " " << result << endl;
  return 0;
}