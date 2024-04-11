#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

int A[100010];
int C[100010];

long long DP[100010];

int main() {
  int N, Q; cin >> N >> Q;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for(int i = 0; i < N; i++) {
    cin >> C[i];
  }

  for(int q = 0; q < Q; q++) {
    memset(DP, 0x88, sizeof(DP));
    long long x, y; cin >> x >> y;

    pair<long long, int> r[2];
    memset(&r, 0, sizeof(r));
    for(int i = 0; i < N; i++) {
      int rid = r[0].second == C[i] ? 1 : 0;
      pair<long long, int> res(r[rid].first + y * A[i], C[i]);
      res.first = max(res.first, DP[C[i]] + x * A[i]);
      DP[C[i]] = max(DP[C[i]], res.first);

      if(res > r[0]) {
        if(C[i] != r[0].second) {
          r[1] = r[0];
        }
        r[0] = res;
      } else if(res > r[1] && C[i] != r[0].second) {
        r[1] = res;
      }
    }

    cout << r[0].first << endl;
  }
  return 0;
}