#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

#define MAXN (1<<17)

int ID[MAXN];
int RID[MAXN];

int NL[MAXN];
int NR[MAXN];
int D[MAXN];

string S[MAXN];

vector<int> E[MAXN];

int BIT[MAXN];

void bit_add(int x, int v) {
  for(int i = x | MAXN; i < (MAXN << 1); i += i & -i) BIT[i ^ MAXN] += v;
}

int bit_get(int x) {
  int ret = BIT[0];
  for(int i = x; i; i &= i - 1) ret += BIT[i];
  return ret;
}

void dfs(int x, int d, int& id) {
  RID[ID[x] = id++] = x;
  D[x] = d;
  NL[x] = id;
  for(int i = 0; i < E[x].size(); i++) {
    dfs(E[x][i], d + 1, id);
  }
  NR[x] = id;
}

int main() {
  int N; cin >> N;
  vector<int> roots;
  for(int i = 0; i < N; i++) {
    cin >> S[i];
    int p; cin >> p;
    if(p == 0) {
      roots.push_back(i);
    } else {
      E[p - 1].push_back(i);
    }
  }

  int id = 0;
  for(int i = 0; i < roots.size(); i++) {
    dfs(roots[i], 0, id);
  }

  map<int, vector<pair<int, int> > > xs;
  map<pair<int, string>, int> last_name;
  for(int i = 0; i < N; i++) {
    int j = RID[i];
    int lid = i + 1;
    swap(lid, last_name[make_pair(D[j], S[j])]);
    xs[D[j]].push_back(make_pair(lid - 1, i));
  }

  int Q; cin >> Q;
  vector<pair<pair<int, int>, pair<int, int> > > qs;
  for(int i = 0; i < Q; i++) {
    int u, k; cin >> u >> k; u--;
    qs.push_back(make_pair(make_pair(D[u] + k, NL[u]), make_pair(NR[u], i)));
  }
  sort(qs.begin(), qs.end());

  vector<int> R(Q, -1);
  memset(BIT, 0, sizeof(BIT));
  for(int i = 0; i < qs.size(); ) {
    int ei;
    for(ei = i; ei < qs.size() &&
        qs[ei].first.first == qs[i].first.first; ei++);

    vector<pair<int, int> >& xds = xs[qs[i].first.first];
    sort(xds.begin(), xds.end());

    int j;
    for(j = 0; i < ei; i++) {
      while(j < xds.size() && xds[j].first < qs[i].first.second) {
        bit_add(xds[j++].second + 1, 1);
      }
      R[qs[i].second.second] =
          bit_get(qs[i].second.first) - bit_get(qs[i].first.second);
    }
    while(j > 0) {
      bit_add(xds[--j].second + 1, -1);
    }
  }

  for(int i = 0; i < Q; i++) {
    cout << R[i] << '\n';
  }
  return 0;
}