#include <bits/stdc++.h>

using namespace std;

struct Node {
   Node *l = nullptr, *r = nullptr, *p = nullptr;
   int lv, mv, rv;
   bool flip;
   void apply() {
      flip ^= true;
      swap(l, r);
      swap(lv, rv);
   }
   void push() {
      if (flip) {
         if (l) l->apply();
         if (r) r->apply();
         flip = false;
      }
   }
   void pop() {
      lv = 0, rv = 0;
      if (l && l->lv) lv = l->lv;
      else if (mv) lv = mv;
      else if (r && r->lv) lv = r->lv;
      if (r && r->rv) rv = r->rv;
      else if (mv) rv = mv;
      else if (l && l->rv) rv = l->rv;
   }
   int dir() {
      if (p) {
         if (p->l == this) return -1;
         if (p->r == this) return 1;
      }
      return 0;
   }
   void push_all() {
      if (dir()) p->push_all();
      push();
   }
   void rot() {
      Node* q = p->p;
      int pd = p->dir();
      if (pd == -1) q->l = this;
      if (pd == 1) q->r = this;
      if (p->l == this) {
         p->l = r;
         if (r) r->p = p;
         r = p;
      } else {
         p->r = l;
         if (l) l->p = p;
         l = p;
      }
      p->p = this;
      p->pop();
      pop();
      p = q;
      if (q) q->pop();
   }
   void splay() {
      push_all();
      int d;
      while ((d = dir())) {
         int pd = p->dir();
         if (!pd) rot();
         else if (pd == d) {
            p->rot();
            rot();
         } else {
            rot();
            rot();
         }
      }
   }
   void access() {
      Node *v = this, *vr = nullptr;
      do {
         v->splay();
         v->r = vr;
         v->pop();
         vr = v;
      } while (v = v->p);
      splay();
   }
   void makeroot() {
      access();
      apply();
   }
   void link(Node *v) {
      makeroot();
      v->access();
      assert(p == nullptr);
      p = v;
   }
   void cut(Node *v) {
      makeroot();
      v->access();
      p = nullptr;
      v->l = nullptr;
      v->pop();
   }
};

const int MAXN = 250250;

int N;
vector<int> adj[MAXN];
pair<int, int> edges[MAXN];
Node nodes[MAXN * 2];

void dfs(int v, int p) {
   for (int u : adj[v]) if (u != p) {
      dfs(u, v);
   }
   if (p) {
      nodes[v].makeroot();
      nodes[p].access();
      int i = nodes[p].lv;
      cout << v << " " << p << " " << edges[i].first << " " << edges[i].second << "\n";
      nodes[N + i].cut(&nodes[edges[i].first]);
      nodes[N + i].cut(&nodes[edges[i].second]);
      nodes[N + i].mv = 0;
      nodes[N + i].pop();
      nodes[N + i].link(&nodes[v]);
      nodes[N + i].link(&nodes[p]);
   }
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   cin >> N;
   for (int i = 0; i < N - 1; ++i) {
      int v, u;
      cin >> v >> u;
      adj[v].emplace_back(u);
      adj[u].emplace_back(v);
   }
   for (int i = 1; i <= N - 1; ++i) {
      int v, u;
      cin >> v >> u;
      edges[i] = {v, u};
      nodes[N + i].mv = i;
      nodes[N + i].pop();
      nodes[N + i].link(&nodes[v]);
      nodes[N + i].link(&nodes[u]);
   }
   cout << N - 1 << "\n";
   dfs(1, 0);
}