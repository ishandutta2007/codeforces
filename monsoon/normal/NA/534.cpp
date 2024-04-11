#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

const int N = 100100, infty = 1000000000;
int n,l,w,ns[2];
int xs[2][N];
ll cnt;

int divide_floor(ll a, int b) {
  if (b == 0) { return a < 0 ? -infty : infty; }
  int neg = (a < 0) ^ (b < 0);
  return neg ? -((abs(a)+abs(b)-1) / abs(b)) : abs(a) / abs(b);
}

int main() {
  scanf("%d%d%d",&n,&l,&w);
  REP(i,n) {
    int x,v; scanf("%d%d",&x,&v);
    int t=v==-1;
    xs[t][ns[t]++] = x;
  }
  REP(t,2) sort(xs[t],xs[t]+ns[t]);

  REP(i,ns[1]) {
    int x2 = xs[1][i];
    int* pos = lower_bound(xs[0],xs[0]+ns[0], -x2 - l);

    int val1 = min( divide_floor(ll(x2+l)*(w-1) - 1, w+1), x2 );
    int val2 = divide_floor(ll(x2+l)*(w+1) - 1, w-1);

    cnt += ( upper_bound(pos,xs[0]+ns[0], val1)-pos )
      + ( upper_bound(xs[0],pos, val2)-xs[0] );
  }
  printf("%lld\n", cnt);
}