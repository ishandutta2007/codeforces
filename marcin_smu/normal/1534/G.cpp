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
  int val,len;
  int size;
  int lazy;
  node(int _val,int _len): l(0), r(0), p(0), val(_val), len(_len), size(len){}
  void update(){
    size = len;
    if(l){
      size += l->size;
    }
    if(r){
      size += r->size;
    }
  }
  void add(int x){
    val += x;
    lazy += x;
  }
  void touch(){
    if(lazy != 0){
      if(l) l->add(lazy);
      if(r) r->add(lazy);
      lazy = 0;
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
      if(k < res->len){
        res->splay_();
        return res;
      }
      k -= res->len;
      res = res->r;
    }
  }
  node* get_zero(){
    node* res = this;
    while(1){
      debug(res->val);
      res->touch();
      if(res->val <= 0){
        if(res->r)res = res->r;
        else break;
      }else{
        if(res->l){
          debug("??", l);
          res = res->l;
        }else break;
      }
    }
    res->splay_();
    return res;
  }
  pair<node*, node*> split(int k){
    if(k == 0) return {nullptr, this};
    if(k >= size) return {this, nullptr};
    node* x = get_kth(k);
    node* res = x->l;
    if(x->l){
      x->l->p = nullptr;
    }
    x->l = nullptr;
    x->update();
    int ressiz = res ? res->size : 0;
    if(ressiz < k){
      int pom = k - ressiz;
      x->len -= pom;
      x->size -= pom;
      res = join(res, new node(x->val, pom));
    }
    return {res, x};
  }
  pair<node*, node*> splitzero(){
    node* x = get_zero();
    if(x->val >= 0){
      node* res = x->l;
      if(x->l){
        x->l->p = nullptr;
      }
      x->l = nullptr;
      x->update();
      return {res, x};
    }else{
      node* res = x->r;
      if(x->r){
        x->r->p = nullptr;
      }
      x->r = nullptr;
      x->update();
      return {x, res};
    }
  }
  int sumuj(){
    touch();
    int res = len * val;
    if(l)res += l->sumuj();
    if(r)res += r->sumuj();
    return res;
  }
  
  void pri(){
#ifdef LOCAL
    touch();
    cout << "(";
    if(l)l->pri();else cout << "emp";
    cout << len << "x" << val;
    if(r)r->pri();
    cout << ")";
#endif
  }
  ~node(){ delete l; delete r; }
};


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int n;
  cin >> n;
  vector<PII> pkt(n);
  R(i,n){
    cin >> pkt[i].FI >> pkt[i].SE;
  }
  sort(ALL(pkt),[](PII a, PII b){
    return a.FI + a.SE < b.FI + b.SE;
  });
  node *root = new node(0, 1);
  int t = 0;
  int res = 0;
  R(i,n){
    int ak = pkt[i].FI + pkt[i].SE;
    debug(ak,t);
    if(ak != t){
      auto x = root->splitzero();
      debug("tu\n");
      root = node::join(x.FI, node::join(new node(0, ak - t), x.SE));
    }
    debug(ak - t);
    root->pri();
    cerr << "\n";
    debug("Oo");
    t = ak;
    auto x = root->split(pkt[i].FI);
    if(x.FI)
      x.FI->add(-1);
    x.SE->add(1);
    root = node::join(x.FI, x.SE);
    res += pkt[i].FI;
    debug(i,pkt[i]);
    root->pri();
    cerr << "\n";
  }
  
  auto x = root->splitzero();
  res += x.FI->sumuj();
  cout << res << "\n";
  delete x.FI;
  delete x.SE;
}