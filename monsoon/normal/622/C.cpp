#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPDN(i,n) for(int i=(n)-1;i>=0;--i)

const int N = 200100;
int n,q,a[N],nxt[N];

int main() {
  scanf("%d%d",&n,&q);
  REP(i,n) { scanf("%d",&a[i]); }
  a[n] = -1;
  REPDN(i,n) { nxt[i] = a[i] != a[i+1] ? i+1 : nxt[i+1]; }
  REP(i,q) {
    int l,r,x; scanf("%d%d%d",&l,&r,&x); --l;
    int ans = a[l] != x ? l+1 : (nxt[l] < r ? nxt[l]+1 : -1);
    printf("%d\n",ans);
  }
}