#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
typedef long long ll;

const int N = 200100;
int n,even[N],odd[N];
vector<int> adj[N];
ll glob;

void dfs(int v, int par) {
  ll evens = 0, odds = 0;
  FORE(i,adj[v]) if (*i != par) {
    dfs(*i, v);
    glob += evens * even[*i];
    glob += 2 * odds * odd[*i];
    glob += 2 * evens * odd[*i];
    glob += 2 * odds * even[*i];
    evens += even[*i];
    odds += odd[*i];
  }
  ll others = n - evens - odds;
  glob += odds * others;
  glob += evens;
  even[v] = 1 + odds;
  odd[v] = evens;
}

int main() {
  scanf("%d",&n);
  REP(i,n-1) {
    int a,b; scanf("%d%d",&a,&b); --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(0, -1);

  printf("%lld\n", glob);
}