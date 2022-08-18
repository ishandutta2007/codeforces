#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 100000
#define INFT 0x7FFFFFFF

int A[MAXN];
int B[MAXN];

vector<pair<int, int> > mp[20][MAXN];

/* When will u overcome v. */
int beat(int u, int v) {
  int db = B[u] - B[v];
  return (A[v] - A[u] + db - 1) / db;
}

vector<pair<int, int> > build(int u, int v) {
  vector<pair<pair<int, int>, int> > V;
  for(int i = u; i < v; i++) {
    V.push_back(make_pair(make_pair(A[i], B[i]), i));
  }
  sort(V.rbegin(), V.rend());
  
  vector<int> res(1, V[0].second);
  for(int i = 1; i < V.size(); i++) {
    int x = V[i].second;
    if(B[x] <= B[res.back()]) continue;

    while(res.size() > 1 &&
        beat(x, res[res.size() - 1]) <= beat(res.back(), res[res.size() - 2])) {
      res.resize(res.size() - 1);
    }
    res.push_back(x);
  }

  vector<pair<int, int> > ret;
  for(int i = 0; i + 1 < res.size(); i++) {
    ret.push_back(make_pair(beat(res[i + 1], res[i]), res[i]));
  }
  ret.push_back(make_pair(INFT, res.back()));
  return ret;
}

int main() {
  int N, Q;
  cin >> N >> Q;
  for(int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }

  int mbi = 0;
  for(int i = 0; (1 << i) <= N; i++) {
    mbi = i;
    for(int j = 0; j < N; j += (1 << i)) {
      mp[i][j] = build(j, min(N, j + (1 << i)));
    }
  }

  for(int i = 0; i < Q; i++) {
    int L, R, T; cin >> L >> R >> T; L--;
    
    int besti = -1;
    for(int x = L; x < R; ) {
      int bi = x ? __builtin_ctz(x) : mbi;
      while(x + (1 << bi) > R) bi--;
      
      vector<pair<int, int> >& V = mp[bi][x];
      int ri = lower_bound(V.begin(), V.end(), make_pair(T, MAXN))->second;
      if(besti == -1 ||
         A[besti] + 1ll* B[besti] * T < A[ri] + 1ll * B[ri] * T) {
        besti = ri;
      }

      x += 1 << bi;
    }
    printf("%d\n", besti + 1);
  }
}