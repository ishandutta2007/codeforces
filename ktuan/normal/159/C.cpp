#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#include <map>
#include <cstring>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Fit(i,v) for(typeof(v.begin()) i=v.begin();i!=v.end();++i)

typedef vector<int> VI;

int container[200020 * 4];
int nct;

struct IntervalTree {
  int *a;
  int n;

  void init(int n) {
    this->n = n;
    a = container + nct;
    nct += n * 4;
    fill(0, 0, n - 1);
  }

  void fill(int i, int l, int r) {
    a[i] = r - l + 1;
    if (l < r) {
      int m = (l + r) / 2;
      fill(2 * i + 1, l, m);
      fill(2 * i + 2, m + 1, r);
    }
  }

  int findCurrentK(int i, int l, int r, int k) {
    if (l == r) return l;
    int m = (l + r) / 2;
    if (k < a[2 * i + 1]) return findCurrentK(2 * i + 1, l, m, k);
    else return findCurrentK(2 * i + 2, m + 1, r, k - a[2 * i + 1]);
  }

  void erasePositionK(int i, int l, int r, int k) {
    if (l == r) {
      a[i] = 0;
      return;
    }
    int m = (l + r) / 2;
    if (k <= m) erasePositionK(2 * i + 1, l, m, k);
    else erasePositionK(2 * i + 2, m + 1, r, k);
    a[i] = a[2 * i + 1] + a[2 * i + 2];
  }

  bool isErased(int i, int l, int r, int k) {
    if (l == r) return a[i] == 0;
    int m = (l + r) / 2;
    if (k <= m) return isErased(2 * i + 1, l, m, k);
    else return isErased(2 * i + 2, m + 1, r, k);
  }
};

int k;
char a[200020], buf[22];
int n;
int c[26];
IntervalTree tree[26];
int pos[200020];
char output[200020];
int nOutput;

int main() {
  scanf("%d", &k);
  gets(a);
  gets(a);
  n = strlen(a);
  for (int i = n; i < n * k; ++i) a[i] = a[i -n];
  n *= k;
  Rep (i, n) {
    a[i] -= 'a';
    pos[i] = c[a[i]];
    c[a[i]]++;
  }
  Rep (i, 26) {
    tree[i].init(c[i]);
  }
  int n_queries;
  scanf("%d", &n_queries);
  Rep (i, n_queries) {
    int p;
    scanf("%d%s", &p, buf);
    int c = buf[0] - 'a';
    --p;
    int k = tree[c].findCurrentK(0, 0, tree[c].n - 1, p);
    tree[c].erasePositionK(0, 0, tree[c].n - 1, k);
  }
  Rep (i, n) if (!tree[a[i]].isErased(0, 0, tree[a[i]].n - 1, pos[i])) {
    output[nOutput++] = (char) (a[i] + 'a');
  }
  puts(output);
  return 0;
}