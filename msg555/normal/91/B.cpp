#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A;
  for(int i = 0; i < N; i++) {
    int x; cin >> x;
    A.push_back(x);
  }

  /* age, dist */
  /* age increasing with dist */
  vector<int> R;
  vector<pair<int, int> > B;
  for(int i = N - 1; i >= 0; i--) {
    int p = lower_bound(B.begin(), B.end(), make_pair(-A[i], 1)) - B.begin();
    if(p < B.size()) {
      R.push_back(-B[p].second - i - 1);
    } else {
      R.push_back(-1);
    }

    if(B.empty() || A[i] < -B.back().first) {
      B.push_back(make_pair(-A[i], -i));
    }
  }

  for(int i = N - 1; i >= 0; i--) {
    if(i < N - 1) printf(" ");
    printf("%d", R[i]);
  }
  printf("\n");
}