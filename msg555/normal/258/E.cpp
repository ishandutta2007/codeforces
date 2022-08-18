#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <cassert>

using namespace std;

template<class T> struct splnode {
  splnode() : P(NULL) { C[0] = C[1] = NULL; fix(); }

  T V;
  splnode* P;
  splnode<T>* C[2];

  /* Fix the parent pointers of our children.  Additionally if we have any
   * extra data we're tracking (e.g. sum of subtree elements) now is the time to
   * update them (all of the children will already be up to date). */
  void fix() {
    if(C[0]) C[0]->P = this;
    if(C[1]) C[1]->P = this;
    V.fix(this);
  }

  void push() {
    V.push(this);
  }

  /* Return the direction of this relative its parent. */
  int up(splnode<T>* stopp = NULL) {
    return !P || P == stopp ? -1 : (P->C[0] == this ? 0 : 1);
  }

  /* Splay this up to the root.  If stopp is not NULL splay until stopp so that
   * this' parent becomes stopp. */
  splnode<T>* splay(splnode<T>* stopp = NULL) {
    for(int c1 = up(stopp); c1 != -1; c1 = up(stopp)) {
      int c2 = P->up(stopp);
      if(c2 != -1 && c1 == c2) {
        P->zig();
      } else if(c2 != -1) {
        zig();
      }
      zig();
    }
    if(P) P->fix();
    push();
    return this;
  }

 private:
  void zig() {
    int c = up();
    P->push(); push();

    P->C[c] = C[1 - c];
    C[1 - c] = P;

    P->fix();
    if(P->P) P->P->C[P->up()] = this;
    P = P->P;
    fix();
  }
};

template<class T>
splnode<T>* spl_subtree_exclusive(splnode<T>* x, splnode<T>* y) {
  x->splay();
  y->splay(x);
  int c = y->up();
  return c == -1 ? NULL : y->C[1 - c];
}

struct node {
  int add;
  int val;
  int min_val;
  int min_cnt;

  node() : add(0), val(0), min_val(0), min_cnt(0) {}

  void fix(splnode<node>* x) {
    min_val = val;
    min_cnt = 1;
    for(int i = 0; i < 2; i++) {
      if(!x->C[i]) continue;
      int val = x->C[i]->V.min_val + x->C[i]->V.add;
      if(val == min_val) {
        min_cnt += x->C[i]->V.min_cnt;
      } else if(val < min_val) {
        min_val = val;
        min_cnt = x->C[i]->V.min_cnt;
      }
    }
  }

  void push(splnode<node>* x) {
    val += add;
    min_val += add;
    if(x->C[0]) x->C[0]->V.add += add;
    if(x->C[1]) x->C[1]->V.add += add;
    add = 0;
  }
};

int V[100010];
int L[100010];
int R[100010];

splnode<node> nds[100010];
vector<pair<int, int> > rngs[100010];
vector<int> E[100010];

void dfs(int x, int p, int& ind) {
  L[x] = ind++;
  for(int i = 0; i < E[x].size(); i++) {
    int u = E[x][i];
    if(u != p) {
      dfs(u, x, ind);
    }
  }
  R[x] = ind;
}

splnode<node>* rt;

void search(int x, int p) {
  for(int i = 0; i < rngs[x].size(); i++) {
    rt = spl_subtree_exclusive(&nds[rngs[x][i].first], &nds[rngs[x][i].second]);
    rt->V.add++;
    rt->splay();
  }
  V[x] = rt->V.min_val == 0 ? rt->V.min_cnt : 0;
  for(int i = 0; i < E[x].size(); i++) {
    if(E[x][i] != p) {
      search(E[x][i], x);
    }
  }
  for(int i = rngs[x].size() - 1; i >= 0; i--) {
    rt = spl_subtree_exclusive(&nds[rngs[x][i].first], &nds[rngs[x][i].second]);
    rt->V.add--;
    rt->splay();
  }
}

int main() {
  int N, M; cin >> N >> M;
  for(int i = 1; i < N; i++) {
    int u, v;
    cin >> u >> v; u--; v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  int ind = 0;
  dfs(0, -1, ind);

  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b; a--; b--;
    rngs[a].push_back(make_pair(L[a], R[a] + 1));
    rngs[a].push_back(make_pair(L[b], R[b] + 1));
    rngs[b].push_back(make_pair(L[a], R[a] + 1));
    rngs[b].push_back(make_pair(L[b], R[b] + 1));
  }

  int ON = N + 2;
  nds[0].V.val = nds[ON - 1].V.val = 1;
  for(int i = 0; i + 1 < ON; i++) nds[i].C[1] = &nds[i + 1];
  for(int i = ON - 1; i >= 0; i--) nds[i].fix();
  rt = &nds[0];

  search(0, -1);
  for(int i = 0; i < N; i++) {
    V[i] = N - V[i];
    if(V[i]) V[i]--;
    if(i) cout << ' ';
    cout << V[i];
  }
  cout << endl;
}