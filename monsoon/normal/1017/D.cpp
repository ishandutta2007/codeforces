#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

const int N = 12, Q=500100;
int n,q,m;
int cnt[1<<N];
int w[N];
char s[N+10];
int cost[1<<N];

vector<pair<int,int> > queries[1<<N];
int ans[Q];
int cnty[100*N+10];

int readmask() {
  scanf("%s",s);
  int mask=0;
  REP(i,n) if (s[i]=='1') mask |= 1<<i;
  return mask;
}

int main() {
  scanf("%d%d%d",&n,&m,&q);
  REP(i,n) scanf("%d",&w[i]);
  REP(i,m) {
    cnt[readmask()]++;
  }
  REP(mask,1<<n) {
    int c=0;
    REP(i,n) if (~mask & 1<<i) c += w[i];
    cost[mask] = c;
  }

  REP(i,q) {
    int qmask = readmask();
    int k; scanf("%d",&k);
    queries[qmask].push_back(make_pair(k, i));
  }

  REP(i,1<<n) {
    sort(queries[i].begin(), queries[i].end());
    REP(j,100*n+10) cnty[j] = 0;
    REP(j,1<<n) cnty[ cost[i^j] ] += cnt[j];
    int c=0,val=0;
    FORE(j,queries[i]) {
      while (val <= j->first) { c += cnty[val++]; }
      ans[j->second] = c;
    }
  }

  REP(i,q) { printf("%d\n", ans[i]); }
}