#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
typedef pair<int,int> pii;

const int N = 310000;
int n,a[N],b[N];
vector<pii> ans[2];

int main() {
  scanf("%d",&n);
  REP(i,n) {
    scanf("%d%d",&a[i],&b[i]);
    if (a[i] < b[i]) { ans[0].push_back(make_pair(-a[i], i)); }
    else { ans[1].push_back(make_pair(a[i], i)); }
  }
  int idx = ans[1].size() > ans[0].size();
  sort(ans[idx].begin(), ans[idx].end());
  printf("%d\n", (int)ans[idx].size());
  FORE(i,ans[idx]) { printf("%d ",i->second+1); }
  printf("\n");
}