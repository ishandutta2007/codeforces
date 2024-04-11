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

int RES = 0;
struct node{
  node *l, *r, *p;
  int val, add, ma;
  node(int _val): l(0), r(0), p(0), val(_val), add(0), ma(_val){}
  void update(){
    ma = val;
    if(l) maxi(ma, l->ma);
    if(r) maxi(ma, r->ma);
  }
  void touch(){
    if(l){
      l->add += add;
      l->val += add;
      l->ma += add;
    }
    if(r){
      r->add += add;
      r->val += add;
      r->ma += add;
    }
    add = 0;
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
  void wys(int toadd){
    if(l)l->wys(toadd + add);
    cerr << toadd + val <<  ", ";
    if(r)r->wys(toadd + add);
  }
  ~node(){RES++; delete l; delete r; }
};

pair<node*,node*> dziel(node* k,int x){
  node *ak = k;
  while(1){
    ak->touch();
    if(ak->val < x){
      ak = ak->r;
    }else{
      if(ak->l && ak->l->ma >= x)
        ak = ak->l;
      else
        break;
    }
  }
  ak->splay();
  node* res = ak->l;
  ak->l = nullptr;
  ak->update();
  if(res)res->p = nullptr;
  return {res,ak};
}

int n;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  node *korz = new node(2e9);
  R(i,n){
    int x,y;
    cin >> x >> y;
    node *a, *b, *c;
    tie(a,b) = dziel(korz,x);
    tie(b,c) = dziel(b,y);
    c = c->get_first();
    if(c->val != 2e9){
      node* pom = c;
      c = c->remove();
      delete pom;
    }
    if(b){
      b->add++;
      b->val++;
      b->ma++;
    }
#ifdef LOCAL
    cerr << "\n" << x << " " << y;
    cerr << "\na: ";
    if(a)a->wys(0);
    cerr << "\n";
    
    cerr << "b: ";
    if(b)b->wys(0);
    cerr << "\n";

#endif

    korz = node::join(node::join(a,new node(x)),node::join(b,c));
#ifdef LOCAL
    korz->wys(0);
    cerr << "\n";
#endif
  }
  RES = 0;
  delete korz;
  cout << RES-1 << endl;
}