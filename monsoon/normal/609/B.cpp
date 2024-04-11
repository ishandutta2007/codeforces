#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

const int N = 110;
int n,m,cnt[N];
ll ans;

int main() {
  scanf("%d%d",&n,&m);
  REP(i,n) {
    int typ; scanf("%d",&typ);
    cnt[--typ]++;
  }
  ans += ll(n)*n;
  REP(i,m) { ans -= ll(cnt[i])*cnt[i]; }
  ans /= 2;
  printf("%lld\n",ans);
}