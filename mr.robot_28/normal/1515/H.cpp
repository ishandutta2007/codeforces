#include <cstdio>
#include <cassert>
#include <utility>
#include <functional>
#define X first
#define Y second
const int mod = 998244353;
template<int k>
struct node{
  node <k-1>* chd[2];
  int cnt;
  int lazy;
  int has[2];
  int get_cnt(){
    assert(this!=NULL);
    return cnt;
  }
  int get_has(int d){
    assert(this!=NULL);
    push();
    assert(has[d]<(1<<(k+1)));
    return has[d];
  }
  node():chd{NULL, NULL}, has{0, 0}, cnt(0),lazy(0){};
  node(node<k-1>* l,node <k-1>* r):chd{l,r},cnt(0),lazy(0),has{0,0}{
    if(l){
      cnt+=l->get_cnt();
      has[0]|=l->get_has(0)|(1<<k);
      has[1]|=l->get_has(1);
    }
    if(r){
      cnt+=r->get_cnt();
      has[0]|=r->get_has(0);
      has[1]|=r->get_has(1)|(1<<k);
    }
    assert(has[0]<(1<<(k+1)));
    assert(has[1]<(1<<(k+1)));
  }
  void push(){
    assert(lazy<(1<<(k+1)));
    if(!lazy) return;
    if(lazy&(1<<k)){
      std::swap(chd[0],chd[1]);
      if((has[0]^has[1])&(1<<k)){
	has[0]^=(1<<k);
	has[1]^=(1<<k);
      }
      lazy^=(1<<k);
    }
    int flip=(has[0]^has[1])&lazy;
    has[0]^=flip;
    has[1]^=flip;
    if(chd[0]) chd[0]->lazy^=lazy;
    if(chd[1]) chd[1]->lazy^=lazy;
    lazy=0;
    assert(has[0]<(1<<(k+1)));
    assert(has[1]<(1<<(k+1)));
  }
};

template<>
struct node<-1>{
  int lazy;
  node():lazy(0){
  }
  int get_cnt(){
    assert(this!=NULL);
    return 1;
  }
  int get_has(int d){
    assert(this!=NULL);
    return 0;
  }
};

template<int k>
node<k>* create(int x){
  if(x&(1<<k)){
    return new node<k>(NULL,create<k-1>(x));
  }else{
    return new node<k>(create<k-1>(x),NULL);
  }
}
template<> node<-1>*create(int x)
{
    return new node<-1>();
}
template<int k> std::pair <node<k - 1>*, node< k - 1>*> destruct(node <k>*a)
{
  assert(a!=NULL);
    a -> push();
    auto res = std::make_pair(a -> chd[0], a -> chd[1]);
    delete a;
    return res;
}
template <int k> node <k>* join(node<k -1>* l, node <k - 1>* r)
{
    if(l == NULL && r == NULL)
    {
        return NULL;
    }
    return new node<k>(l, r);
}
template<int k> node<k>* merge(node<k> *a, node<k> *b)
{
    if(!a)
    {
        return b;
    }
    if(!b)
    {
        return a;
    }
    auto aa = destruct(a);
    auto bb = destruct(b);
    node <k - 1> *l = merge<k - 1>(aa.X, bb.X);
    node <k - 1> *r = merge<k - 1>(aa.Y, bb.Y);
    return join<k>(l, r);
}
template<>node<-1>* merge(node<-1>*a, node<-1>* b)
{
    if(!a)
    {
        return b;
    }
    if(!b)
    {
        return a;
    }
    delete b;
    return a;
}
template<int k>
std::pair<node<k>*,node<k>*> split(node<k>* a,int thres){
  if(a==NULL){
    return {NULL,NULL};
  }
  if(thres<=0) return {NULL,a};
  if(thres>=(1<<(k+1))) return {a,NULL};
  assert(k>=0);
  auto aa =destruct(a);
  if(thres<(1<<k)){
    node<k-1>* l,*r;
    std::tie(l,r)=split<k-1>(aa.first,thres);
    return std::make_pair(join<k>(l,NULL),join<k>(r,aa.second));
  }else if(thres>(1<<k)){
    node<k-1>* l,*r;
    std::tie(l,r)=split<k-1>(aa.second, thres-(1<<k));
    return std::make_pair(join<k>(aa.first,l),join<k>(NULL,r));
  }else{
    return std::make_pair(join<k>(aa.first,NULL),join<k>(NULL,aa.second));
  }
}

template<>
std::pair<node<-1>*,node<-1>*> split<-1>(node<-1>* a,int thres){
  assert(0);
}
template<int k> node<k>* update(node<k> *a, int val)
{
    if(a == NULL) return NULL;
    a -> push();
  assert(val<(1<<(k+1)));
    if((val & a -> has[0] & a -> has[1]) == 0)
    {
        a -> lazy ^= (val & a ->has[0]);
        return a;
    }
    node<k - 1>*l, *r;
    std::tie(l, r) = destruct(a);
    l = update<k - 1>(l, val & ~(1 << k));
    r = update<k - 1>(r, val & ~(1 << k));
    if(val & (1 << k))
    {
        return join<k>(NULL, merge<k - 1>(l, r));
    }
    else
    {
        return join<k>(l, r);
    }
}
template<>node<-1>*update(node<-1>*a, int val)
{
    return a;
}

int main()
{
  //  ifstream cin("input1.txt.4c");
//    ios_base::sync_with_stdio(0);
  //  cin.tie(0);
    //cout.tie(0);
    node<19>* root = NULL;
    int n, q;
    //cin >> n >> q;
    scanf("%d %d", &n, &q);
   // printf("A\n");
    for(int i = 0; i< n; i++)
    {
        int a;
        scanf("%d", &a);
      //  root = create<19> (a);
        root = merge(root, create<19>(a));
    }
    while(q--)
    {
        int t, l, r;
        scanf("%d%d%d", &t, &l, &r);
        node<19>*left, *right;
        std::tie(left, root) = split(root, l);
        std::tie(root, right) = split(root, r + 1);
        if(t == 4)
        {
            if(root)
            {
                printf("%d\n", root -> cnt);
               // return 0;
            }
            else
            {
                printf("0\n");
                //return 0;
            }
        }
        else
        {
            int x;
            scanf("%d", &x);
            if(root != NULL)
            {
                if(t == 1)
                {
                    root -> lazy ^= ((1 << 20) - 1);
                    root = update(root, x ^ ((1 << 20) - 1));
                    root -> lazy ^= ((1 << 20) - 1);
                }
                else if(t == 2)
                {
                    root = update(root, x);
                }
                else
                {
                    root -> lazy ^=x;
                }
            }
        }
        root = merge(root, left);
        root = merge(root, right);
    }
    return 0;
}