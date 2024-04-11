#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

const int infty = 1000000000;

int msb(int x) { return 31 - __builtin_clz(x); }

template<class T>
struct segment_tree {

  int n,base;
  vector<T> vals;

  segment_tree(int n) : n(n) {
    base = 1;
    while (base < n) base *= 2;
    vals.resize(2*base);
  }

  void update(int x, const T& val) {
    vals[x += base] = val;
    while (x > 1) {
      update_inner(x /= 2);
    }
  }

  void update_inner(int x) {
    vals[x] = T::merge(vals[2*x], vals[2*x+1]);
  }

  T query(int a, int b) const {
    T val_a = vals[a += base];
    if (a == b) { return val_a; }
    T val_b = vals[b += base];
    while (a/2 != b/2) {
      if (a%2 == 0) { val_a = T::merge(val_a, vals[a+1]); }
      if (b%2 == 1) { val_b = T::merge(vals[b-1], val_b); }
      a /= 2;
      b /= 2;
    }
    return T::merge(val_a, val_b);
  }

  int left(int x) const { return (base >> msb(x)) * (x - (1 << msb(x))); }
  int right(int x) const { return left(x) + (base >> msb(x)); }
};

struct node_t {
  int xmin,xmax;
  int hole;  // right-most hole

  node_t() : xmin(infty), xmax(-infty), hole(-infty) { }
  node_t(int xmin, int xmax, int hole) : xmin(xmin), xmax(xmax), hole(hole) { }

  static node_t merge(const node_t& L, const node_t& R) {
    node_t I;
    I.xmin = min(L.xmin, R.xmin);
    I.xmax = max(L.xmax, R.xmax);
    I.hole = max(L.hole, L.xmax <= R.hole ? R.hole : -infty);
    if (L.xmax <= R.xmin && R.xmin < infty) {
      I.hole = max(I.hole, R.xmin);
    }
    return I;
  }
};


struct box_t {
  int x1,y1,x2,y2;
};

const int N = 110000;
int n,idx_x[N],idx_y[N];
box_t box[N];

bool recursive(vector<int> idx_x, vector<int> idx_y) {
  int n = idx_x.size();
  if (n == 1) { return true; }

  segment_tree<node_t> stx(n), sty(n);
  REP(i,n) {
    stx.update(i, node_t{ box[idx_x[i]].x1, box[idx_x[i]].x2, -infty });
    sty.update(i, node_t{ box[idx_y[i]].y1, box[idx_y[i]].y2, -infty });
  }

  set<int> left;
  vector<int> idx_x_l, idx_x_r, idx_y_l, idx_y_r;

  if (stx.vals[1].hole > -infty) {
    int hole = stx.vals[1].hole;
    REP(i,n) if (box[idx_x[i]].x2 <= hole) { left.insert(idx_x[i]); }
  } else if (sty.vals[1].hole > -infty) {
    int hole = sty.vals[1].hole;
    REP(i,n) if (box[idx_y[i]].y2 <= hole) { left.insert(idx_y[i]); }
  } else {
    return false;
  }

  REP(i,n) {
    (left.find(idx_x[i]) != left.end() ? idx_x_l : idx_x_r).push_back(idx_x[i]);
    (left.find(idx_y[i]) != left.end() ? idx_y_l : idx_y_r).push_back(idx_y[i]);
  }
  return recursive(idx_x_l, idx_y_l) && recursive(idx_x_r, idx_y_r);
}


int main() {
  scanf("%d",&n);
  REP(i,n) {
    box_t& b = box[i];
    scanf("%d%d%d%d",&b.x1,&b.y1,&b.x2,&b.y2);
    idx_x[i] = idx_y[i] = i;
  }

  sort(idx_x, idx_x+n, [](int i, int j) { return box[i].x1 < box[j].x1; });
  sort(idx_y, idx_y+n, [](int i, int j) { return box[i].y1 < box[j].y1; });

  vector<int> _idx_x, _idx_y;
  REP(i,n) {
    _idx_x.push_back(idx_x[i]);
    _idx_y.push_back(idx_y[i]);
  }

  bool ans = recursive(_idx_x, _idx_y);
  puts(ans ? "YES" : "NO");
}