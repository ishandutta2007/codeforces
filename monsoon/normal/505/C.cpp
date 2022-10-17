#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 30100, SQRT_2N = 250;
int n,d,gem[N];
int memo[N][2*SQRT_2N];

int rek(int pos, int jump) {
  if (pos >= N) return 0;
  int& best = memo[pos][SQRT_2N + (jump-d)];
  if (best != -1) return best;

  best = max(rek(pos + jump, jump), rek(pos + jump + 1, jump + 1));
  if (jump > 1) {
    best = max(best, rek(pos + jump - 1, jump - 1));
  }
  best += gem[pos];
  return best;
}

int main() {
  scanf("%d%d",&n,&d);
  memset(memo, -1, sizeof(memo));
  REP(i,n) { int p; scanf("%d",&p); gem[p]++; }
  printf("%d\n", rek(d, d));
}