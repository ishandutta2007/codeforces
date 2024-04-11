#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
typedef pair<int,int> pii;

const int N = 100100;
int n,m,q;
map<int,int> fu[N];
vector<pii> cols[N];
map<pii,int> ans;

int fufind(int c, int i) {
  if (fu[c].find(i) == fu[c].end() || fu[c][i] == i) { return i; }
  else { return fu[c][i] = fufind(c, fu[c][i]); }
}
void fujoin(int c, int i, int j) {
  i = fufind(c, i);
  j = fufind(c, j);
  if (i != j) {
    fu[c][i] = j;
    fu[c][j] = j;
  }
}

int main() {
  scanf("%d%d",&n,&m);
  REP(i,m) {
    int a,b,c; scanf("%d%d%d",&a,&b,&c);
    fujoin(--c, --a, --b);
  }

  REP(c,m) FORE(i,fu[c]) { cols[i->first].push_back(make_pair(c, fufind(c, i->second))); }

  scanf("%d",&q);
  REP(i,q) {
    int a,b; scanf("%d%d",&a,&b); --a; --b;
    pii key = make_pair(a,b);
    if (ans.find(key) == ans.end()) {

      if (cols[a].size() > cols[b].size()) { swap(a,b); }
      int answer = 0;
      FORE(i,cols[a]) if (binary_search(cols[b].begin(), cols[b].end(), *i)) { ++answer; }
      ans[key] = answer;
    }

    printf("%d\n", ans[key]);
  }
}