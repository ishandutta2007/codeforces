#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int CC[300][300];
int GG[300][300];

map<int, int> remap;
map<int, int> reassn;

map<int, vector<int> > geos;
map<int, int> num;

int get_color(map<int, int>& remp, int orig_color) {
  if(remp.find(orig_color) == remp.end()) return orig_color;
  int x = remp[orig_color];
  return x == orig_color ? x : (remp[orig_color] = get_color(remp, x));
}

map<pair<int, int>, int> windmp;

int get_wind(int r, int c, int vr, int vc) {
  pair<int, int> s = make_pair(vr - r, vc - c);
  if(windmp.find(s) == windmp.end()) cout << "problem" << endl;
  return windmp[s];
}

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int main() {
  int rr = 0;
  int cc = 0;
  int ind = 0;
  for(int i = 0; i < 1300; i++) {
    int ln = (i + 2) / 2;
    int dir = i % 4;
    for(int k = 0; k < ln; k++) {
      windmp[make_pair(rr, cc)] = ind++;
      rr += dr[dir];
      cc += dc[dir];
    }
  }

  int N, M; cin >> N >> M;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      //CC[i][j] = rand() % 100;
      cin >> CC[i][j];
      ++num[CC[i][j]];
    }
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> GG[i][j];
      //GG[i][j] = rand() % 100;
    }
  }
  int r, c; cin >> r >> c; r--; c--;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(GG[i][j] != -1 && (i != r || j != c)) {
        geos[CC[i][j]].push_back(i * M + j);
      }
    }
  }
  queue<int> q;
  q.push(r * M + c);
  long long result = 0;
  int nc = 1000000010;
  while(!q.empty()) {
    int v = q.front(); q.pop();
    int vr = v / M;
    int vc = v % M;

    int geo = get_color(reassn, GG[vr][vc]);
    int panel = get_color(reassn, get_color(remap, CC[vr][vc]));
    if(panel == get_color(reassn, 0) || panel == geo) continue;

    vector<int>& g = geos[panel];
    vector<pair<int, int> > gg;
    for(int i = 0; i < g.size(); i++) {
      int gr = g[i] / M;
      int gc = g[i] % M;
      gg.push_back(make_pair(get_wind(vr, vc, gr, gc), g[i]));
    }
    g.clear();
    sort(gg.begin(), gg.end());
    for(int i = 0; i < gg.size(); i++) {
      q.push(gg[i].second);
    }

    if(num[geo] == 0) {
      geo = reassn[geo] = nc++;
    }

    result += num[panel];
    num[geo] += num[panel];
    num[panel] = 0;

    remap[panel] = geo;
  }
  cout << result << endl;
}