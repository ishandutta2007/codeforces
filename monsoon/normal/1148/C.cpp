#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,n) for(int i=(a);i<(n);++i)
typedef pair<int,int> pii;

const int N = 310000;
int n,a[N],where[N];
vector<pii> ans;

void swapuj(int i, int j) {
  assert(abs(i-j) >= n/2);
  where[a[i]] = j;
  where[a[j]] = i;
  swap(a[i], a[j]);
  ans.push_back(make_pair(i, j));
}

int main() {
  scanf("%d",&n);
  REP(i,n) { scanf("%d",&a[i]); --a[i]; }
  REP(i,n) { where[a[i]] = i; }
  FOR(i,1,n-1) {
    if (abs(i - where[i]) >= n/2) {
      swapuj(i, where[i]);
    } else {
      if (where[i] < n/2) { swapuj(where[i], n-1); }
      else { swapuj(where[i], 0); }
      if (((i < n/2) ^ (where[i] < n/2)) == 0) { swapuj(0, n-1); }
      swapuj(i, where[i]);
    }
  }
  if (where[0] != 0) { swapuj(0, n-1); }
  assert(ans.size() <= 5*n);

  printf("%d\n",(int)ans.size());
  REP(i,(int)ans.size()) {
    printf("%d %d\n",ans[i].first+1,ans[i].second+1);
  }
}