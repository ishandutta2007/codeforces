#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 300100;
int n,a;
set<int> s;
int bbegin[N],ans;


int main() {
  scanf("%d",&n);
  bbegin[0] = 0;
  REP(i,n) {
    scanf("%d",&a);
    if (s.find(a) != s.end()) {
      bbegin[++ans] = i+1;
      s.clear();
    } else {
      s.insert(a);
    }
  }
  bbegin[ans] = n;
  printf("%d\n", ans ?: -1);
  REP(i,ans) {
    printf("%d %d\n",bbegin[i]+1, bbegin[i+1]);
  }
}