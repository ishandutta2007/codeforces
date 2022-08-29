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

template<class C> void mini(C& _a4, C _b4) { _a4 = min(_a4, _b4); }
template<class C> void maxi(C& _a4, C _b4) { _a4 = max(_a4, _b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr << sdbg << '=' << h << endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(CC) {cerr<<#CC<<"=";for(auto&cc:CC)cerr<<cc<<",";cerr<<endl;}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(CC) {}
#define cerr if(0)cout
#endif
struct node{
  node *l, *r, *p;
  int size;
  int val;
  int max;
  int LCsize;
  
  bool flip;
  
  node(int _val,bool edge): l(nullptr), r(nullptr), p(nullptr),
    val(_val), max(_val), size(!edge), flip(0), LCsize(!edge){}
  
  void update(){
    size = LCsize;
    max = val;
    if(l){
      size += l->size;
      maxi(max,l->max);
    }
    if(r){
      size += r->size;
      maxi(max,r->max);
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
    return right?r:l;
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
  
  node* get_max(){
    node* res = this;
    while(1){
      res->touch();
      if(res->l && max == res->l->max){
        res = res->l;
      }else if(res->r && max == res->r->max){
        res = res->r;
      }else break;
    }
    res->splay_();
    return res;
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
  
  ~node(){
    delete l;
    delete r;
  }
};

struct LCnode : node{
  LCnode(int val,bool edge):node(val,edge){};
  
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
      
      if(cur->r) cur->LCsize += cur->r->size;
      if(right) cur->LCsize -= right->size;
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
    par->to_root();
    p = par;
    par->LCsize += size;
    par->update();
  }
  
  void get_path(LCnode* v){
    v->to_root();
    access();
  }
    
  void cut(LCnode* v){
    get_path(v);
    v->p = nullptr;
    l = nullptr;
    update();
  }
  
  bool connected(LCnode* v){
    get_path(v);
    return get_kth(0) == v;
  }
  
  ~LCnode(){
    l = r = nullptr;
  };
};


#define MAX 100001
LCnode* t[MAX];
int zle;
int n,m;

map<LCnode*, PII> edges;
set<pair<int, LCnode*>> secik;
void add_edge(int a,int b,int c){
  debug("dodaje",a,b,c);
  LCnode* pom = new LCnode(c, true);
  debug(pom);
  edges[pom] = {a,b};
  pom->link(t[a]);
  pom->link(t[b]);
  secik.insert({c,pom});
}

void rem_edge(LCnode* e){
  auto xxx = edges.find(e);
  debug("usuwam", xxx->SE.SE, xxx->SE.FI);
  e->cut(t[xxx->SE.SE]);
  e->cut(t[xxx->SE.FI]);
  edges.erase(xxx);
  secik.erase({e->val, e});
  delete e;
}
bool us_max(){
  auto xxx = secik.end();
  xxx--;
  LCnode *e = xxx->SE;
  debug(xxx->FI,e->val);
  auto yyy = edges.find(e);
  int a = yyy->SE.FI;
  int b = yyy->SE.SE;
  int c = e->val;
  debug(a,b,c);
  rem_edge(e);
  t[a]->to_root();
  debug(t[a]->size,t[a]->LCsize);
  if(t[a]->size & 1){
    add_edge(a,b,c);
    return 0;
  }
  return 1;
}
#undef int
int main(){
#define int LL
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  zle = n;
  R(i,n) t[i] = new LCnode(0, false);
  debug(t[0]->LCsize);
  R(i,m){
    debug(i);
    int a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    if(!t[a]->connected(t[b])){
      t[a]->to_root();
      t[b]->to_root();
      if(t[a]->size & t[b]->size & 1){
        zle-=2;
      }
      add_edge(a,b,c);
    }else{
      t[a]->get_path(t[b]);
      if(t[a]->max > c){
        rem_edge((LCnode*)t[a]->get_max());
        add_edge(a,b,c);
      }
    }
    debug(zle);
    cerr << "    WYNIK: ";
    if(zle){
      cout << "-1\n";
    }else{
      while(us_max());
      cout << secik.rbegin()->FI << "\n";
    }
  }
  
  R(i,n) delete t[i];
}