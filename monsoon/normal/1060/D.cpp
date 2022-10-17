#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

const int N = 100100;
int n,l[N],r[N],se;
pair<int,int> p[2*N],s[2*N];
ll cnt;

int main() {
  scanf("%d",&n);
  REP(i,n) {
    scanf("%d%d",&l[i],&r[i]);
    p[2*i] = make_pair(l[i], 0);
    p[2*i+1] = make_pair(r[i], 1);
  }
  sort(p,p+2*n);
  REP(i,2*n) {
    if (se>0 && s[se-1].second != p[i].second) {
      cnt += p[i].first;
      --se;
    } else {
      s[se++] = p[i];
    }
  }
  printf("%lld\n",cnt + n);
}