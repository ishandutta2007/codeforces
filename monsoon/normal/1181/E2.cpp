#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
typedef pair<int,int> pii;

const int infty = 1000000000;

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
};

struct node_t {
  int xmin,xmax;
  int hole;  // right-most hole
  int cnt;

  node_t() : xmin(infty), xmax(-infty), hole(-infty), cnt(0) { }
  node_t(int xmin, int xmax, int hole, int cnt) : xmin(xmin), xmax(xmax), hole(hole), cnt(cnt) { }

  static node_t merge(const node_t& L, const node_t& R) {
    node_t I;
    I.xmin = min(L.xmin, R.xmin);
    I.xmax = max(L.xmax, R.xmax);
    I.hole = max(L.hole, L.xmax <= R.hole ? R.hole : -infty);
    if (L.cnt && R.cnt && L.xmax <= R.xmin) {
      I.hole = max(I.hole, R.xmin);
    }
    I.cnt = L.cnt + R.cnt;
    return I;
  }
};


struct box_t {
  int x1,y1,x2,y2;
  int get1(bool isx) const { return isx ? x1 : y1; }
  int get2(bool isx) const { return isx ? x2 : y2; }
};

const int N = 110000;
int n,idx[N];
box_t box[N];


struct gather {
  segment_tree<node_t> tree;
  map<int,int> pos;  // rect index -> position in tree
  set<pii> xx;  // pairs (x1, index)
  bool isx;

  gather(int n, bool isx) : tree(n), isx(isx) { }

  gather split(const vector<int>& indices) {
    int m = indices.size();

    gather other(m, isx);
    int k=0;
    FORE(i,indices) {
      other.xx.insert(make_pair(box[*i].get1(isx), *i));
    }

    FORE(i,other.xx) {
      int idx = i->second;
      other.tree.update(k, node_t{ box[idx].get1(isx), box[idx].get2(isx), -infty, 1 });
      other.pos[idx] = k++;
    }

    FORE(i,indices) {
      tree.update(pos[*i], node_t());
      pos.erase(*i);
      xx.erase(make_pair(box[*i].get1(isx), *i));
    }

    return other;
  }

  vector<int> split_hole() {
    int cnt = tree.vals[1].cnt;
    int pos = lower_bound(tree.vals.begin() + tree.base, tree.vals.begin() + 2*tree.base,
        node_t{ tree.vals[1].hole, -infty, -infty, 0 },
        [](const node_t& lh, const node_t& rh) { return lh.xmin < rh.xmin; })
        - (tree.vals.begin() + tree.base);
    int cnt_b = tree.query(pos, tree.base-1).cnt;
    int cnt_a = cnt - cnt_b;
    set<pii>::iterator it_split = xx.lower_bound(make_pair(tree.vals[1].hole, -1)), it_a, it_b;
    vector<int> indices;

    if (cnt_a <= cnt_b) {
      it_a = xx.begin();
      it_b = it_split;
    } else {
      it_a = it_split;
      it_b = xx.end();
    }

    for (set<pii>::iterator it = it_a; it != it_b; ++it) {
      indices.push_back(it->second);
    }
    return indices;
  }
};

bool recursive(gather& gx, gather& gy) {
  int n = gx.xx.size();
  if (n == 1) { return true; }

  vector<int> indices;

  if (gx.tree.vals[1].hole > -infty) {
    indices = gx.split_hole();
  } else if (gy.tree.vals[1].hole > -infty) {
    indices = gy.split_hole();
  } else {
    return false;
  }

  gather gx_other = gx.split(indices);
  gather gy_other = gy.split(indices);

  return recursive(gx, gy) && recursive(gx_other, gy_other);
}

gather create_gather(bool isx) {
  sort(idx, idx+n, [isx](int i, int j) { return box[i].get1(isx) < box[j].get1(isx); });
  gather g(n, isx);
  REP(i,n) {
    g.tree.update(i, node_t{ box[idx[i]].get1(isx), box[idx[i]].get2(isx), -infty, 1 });
    g.pos[idx[i]] = i;
    g.xx.insert(make_pair(box[idx[i]].get1(isx), idx[i]));
  }
  return g;
}

int main() {
  scanf("%d",&n);
  REP(i,n) {
    box_t& b = box[i];
    scanf("%d%d%d%d",&b.x1,&b.y1,&b.x2,&b.y2);
    idx[i] = i;
  }

  gather gx = create_gather(true), gy = create_gather(false);

  bool ans = recursive(gx, gy);
  puts(ans ? "YES" : "NO");
}