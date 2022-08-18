#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

#define MAXN 150010

int mq_a, mq_b, mq_va, mq_vb;
int mq_v[MAXN];
int mq_i[MAXN];

/* Call once before use or to clear previous use. */
void mq_init() {
  mq_a = mq_b = mq_va = mq_vb = 0;
}

/* Push the value v onto end of the queue. O(1) amortized. */
void mq_push(int v) {
  while(mq_va < mq_vb && mq_v[mq_vb - 1] >= v) mq_vb--;
  mq_v[mq_vb] = v;
  mq_i[mq_vb++] = mq_b++;
}

/* Pop the front value of the queue. */
void mq_pop() {
  mq_va += mq_a++ == mq_i[mq_va];
}

/* Return the maximum value in the queue. */
int mq_min() {
  return mq_v[mq_va];
}

int DP[2][MAXN];

int main() {
  int N, M, D; cin >> N >> M >> D;

  long long result = 0;
  vector<int> T(M), X(M);
  vector<int> TS;
  for(int i = 0; i < M; i++) {
    long long a, b, t;
    cin >> X[i] >> b >> T[i];
    TS.push_back(T[i]);
    result += b;
    X[i]--;
  }
  sort(TS.begin(), TS.end());
  TS.resize(unique(TS.begin(), TS.end()) - TS.begin());

  vector<vector<int> > FW(TS.size());
  for(int i = 0; i < M; i++) {
    int ti = lower_bound(TS.begin(), TS.end(), T[i]) - TS.begin();
    FW[ti].push_back(X[i]);
  }

  for(int ti = 0; ti < TS.size(); ti++) {
    int bt = ti & 1;
    int dd = ti == 0 ? 1 : (int)min(1ll * (TS[ti] - TS[ti - 1]) * D, 1ll * N);

    mq_init();
    int qb = 0;
    for(int x = 0; x < N; x++) {
      while(qb < N && qb <= x + dd) {
        mq_push(DP[!bt][qb++]);
      }
      if(dd < x) {
        mq_pop();
      }

      DP[bt][x] = mq_min();
      for(int i = 0; i < FW[ti].size(); i++) {
        DP[bt][x] += abs(FW[ti][i] - x);
      }
    }
  }

  int bt = !(TS.size() & 1);
  cout << result - *min_element(DP[bt], DP[bt] + N) << endl;
  return 0;
}