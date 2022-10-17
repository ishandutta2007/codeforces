#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
typedef long long ll;

const int N = 500100;
int n,k;
char s[N],t[N];
ll ans;

int main() {
  scanf("%d%d",&n,&k);
  scanf("%s%s",s,t);
  int cnt = 1;
  REP(i,n) {
    cnt = 2*(cnt-1) + (s[i] == 'a') + (t[i] == 'b');
    cnt = min(cnt, 1000000000);
    ans += min(cnt, k);
  }
  printf("%lld\n", ans);
}