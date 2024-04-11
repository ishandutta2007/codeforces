#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 1000005;
const int Maxm = 2104857;

struct node {
       bool flag;
       int n4, n7, n47, n74;
       int l, r;
       node(int ll = 0, int rr = 0) {
                flag = false;
                n4 = n7 = n47 = n74 = true;
                l = ll; r = rr;
       }
};

int n, m;
char s[Maxn];
node st[Maxm];

void Create(int v, int l, int r)
{
     st[v] = node(l, r);
     if (l == r) {
           if (s[l - 1] == '4') { st[v].n4 = st[v].n47 = st[v].n74 = 1; st[v].n7 = 0; }
           else { st[v].n7 = st[v].n47 = st[v].n74 = 1; st[v].n4 = 0; }
     } else {
            int mid = l + r >> 1;
            int lc = 2 * v, rc = 2 * v + 1;
            Create(lc, l, mid); Create(rc, mid + 1, r);
            st[v].n4 = st[lc].n4 + st[rc].n4; st[v].n7 = st[lc].n7 + st[rc].n7;
            st[v].n47 = max(st[lc].n4 + st[rc].n47, st[lc].n47 + st[rc].n7);
            st[v].n74 = max(st[lc].n7 + st[rc].n74, st[lc].n74 + st[rc].n4);
     }
}

void Update(int v, int a, int b)
{
     int l = st[v].l, r = st[v].r;
     if (l == a && r == b) { 
           st[v].flag ^= true; 
           swap(st[v].n4, st[v].n7); swap(st[v].n47, st[v].n74); 
     } else {
          int mid = l + r >> 1;
          int lc = 2 * v, rc = 2 * v + 1;
          if (a <= mid) Update(lc, a, min(mid, b));
          if (mid < b) Update(rc, max(mid + 1, a), b);
          st[v].n4 = st[lc].n4 + st[rc].n4; st[v].n7 = st[lc].n7 + st[rc].n7;
          st[v].n47 = max(st[lc].n4 + st[rc].n47, st[lc].n47 + st[rc].n7);
          st[v].n74 = max(st[lc].n7 + st[rc].n74, st[lc].n74 + st[rc].n4);
          if (st[v].flag) { swap(st[v].n4, st[v].n7); swap(st[v].n47, st[v].n74); }
     }
}

int main()
{
    scanf("%d %d", &n, &m);
    scanf("%s", s);
    Create(1, 1, n);
    while (m--) {
          scanf("%s", s);
          if (s[0] == 'c') printf("%d\n", st[1].n47);
          else {
               int a, b; scanf("%d %d", &a, &b);
               Update(1, a, b);
          }
    }
    return 0;
}