#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

const int N = 300000;
int n,L,pos[N],posb[N],idx[N],posans[N];
ll T;
char dir[N];

int main() {
  scanf("%d%d%lld",&n,&L,&T);
  REP(i,n) {
    scanf("%d %c",&pos[i],&dir[i]); --pos[i];
    idx[i] = i;
  }
  int min_pos = *min_element(pos,pos+n);
  REP(i,n) {
    pos[i] -= min_pos;
    int dist = T % L;
    if (dir[i] == 'L') dist = L - dist;
    posb[i] = (pos[i] + dist) % L;
  }
  sort(idx,idx+n,[](int i, int j) { return pos[i] < pos[j]; });
  sort(posb,posb+n);

  // go partial circle T%L
  set<int> le, ri;
  REP(i,n) if (i != idx[0]) {
    if (dir[i] == 'L') le.insert(pos[i]); else ri.insert(L-pos[i]);
  }
  int le_off = 0, ri_off = 0;
  int t = 2*(T%L), p = 0, dr = dir[idx[0]];
  // p = real position of ant idx[0]
  // le, ri = relative positions in respect to ant idx[0]

  while (t) {
    if (dr == 'R') {
      if (le.empty()) { p += t; break; }
      int po = *le.begin() + le_off; le.erase(le.begin());
      int dist = min(po, t);
      p += dist;
      t -= dist;
      le_off -= dist;
      ri.insert(L - ri_off);
    } else {
      if (ri.empty()) { p -= t; break; }
      int po = *ri.begin() + ri_off; ri.erase(ri.begin());
      int dist = min(po, t);
      p -= dist;
      t -= dist;
      ri_off -= dist;
      le.insert(L - le_off);
    }
    dr = 'R'+'L'-dr;
  }

  p = (p/2 + L) % L;

  int id = find(posb,posb+n,p)-posb;
  if (id+1 < n && posb[id] == posb[id+1] && dr == 'R') ++id;

  // go T/L full circles
  int cost = 0;
  REP(i,n) { if (dir[i] == 'R') cost += 1; else cost -= 1; }
  id = (id + T/L * (n + cost)) % n;
  REP(i,n) {
    posans[idx[i]] = (posb[(i + id) % n] + min_pos) % L;
  }

  REP(i,n) printf("%d%c",posans[i]+1, i==n-1?'\n':' ');
}