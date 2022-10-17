#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 210000, NB = 1<<18;
int n,q;
char s[N];

struct node_t {
  int delta;
  int h;  // deepest
  int minh;  // shallowest
  int ha;  // deep + ancestor
  int ah;  // ancestor + deep
  int diam;  // deep + ancestor + deep
};
int base;
node_t nodes[2*NB];

node_t tree_oper(const node_t& L, const node_t& R) {
  node_t I;
  I.delta = L.delta + R.delta;
  I.h = max(L.h, L.delta + R.h);
  I.minh = min(L.minh, L.delta + R.minh);
  I.ha = max(max(L.ha, R.ha - L.delta), L.h - 2*(R.minh + L.delta));
  I.ah = max(max(L.ah, R.ah - L.delta), -2*L.minh + R.h + L.delta);
  I.diam = max(max(L.diam, R.diam), max(L.ha + R.h + L.delta, L.h + R.ah - L.delta));
  return I;
}

void tree_update(int x) {
  node_t& I = nodes[x + base];
  I.delta = x == n ? 0 : s[x] == '(' ? 1 : -1;
  I.h = 0;
  I.minh = 0;
  I.ha = I.ah = 0;
  I.diam = 0;

  x += base;
  while (x > 1) {
    x /= 2;
    nodes[x] = tree_oper(nodes[2*x], nodes[2*x+1]);
  }
}

int tree_query() {
  return nodes[1].diam;
}

int main() {
  scanf("%d%d%s",&n,&q,s);
  n = 2*n-2;

  base=1;
  while (base < n+1) { base *= 2; }

  REP(i,n+1) { tree_update(i); }

  printf("%d\n", tree_query());
  REP(i,q) {
    int a,b; scanf("%d%d",&a,&b);
    swap(s[--a], s[--b]);
    tree_update(a);
    tree_update(b);
    printf("%d\n", tree_query());
  }
}