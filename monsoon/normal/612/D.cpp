#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
typedef pair<int,int> pii;

const int N = 1000100;
int n,k,ans[2*N],cnt,ansk;
pii v[2*N];

int main() {
  scanf("%d%d",&n,&k);
  REP(i,n) {
    int a,b; scanf("%d%d",&a,&b);
    v[2*i] = make_pair(a, -1);
    v[2*i+1] = make_pair(b, 1);
  }
  sort(v,v+2*n);
  REP(i,2*n) {
    int delta = -v[i].second;
    cnt += delta;
    if (delta == 1 && cnt == k) {
      ans[ansk++] = v[i].first;
    } else if (delta == -1 && cnt == k-1) {
      ans[ansk++] = v[i].first;
    }
  }
  printf("%d\n",ansk/2);
  REP(i,ansk/2) {
    printf("%d %d\n",ans[2*i],ans[2*i+1]);
  }
}