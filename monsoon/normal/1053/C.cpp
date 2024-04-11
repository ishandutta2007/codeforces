#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
typedef long long ll;

const int N = 200100, B=1<<18, MOD = 1000000007;
int n,q,a[N],w[N];

int BASE;
ll tree[2*B];
ll treeW[2*B];

void set(int x, int val, int a) {
  tree[x += BASE] = val;
  treeW[x] = ll(val) * a % MOD;
  while (x > 1) {
    x /= 2;
    tree[x] = tree[2*x] + tree[2*x+1];
    treeW[x] = (treeW[2*x] + treeW[2*x+1]) % MOD;
  }
}

ll query(int x) {
  if (x==0) return 0;
  --x;
  ll ans = tree[x += BASE];
  while (x > 1) {
    if (x & 1) ans += tree[x-1];
    x /= 2;
  }
  return ans;
}

ll queryW(int x) {
  if (x==0) return 0;
  --x;
  ll ans = treeW[x += BASE];
  while (x > 1) {
    if (x & 1) ans = (ans + treeW[x-1]) % MOD;
    x /= 2;
  }
  return ans;
}

int find(ll sum) {
  int x = 1;
  while (x < BASE) {
    if (tree[2*x] > sum) { x = 2*x; }
    else { sum -= tree[2*x]; x = 2*x+1; }
  }
  return x - BASE;
}

int main() {
  scanf("%d%d",&n,&q);

  BASE=1; while (BASE < n) { BASE *= 2; }

  REP(i,n) { scanf("%d",&a[i]); a[i] -= i; }
  REP(i,n) { scanf("%d",&w[i]); set(i, w[i], a[i]); }
  REP(i,q) {
    int x,y; scanf("%d%d",&x,&y);
    if (x < 0) {
      w[-x-1] = y; set(-x-1, y, a[-x-1]);
    } else {
      --x;
      ll sum = 0, sum2 = 0;
//      for(int j=x;j<y;++j) sum += w[j];
      sum = query(y) - query(x);
//      int xy;

//      for(xy=x; xy<y; ++xy) {
//        sum2 += w[xy];
//        if (sum2*2 > sum) break;
//      }

      ll needed = query(x) + sum/2;
      int xy = find(needed);

      ll cost = 0;
//      for(int j=x;j<y;++j) {
//        cost = (cost + ll(w[j]) * abs(a[j] - a[xy])) % MOD;
//      }

//      for(int j=x;j<xy;++j) cost = (cost + w[j] * (a[xy] - a[j])) % MOD;
//      for(int j=xy;j<y;++j) cost = (cost + w[j] * (a[j] - a[xy])) % MOD;

      cost = (cost + queryW(y) + MOD - queryW(xy) + MOD - (query(y) - query(xy)) % MOD * a[xy] % MOD) % MOD;
      cost = (cost + (query(xy) - query(x)) % MOD * a[xy] % MOD + MOD - queryW(xy) + queryW(x)) % MOD;

      printf("%d\n", (int)cost);
    }
  }
}