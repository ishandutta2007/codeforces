#include <bits/stdc++.h>

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
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
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
  int val,size;
  bool flip;
  node(int _val): l(0), r(0), p(0), val(_val), size(1), flip(0){}
  void update(){
    size = 1;              // Wszystkie funckje nalezy wykonywac na korzeniu/korzeniach
//     sum = val;             // drzewa Splay. Zwracaja one nowy korzen/korzenie.
    if(l){                 // Jesli skadinad mamy wskaznik do wierzcholka, nalezy
      size += l->size;     // wykonac na nim splay(). Remove() nie zwalnia pamieci.
//       sum += l->sum;       // Usuwany wierzcholek staje sie korzeniem
    }                      // jednoelementowego drzewa.
    if(r){
      size += r->size;
//       sum += r->sum;
    }
  }
  void touch(){
    if(flip){
      swap(l, r);
      if(l) l->flip ^= 1;
      if(r) r->flip ^= 1;
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
    node* root = node::join(l, r);
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
  ~node(){ delete l; delete r; }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int n,q,m;
  cin >> n >> q >> m;
  node* korz = nullptr;
  R(i,n){
    int pom;
    cin >> pom;
    debug(i,pom);
    korz = node::join(korz, new node(pom));
  }
  R(i,q){
    int typ,l,r;
    cin >> typ >> l >> r;
    l--;
    debug(typ,l,r);
    if(typ == 1){
      auto x = korz->split(r);
      auto y = x.FI->split(r-1);
      auto z = y.FI->split(l);
      korz = node::join(node::join(z.FI, y.SE), node::join(z.SE, x.SE));
    }else{
      auto x = korz->split(r);
      auto y = x.FI->split(l);
      y.SE->reverse();
      korz = node::join(node::join(y.FI,y.SE), x.SE);
    }
  }
  R(i,m){
    int pom;
    cin >> pom;
    pom--;
    korz = korz->get_kth(pom);
    cout << korz->val << " ";
  }
  cout << "\n";
}