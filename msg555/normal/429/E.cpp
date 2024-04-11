#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

#define MAXN 100010

int N;
pair<int, int> RMAP[2 * MAXN];
int COL[MAXN];

void do_color(int u, int c) {
  pair<int, int> rid = RMAP[u];
  if(rid.second == -1) {
    COL[rid.first] = c;
  } else {
    do_color(rid.first, c);
    do_color(rid.second, 1 - c);
  }
}

int main() {
  cin >> N;

  set<pair<pair<int, int>, int> > segs;
  for(int i = 0; i < N; i++) {
    int L, R;
    cin >> L >> R;
    RMAP[i] = make_pair(i, -1);
    segs.insert(make_pair(make_pair(L, R + 1), i));
  }

  int NN = N;
  while(!segs.empty()) {
    int id = segs.begin()->second;
    pair<int, int> loc = segs.begin()->first;
    segs.erase(segs.begin());

    if(segs.empty() || loc.second <= segs.begin()->first.first) {
      do_color(id, 0);
    } else {
      int nid = segs.begin()->second;
      pair<int, int> nloc = segs.begin()->first;
      segs.erase(segs.begin());

      if(loc.second < nloc.second) {
        RMAP[NN] = make_pair(nid, id);
        segs.insert(make_pair(make_pair(loc.second, nloc.second), NN));
        NN++;
      } else if(nloc.second < loc.second) {
        RMAP[NN] = make_pair(id, nid);
        segs.insert(make_pair(make_pair(nloc.second, loc.second), NN));
        NN++;
      } else {
        do_color(id, 0);
        do_color(nid, 1);
      }
      continue;
    }
  }

  for(int i = 0; i < N; i++) {
    if(i) cout << ' ';
    cout << COL[i];
  }
  cout << endl;

  return 0;
}