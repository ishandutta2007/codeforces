#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

struct node_t {
  int sum;
  int max_suf;

  static node_t merge(const node_t& L, const node_t& R) {
    node_t I;
    I.sum = L.sum + R.sum;
    I.max_suf = max(L.max_suf + R.sum, R.max_suf);
    return I;
  }
};


const int N = 300100, NB = 1<<20;
int n,m,q,a[N],b[N],qt[N],qi[N],qv[N];
int xs[3*N],xn;
int base;
node_t tree[2*NB];

void update(int x, int v) {
  x += base;
  tree[x].sum += v;
  tree[x].max_suf += v;
  while (x > 1) {
    x /= 2;
    tree[x] = node_t::merge(tree[2*x], tree[2*x+1]);
  }
}

int findit(int v) {
  int need = 0;
  while (v < base) {
    if (tree[2*v+1].max_suf > need) { v = 2*v+1; }
    else { need -= tree[2*v+1].sum; v = 2*v; }
  }
  return v-base;
}

int main() {
  scanf("%d%d",&n,&m);
  REP(i,n) { scanf("%d",&a[i]); xs[i] = a[i]; }
  REP(i,m) { scanf("%d",&b[i]); xs[n+i] = b[i]; }
  scanf("%d",&q);
  REP(i,q) {
    scanf("%d%d%d",&qt[i],&qi[i],&qv[i]); --qi[i];
    xs[n+m+i] = qv[i];
  }
  sort(xs,xs+n+m+q);
  xn = unique(xs,xs+n+m+q)-xs;

  base = 1;
  while (base < xn) base *= 2;
  REP(i,n) { update( lower_bound(xs,xs+xn,a[i])-xs, 1 ); }
  REP(i,m) { update( lower_bound(xs,xs+xn,b[i])-xs, -1 ); }
  REP(i,q) {
    if (qt[i] == 1) {
      update( lower_bound(xs,xs+xn,a[qi[i]])-xs, -1 );
      a[qi[i]] = qv[i];
      update( lower_bound(xs,xs+xn,a[qi[i]])-xs, 1 );
    } else {
      update( lower_bound(xs,xs+xn,b[qi[i]])-xs, 1 );
      b[qi[i]] = qv[i];
      update( lower_bound(xs,xs+xn,b[qi[i]])-xs, -1 );
    }

    int ans = -1;
    if (tree[1].max_suf > 0) {
      ans = xs[findit(1)];
    }
    printf("%d\n",ans);
  }
}