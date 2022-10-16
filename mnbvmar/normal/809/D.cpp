#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define RE(i,n) FOR(i,1,n)
#define R(i,n) REP(i,n)
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define VI vector<int>
#define PII pair<int,int>
#define LD long double

template<class C> void mini(C& a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C& a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream &os, vector<T> V){
  os<<"[";for(auto vv:V)os<<vv<<",";return os<<"]";
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
  int size,val,sum;
  node(int _val): l(0), r(0), p(0), val(_val), size(1), sum(_val) {}
  virtual void update(){
    size = 1;              // Wszystkie funckje nalezy wykonywac na korzeniu/korzeniach
    sum = val;             // drzewa Splay. Zwracaja one nowy korzen/korzenie.
    if(l){                 // Jesli skadinad mamy wskaznik do wierzcholka, nalezy
      size += l->size;     // wykonac na nim splay(). Remove() nie zwalnia pamieci.
      sum += l->sum;       // Usuwany wierzcholek staje sie korzeniem
    }                      // jednoelementowego drzewa.
    if(r){
      size += r->size;
      sum += r->sum;
    }
  }
  void touch(){
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
  node* get_at_psum(int x) {
    assert(x < sum);
    node *res = this;
    while (1) {
      res->touch();
      
      if (res->l && res->l->sum > x) {
        res = res->l;
      } else {
        if (res->l) { x -= res->l->sum; }
        if (res->val > x) {
          res->splay_();
          return res;
        } else {
          x -= res->val;
          res = res->r;
        }
      }
    }
  }
  
  int get_pos() {
    int res = 1;
    if (l) { res += l->size; }
    return res;
  }
  
  int get_prev_sum() {
    int res = 0;
    if (l) { res += l->sum; }
    return res;
  }
  
  node *get_next() {
    node *res = r;
    while (res && res->l) {
      res = res->l;
    }
    if (res) {
      res->splay_();
    }
    return res;
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
  ~node(){ delete l; delete r; }
  
  
  void dbg_tree(vector<int> &values) {
    if (l) { l->dbg_tree(values); }
    values.PB(val);
    if (r) { r->dbg_tree(values); }
  }
};


node *tree;
int N;


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N;
  tree = new node(1e9);
  
  for (int i = 0; i < N; i++) {
    int l, r;
    cin >> l >> r;
    
    node *tx = tree = tree->get_at_psum(l - 1);
    //int x = tree->get_pos();
    node *ty = tree = tree->get_at_psum(r - 1);
    //int y = tree->get_pos();
    
    tx->splay_();
    tree = tx;
    int psum = tx->get_prev_sum();
    
    int to_cut = tx->val + psum - l;
    debug(to_cut);
    tx->val -= to_cut;
    tx->sum -= to_cut;
    
    node *rgt = tx->r;
    node *nintv = new node(to_cut + 1);
    node::add_child(tx, nintv, true);
    node::add_child(nintv, rgt, true);
    
    #ifdef LOCAL
    vector<int> tblah;
    tree->dbg_tree(tblah);
    debug("!", tblah, tx, ty);
    #endif
    
    
    if (tx == ty) {
      ty = nintv;
    }
    
    if (ty) {
      ty->splay_();
      tree = ty;
      node *nty = ty->get_next();
      debug(ty->val, nty ? nty->val : 0);
      
      if (nty) {
        int sz = nty->val;
        nty->remove();
        ty->splay_();
        ty->val += sz - 1;
        ty->sum += sz - 1;
        tree = ty;
      }
    }
    
    #ifdef LOCAL
    vector<int> blah;
    tree->dbg_tree(blah);
    debug(i, blah, tree, tx->val, ty->val);
    #endif
  }
  
  cout << tree->size - 1 << "\n";
}