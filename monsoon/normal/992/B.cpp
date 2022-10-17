#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

int l,r,x,y;
vector<int> divs;

int main() {
  scanf("%d%d%d%d",&l,&r,&x,&y);
  int cnt = 0;
  if (y%x == 0) {
    int w = y/x;
    for (int d=1; d*d<=w; ++d) {
      if (w % d == 0) {
        divs.push_back(d);
        if (d != w/d) divs.push_back(w/d);
      }
    }
    FORE(i,divs) {
      int d = *i;
      int e = w/d;
      if (__gcd(d, e) == 1) {
        int a = x*d;
        int b = x*e;
        if (l <= a && a <= r && l <= b && b <= r) {
          ++cnt;
        }
      }
    }
  }
  printf("%d\n", cnt);
}