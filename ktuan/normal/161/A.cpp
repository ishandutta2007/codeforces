#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
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

struct Person {
  int x;
  int i;
  bool operator<(Person p) const {
    return x < p.x;
  }
};

Person a[100010], b[100010];
int m, n;
int x, y;

int main() {
  scanf("%d%d%d%d", &m, &n, &x, &y);
  Rep (i, m) scanf("%d", &a[i].x), a[i].i = i + 1;
  Rep (i, n) scanf("%d", &b[i].x), b[i].i = i + 1;

  sort(a, a + m);
  sort(b, b + n);

  int j = 0;
  int res = 0;
  vector<PII> matches;
  Rep (i, m) {
    while (j < n && b[j].x < a[i].x - x) ++j;
    if (j < n && a[i].x - x <= b[j].x && b[j].x <= a[i].x + y) {
      matches.push_back(make_pair(a[i].i, b[j].i));
      ++res;
      ++j;
    }
  }
  cout << res << endl;
  Rep (i, res) {
    printf("%d %d\n", matches[i].fi, matches[i].se);
  }
  return 0;
}