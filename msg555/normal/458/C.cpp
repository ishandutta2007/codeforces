#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

vector<int> V[100010];

#define MAXW (1 << 14)

struct agg {
  agg() : tot(0), sum(0) {
  }

  int tot;
  int sum;
};

agg seg[2 * MAXW];

int xminsum(int amt) {
  int A = 0;
  int B = MAXW;
  int res = 0;
  for(int x = 1; ; ) {
    if(A + 1 == B) {
      res += amt * A;
      break;
    }
    int M = (A + B) / 2;
    int x0 = 2 * x + 0;
    int x1 = 2 * x + 1;
    if(amt < seg[x0].tot) {
      x = x0;
      B = M;
    } else {
      x = x1;
      res += seg[x0].sum;
      amt -= seg[x0].tot;
      A = M;
    }
  }
  return res;
}

void xinsert(int val) {
  int A = 0;
  int B = MAXW;
  for(int x = 1; ; ) {
    seg[x].tot++;
    seg[x].sum += val;
    if(A + 1 == B) break;

    int M = (A + B) / 2;
    if(val < M) {
      x = 2 * x + 0;
      B = M;
    } else {
      x = 2 * x + 1;
      A = M;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int N; cin >> N;
  int M = 1;
  for(int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    V[a].push_back(b);
    M = max(M, a + 1);
  }
  for(int i = 0; i < M; i++) {
    sort(V[i].begin(), V[i].end());
    for(int j = 1; j < V[i].size(); j++) {
      V[i][j] += V[i][j - 1];
    }
  }

  vector<pair<int, int> > vlst;
  for(int i = 1; i < M; i++) {
    if(V[i].empty()) continue;
    vlst.push_back(make_pair(V[i].size(), i));
  }
  sort(vlst.begin(), vlst.end());
  reverse(vlst.begin(), vlst.end());
  M = vlst.size();

  int options = 0;
  int result = 0x7FFFFFFF;
  for(int i = 1; i <= N; i++) {
    int tot = V[0].size();
    int cst = 0;
    for(int j = 0; j < M; j++) {
      int id = vlst[j].second;
      cst += V[id][V[id].size() - i];
      tot += vlst[j].first - (i - 1);
    }
    if(tot + options >= i) {
      if(tot < i) {
        cst += xminsum(i - tot);
      }
      //cout << i << ": " << cst << ", " << tot << endl;
      result = min(result, cst);
    }

    for(int j = 0; j < M; j++) {
      int id = vlst[j].second;
      int pos = V[id].size() - i;
      xinsert(V[id][pos] - (pos == 0 ? 0 : V[id][pos - 1]));
      options++;
    }
    while(M > 0 && vlst[M - 1].first == i) {
      M--;
    }
  }
  cout << result << endl;

  return 0;
}