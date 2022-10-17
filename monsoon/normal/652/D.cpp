#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

namespace cp {

struct tree_2d_t {
  vector<pair<int,int> > pts;
  vector<vector<int> > nodes;
  int base;
  int n;

  tree_2d_t(const vector<pair<int,int> >& points) {
    pts = points;
    sort(pts.begin(), pts.end());
    n = pts.size();
    base = 1;
    while (base < n) { base *= 2; }
    nodes.resize(2*base);
    REP(i, n) {
      nodes[base + i].push_back(pts[i].second);
    }
    for (int i = base-1; i >= 1; --i) {
      merge(nodes[2*i].begin(), nodes[2*i].end(),
          nodes[2*i+1].begin(), nodes[2*i+1].end(),
          back_inserter(nodes[i]));
    }
  }

  int query(int x, int yl, int yr) {
    yl = lower_bound(nodes[x].begin(), nodes[x].end(), yl) - nodes[x].begin();
    yr = lower_bound(nodes[x].begin(), nodes[x].end(), yr+1) - nodes[x].begin();
    return yr - yl;
  }

  int query(int xl, int xr, int yl, int yr) {

    const int infty = 2000000000;
    xl = lower_bound(pts.begin(), pts.end(), make_pair(xl, -infty)) - pts.begin();
    xr = lower_bound(pts.begin(), pts.end(), make_pair(xr+1, -infty)) - pts.begin();
    int cnt = 0;
    xl += base;
    xr += base-1;
    cnt += query(xl, yl, yr);
    if (xl != xr) {
      cnt += query(xr, yl, yr);
    }
    while (xl/2 != xr/2) {
      if (~xl&1) { cnt += query(xl+1, yl, yr); }
      if (xr&1) { cnt += query(xr-1, yl, yr); }
      xl /= 2;
      xr /= 2;
    }
    return cnt;
  }
};

}

int n;
vector<pair<int,int>> p;

int main() {
  scanf("%d",&n);
  p.resize(n);
  REP(i,n) {
    scanf("%d%d",&p[i].first,&p[i].second);
  }
  cp::tree_2d_t t(p);
  REP(i,n) {
    int ans = t.query(p[i].first,p[i].second, p[i].first,p[i].second);
    printf("%d\n",ans-1);
  }
}