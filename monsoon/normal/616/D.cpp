#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 1000100;
int n,k,a[N];
int best,bi,bj;
int cnt[N],cnt_dist;

void insert(int val) {
  if (cnt[val] == 0) ++cnt_dist;
  ++cnt[val];
}

void remove(int val) {
  --cnt[val];
  if (cnt[val] == 0) --cnt_dist;
}

int main() {
  scanf("%d%d",&n,&k);
  REP(i,n) { scanf("%d",&a[i]); }
  int j = 0;
  REP(i,n) {
    while (j < n) {
      insert(a[j]);
      if (cnt_dist > k) { remove(a[j]); break; }
      ++j;
    }
    if (j-i > best) {
      best = j-i;
      bi = i; bj = j;
    }
    remove(a[i]);
  }
  printf("%d %d\n",bi+1,bj);
}