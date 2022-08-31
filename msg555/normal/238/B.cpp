#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <cstring>
#include <set>
#include <queue>

using namespace std;

pair<int, int> A[100010];
int B[100010];

int main() {
  int N, H; cin >> N >> H;
  for(int i = 0; i < N; i++) {
    cin >> A[i].first;
    A[i].second = i;
  }
  sort(A, A + N);

  int r1 = A[N - 1].first + A[N - 2].first - A[0].first - A[1].first;
  int res = r1;
  if(N > 2) {
    res = min(res,
        max(A[N - 1].first + A[N - 2].first, A[N - 1].first + A[0].first + H) -
        min(A[0].first + A[1].first + H, A[1].first + A[2].first));
  }

  cout << res << endl;
  for(int i = 0; i < N; i++) {
    if(i) cout << ' ';
    cout << (res < r1 && i == A[0].second == 0 ? 2 : 1);
  }
  cout << endl;
}