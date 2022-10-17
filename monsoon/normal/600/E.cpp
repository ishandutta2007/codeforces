#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
typedef long long ll;

const int N = 100100;
int n,c[N],mult[N],idx[N];
vector<int> adj[N];
map<int,int> mults[N];
ll sum[N],ans[N];

int join(int a, int b) {
  if (mults[a].size() < mults[b].size()) { swap(a,b); }
  FORE(i,mults[b]) {
    int newv = mults[a][i->first] + i->second;
    mults[a][i->first] = newv;

    if (newv == mult[a]) {
      sum[a] += i->first;
    } else if (newv > mult[a]) {
      sum[a] = i->first;
      mult[a] = newv;
    }
  }

  return a;
}

void dfs(int v, int par) {
  FORE(i,adj[v]) if (*i != par) {
    dfs(*i, v);
    idx[v] = join(idx[v], idx[*i]);
  }
  ans[v] = sum[idx[v]];
}


int main() {
  scanf("%d",&n);
  REP(i,n) {
    scanf("%d",&c[i]);
    mults[i][c[i]]++;
    mult[i] = 1;
    sum[i] = c[i];
    idx[i] = i;
  }
  REP(i,n-1) {
    int a,b; scanf("%d%d",&a,&b); --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(0, -1);

  REP(i,n) printf("%lld ",ans[i]);
  printf("\n");
}