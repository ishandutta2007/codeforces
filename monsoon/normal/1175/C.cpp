#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 200100;
int _,n,k,a[N];
pair<int,int> ans;

int main() {
  scanf("%d",&_);
  REP(__,_) {
    scanf("%d%d",&n,&k);
    REP(i,n) { scanf("%d",&a[i]); }
    ans = make_pair(a[n-1], 0);
    REP(i,n-k) {
      int len = (a[i+k] - a[i] + 1)/2;
      ans = min(ans, make_pair(len, a[i] + len));
    }
    printf("%d\n", ans.second);
  }
}