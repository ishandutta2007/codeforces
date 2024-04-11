#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
typedef long long ll;

const int N = 400100, NB=1<<19;
int n,q,c[N],base;
ll tree_val[2*NB];
int tree_set[2*NB];
vector<int> adj[N];
int tin[N],tout[N],T;

void set_node(int a, int c) {
  tree_set[a] = c;
  tree_val[a] = 1LL << c;
}

void prepare(int a) {
  vector<int> nodes;
  a += base;
  while (a > 1) { nodes.push_back(a /= 2); }
  reverse(nodes.begin(),nodes.end());
  FORE(i,nodes) {
    if (tree_set[*i]) {
      set_node(2**i, tree_set[*i]);
      set_node(2**i+1, tree_set[*i]);
      tree_set[*i] = 0;
    }
  }
}

void update(int a) {
  tree_val[a] = tree_set[a] ? (1LL << tree_set[a]) :
    tree_val[2*a] | tree_val[2*a+1];
}

void set_query(int a, int b, int c) {
  prepare(a);
  prepare(b);
  set_node(a += base, c);
  set_node(b += base, c);

  while (a/2 != b/2) {
    if (a%2 == 0) { set_node(a+1, c); }
    if (b%2 == 1) { set_node(b-1, c); }
    update(a /= 2);
    update(b /= 2);
  }
  while (a > 1) { update(a /= 2); }
}

ll get_query(int a, int b) {
  prepare(a);
  prepare(b);
  ll ans = tree_val[a += base] | tree_val[b += base];
  while (a/2 != b/2) {
    if (a%2 == 0) { ans |= tree_val[a+1]; }
    if (b%2 == 1) { ans |= tree_val[b-1]; }
    a /= 2;
    b /= 2;
  }
  return ans;
}

void dfs(int v, int par) {
  tin[v] = T++;
  FORE(i,adj[v]) if (*i != par) {
    dfs(*i, v);
  }
  tout[v] = T;
}

int main() {
  scanf("%d%d",&n,&q);
  base = 1;
  while (base < n) base *= 2;
  REP(i,n) { scanf("%d",&c[i]); }
  REP(i,n-1) {
    int a,b; scanf("%d%d",&a,&b); --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(0,-1);

  REP(i,n) { set_node(base + tin[i], c[i]); }
  for(int i=base-1; i>=1; --i) { update(i); }

  REP(i,q) {
    int ty,v; scanf("%d%d",&ty,&v); --v;
    if (ty == 1) {
      int c; scanf("%d",&c);
      set_query(tin[v], tout[v]-1, c);
    } else {
      ll ans = get_query(tin[v], tout[v]-1);
      printf("%d\n", __builtin_popcountll(ans));
    }
  }
}