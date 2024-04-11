#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define M_PI 3.14159265358979323846264338327

const int N = 100100;
int n;
pair<long double,int> at[N],ans;

int main() {
  scanf("%d",&n);
  REP(i,n) {
    int x,y; scanf("%d%d",&x,&y);
    at[i] = make_pair(atan2l(y,x), i);
  }
  sort(at,at+n);
  ans = make_pair(2*M_PI, -1);
  at[n] = at[0];
  at[n].first += 2*M_PI;

  REP(i,n) {
    ans = min(ans, make_pair(at[i+1].first - at[i].first, i));
  }
  int idx = ans.second;
  printf("%d %d\n", at[idx+1].second+1, at[idx].second+1);
}