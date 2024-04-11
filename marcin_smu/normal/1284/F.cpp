#pragma GCC optimize("O3")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// gp_hash_table<int, int> mapka;

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

struct node{
  node *l, *r, *p;
  int val,size,pier,ost;
  bool flip;
  node(int _val): l(0), r(0), p(0), val(_val), size(1), pier(_val), ost(_val), flip(0){}
  /*virtual */void update(){
    touch();
    size = 1;         
    pier = val;
    ost = val;
    if(l){            
      size += l->size;
      if(l->pier != -1)
        pier = l->pier;
    }                 
    if(r){
      size += r->size;
      if(pier == -1){
        pier = r->pier;
      }
      if(r->ost != -1)
        ost = r->ost;
    }
    if(l && ost == -1){
      ost = l->ost;
    }
  }
  void touch(){
    if(flip){
      swap(l, r);
      if(l) l->reverse();
      if(r) r->reverse();
      flip = 0;
    }
  }
  void touch_path(){
    if(p) p->touch_path();
    touch();
  }
  node*& get_child(bool right){
    return right ? r : l;
  }
  static void add_child(node* x, node* q, bool right){
    if(x) x->get_child(right) = q;
    if(q) q->p = x;
  }
  inline bool is_right(){
    return p && p->r == this;
  }
  void rotate(){
    if(!p) return;
    node *oldp = p;
    bool right = is_right();
    add_child(p->p, this, p->is_right());
    add_child(oldp, get_child(!right), right);
    add_child(this, oldp, !right);
    oldp->update();
    update();
  }
  void splay_(){
    while(p){
      if(is_right() ^ p->is_right())
        rotate();
      else
        p->rotate();
      rotate();
    }
  }
  void splay(){ //dla nieodwracalych splay'ow zastapic przez splay_
    touch_path();
    splay_();
  }
  void set_val(int nval){
    val = nval;
    update();
  }
  void reverse(){
    swap(pier, ost);
    flip = !flip;
  }
  node* get_first(){
    node* res = this;
    while(1){
      res->touch();
      if(!res->l) break;
      res = res->l;
    }
    res->splay_();
    return res;
  }
  node* remove() {
    if(l) l->p = nullptr;
    if(r) r->p = nullptr;
    node* root = join(l, r);
    l = r = nullptr;
    return root;
  }
  static node* join(node* a, node* b){
    if(!a) return b;
    while(1){
      a->touch();
      if(!a->r) break;
      a = a->r;
    }
    a->splay_();
    add_child(a, b, true);
    a->update();
    return a;
  }
  node* get_kth(int k){
    assert(size > k);
    node* res = this;
    while(1){
      res->touch();
      if(res->l){
        if(res->l->size > k){
          res = res->l;
          continue;
        }else
          k -= res->l->size;
      }
      if(k == 0){
        res->splay_();
        return res;
      }
      k--;
      res = res->r;
    }
  }
  pair<node*, node*> split(int k){
    if(k == 0) return {nullptr, this};
    if(k >= size) return {this, nullptr};
    node* x = get_kth(k);
    node* res = x->l;
    x->l->p = nullptr;
    x->l = nullptr;
    x->update();
    return {res, x};
  }
  //~node(){ delete l; delete r; }
};


struct LCnode : node{
//   int st_size, base_size;
  LCnode(int _val):node(_val)/*, st_size(ver), base_size(ver)*/{};
//   virtual void update(){
//     node::update();
//     st_size = base_size;
//     if(l) st_size += ((LCnode*) l)->st_size;
//     if(r) st_size += ((LCnode*) r)->st_size;
//   }
  void LCsplay(){
    node* ak = this;
    node* par = ak->p;
    while(par && (par->l == ak || par->r == ak)){
      ak = par;
      par = ak->p;
    }
    ak->p = nullptr;
    splay();
    p = par;
  }
  void access(){
    node* right = nullptr;
    LCnode* cur = this;
    while(cur){
      cur->LCsplay();
      //--- zapytania o poddrzewo
//       if(cur->r) cur->base_size += ((LCnode*) cur->r)->st_size;
//       if(right) cur->base_size -= ((LCnode*) right)->st_size;
      //---
      cur->r = right;
      cur->update();
      right = cur;
      cur = (LCnode*)cur->p;
    }
    splay();
  }
  void to_root(){
    access();
    reverse();
    touch();
  }
  void link(LCnode* par){
    to_root();
    p = par;
    //--- zapytania o poddrzewo
//     par->to_root();
//     par->base_size += st_size;
//     par->update();
    //---
  }
  void get_path(LCnode* v){
    v->to_root();
    access();
  }
  void cut(LCnode* v){
    get_path(v);
    v->p = l = nullptr;
    update();
  }
  bool connected(LCnode* v){
    get_path(v);
    return get_first() == v;
  }
  ~LCnode(){
    l = r = nullptr;
  };
};


int n;
vector<vector<int>> d;
vector<vector<int>> res;
vector<LCnode*> t,c;
vector<int> a,b;
void dfs(int v,int oj){
  for(int el:d[v])if(el != oj){
    dfs(el, v);
  }
  if(oj != -1){
    t[v]->get_path(t[oj]);
    int id = t[v]->ost;
    res.PB({v, oj, a[id], b[id]});
    c[id]->cut(t[a[id]]);
    t[b[id]]->cut(c[id]);
    t[v]->link(t[oj]);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  d.resize(n);
  t.resize(n);
  R(i,n-1){
    int aa,bb;
    cin >> aa >> bb;
    aa--;bb--;
    d[aa].PB(bb);
    d[bb].PB(aa);
  }
  R(i,n){
    t[i] = new LCnode(-1);
  }
  a.resize(n-1);
  b.resize(n-1);
  c.resize(n-1);
  R(i,n-1){
    cin >> a[i] >> b[i];
    a[i]--;b[i]--;
    c[i] = new LCnode(i);
    c[i]->link(t[a[i]]);
    c[i]->link(t[b[i]]);
  }
  dfs(0,-1);
  cout << n-1 << "\n";
  for(auto el:res){
    for(int pom:el)
      cout << pom + 1 << " ";
    cout << "\n";
  }
  R(i,n)delete t[i];
  R(i,n-1)delete c[i];
}