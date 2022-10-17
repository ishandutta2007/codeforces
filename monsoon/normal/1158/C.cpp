#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 500100, NB = 1<<19;
int _,n,a[N],ans[N];
int base;
pair<int,int> tree[2*NB];

int query(int l, int r) {
  pair<int,int> ans = min(tree[l += base], tree[r += base]);
  while (l/2 != r/2) {
    if (l%2 == 0) { ans = min(ans, tree[l+1]); }
    if (r%2 == 1) { ans = min(ans, tree[r-1]); }
    l /= 2;
    r /= 2;
  }
  return ans.second;
}

int go(int l, int r, int sub, int add) {
  int n = r-l;

  if (n == 0) return 1;

  int i = query(l, r-1);
  if (a[i] - sub != n) { i = r; }

  if (i == r) {
    if (a[r-1] == -2) { i = r-1; }
    else return 0;
  }

  ans[i] = n-1 + add;
  if (!go(l, i, sub, add)
      || !go(i+1, r, sub + (i-l)+1, add + (i-l))) return 0;
  return 1;
}

int main() {
  scanf("%d",&_);
  REP(__,_) {
    scanf("%d",&n);
    REP(i,n) { scanf("%d",&a[i]); a[i]--; }

    base=1; while (base < n) { base*=2; }
    REP(i,n) { tree[base+i] = make_pair(-a[i], i); }
    for(int i=base-1; i>=1; --i) {
      tree[i] = min(tree[2*i], tree[2*i+1]);
    }

    if (!go(0,n,0,0)) {
      puts("-1");
    } else {
      REP(i,n) printf("%d ",ans[i]+1);
      printf("\n");
    }
  }
}