#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

const int N = 1100;
int n,m,a[N],ans;

int main() {
  scanf("%d%d",&n,&m);
  if (n > m) {
    puts("0");
  } else {
    REP(i,n) scanf("%d",&a[i]);
    ans = 1;
    REP(i,n) REP(j,i) {
      ans = ll(ans) * abs(a[i] - a[j]) % m;
    }
    printf("%d\n",ans);
  }
}