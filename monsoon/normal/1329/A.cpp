#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPDN(i,n) for(int i=(n)-1;i>=0;--i)
typedef long long ll;

const int N = 110000;
int n,m,d[N],ans[N],mx;
ll sum;

int main() {
  scanf("%d%d",&n,&m);
  REP(i,m) {
    scanf("%d",&d[i]);
    sum += d[i];
  }
  if (sum < n) goto bad;
  mx = 0;
  REPDN(i,m) {
    mx = max(mx+1, d[i]);
    if (mx + i > n) goto bad;
  }
  mx = n;
  REPDN(i,m) {
    mx = max(i, mx-d[i]);
    ans[i] = mx;
  }
  REP(i,m) { printf("%d ",ans[i]+1); }
  puts("");
  return 0;
bad:
  puts("-1");
}