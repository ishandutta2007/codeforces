#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node {
  node *l, *r;
  int val, pr;
  int sz;
  long long sum;
  node(int val = 0) : l(0), r(0), val(val), pr(rng()), sz(1), sum(val) {}
};

int sz(node *v) { return v ? v->sz : 0; }
long long sum(node *v) { return v ? v->sum : 0; }

void pull(node *v) {
  if (v) {
    v->sz = sz(v->l) + sz(v->r) + 1;
    v->sum = v->val + sum(v->l) + sum(v->r);
  }
}

void print(node *v,bool root = true) {
  if (!v) return;
  print(v->l, 0);
  printf("%d ", v->val);
  print(v->r, 0);
  if (root) {
    puts("");
  }
}

void mrg(node *&v,node *l, node *r) {
  if (!l || !r) v = l ? l : r;
  else if (l->pr > r->pr) {
    mrg(l->r, l->r, r);
    v = l;
  } else {
    mrg(r->l, l, r->l);
    v = r;
  }
  pull(v);
}

void split_sz(node *v, node *&l, node *&r,int sz) {
  if (!v) { l = r = 0; return; }
  if (sz <= ::sz(v->l)) {
    split_sz(v->l, l, v->l, sz);
    r = v;
  } else {
    split_sz(v->r, v->r, r, sz - ::sz(v->l) - 1);
    l = v;
  }
  pull(v);
}

void split_val(node *v,node *&l, node *&r,int val) {
  if (!v) { l = r = 0; return; }
  if (val >= v->val) {
    split_val(v->l, l, v->l, val);
    r = v;
  } else {
    split_val(v->r, v->r, r, val);
    l = v;
  }
  pull(v);
}

void add(node *&v, int val) {
  node *l, *r;
  split_val(v, l, r, val);
  node *m = new node(val);
  mrg(v, l, m);
  mrg(v, v, r);
}

void del(node *&v,int val) {
  node *l, *m, *r;
  split_val(v, l, r, val);
  split_sz(r, m, r, 1);
  mrg(v, l, r);
}

long long getPref(node *v,int len) {
  node *l, *r;
  split_sz(v, l, r, len);
  long long ans = sum(l);
  mrg(v, l, r);
  return ans;
}

const int N = 250250;

node* rt[N];
int n;
vector< pair<int, int> > g[N], cg[N];
bool visit[N];
bool can[N];
vector<int> at_deg[N];
long long f[N][2];
vector<int> vers;
long long tot;
long long ans[N];

void dfs(int u,int p,int md) {
  visit[u] = true;
  vector<long long> vals;
  int up_cost = 0;
  long long all = 0;
  for (auto e : cg[u]) {
    int v = e.first;
    int cost = e.second;
    if (v == p) {
      up_cost = cost;
      continue;
    }
    dfs(v, u, md);
    all += f[v][0];
    if (f[v][1] > f[v][0]) {
      vals.push_back(f[v][1] - f[v][0]);
    }
  }
  sort(vals.begin(), vals.end(), greater<long long>());
  for (int up = 0; up < 2; ++up) {
    f[u][up] = all;
    long long sum = all;
    int nmd = md - up;
    for (int i = 0; i <= vals.size() && i <= nmd; ++i) {
      if (i) sum += vals[i - 1];
      f[u][up] = max(f[u][up], sum + getPref(rt[u], nmd - i));
    }
  }
  f[u][1] += up_cost;
}

void addver(int u) {
  vers.push_back(u);
  can[u] = true;
  for (auto e : g[u]) {
    int v = e.first;
    int cost = e.second;
    if (can[v]) {
      cg[u].push_back(make_pair(v, cost));
      cg[v].push_back(make_pair(u, cost));
      del(rt[v], cost);
    } else {
      tot += cost;
      add(rt[u], cost);
    }
  }
}

long long get(int md) {
  long long ans = tot;
  for (int u : vers) {
    if (!visit[u]) {
      dfs(u, -1, md);
      ans -= f[u][0];
    }
  }
  for (int u : vers) {
    visit[u] = false;
  }
  return ans;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v, cost;
    scanf("%d %d %d", &u, &v, &cost);
    g[u].push_back(make_pair(v, cost));
    g[v].push_back(make_pair(u, cost));
  }
  for (int i = 1; i <= n; ++i) {
    rt[i] = 0;
    at_deg[g[i].size()].push_back(i);
  }

  for (int i = n - 1; i > 0; --i) {
    ans[i] = get(i);
    for (int v : at_deg[i]) {
      addver(v);
    }
  }
  ans[0] = tot;
  for (int i = 0; i < n; ++i) printf("%lld ", ans[i]);
}