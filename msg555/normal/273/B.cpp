#include <iostream>
#include <algorithm>
#include <cassert>
#include <map>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main() {
  int N; cin >> N;

  vector<pair<int, int> > A(2 * N);
  for(int i = 0; i < N; i++) {
    cin >> A[i].first;
    A[i].second = i;
  }
  for(int i = 0; i < N; i++) {
    cin >> A[N + i].first;
    A[N + i].second = i;
  }
  sort(A.begin(), A.end());

  int M; cin >> M;
  int r = 1;
  for(int i = 0; i < 2 * N; ) {
    int j;
    for(j = 1; i + j < 2 * N && A[i + j].first == A[i].first; j++);

    int twos = 0;
    for(int k = 1; k < j; k++) {
      twos += A[i + k] == A[i + k - 1];
    }
    for(int k = 2; k <= j; k++) {
      int x = k;
      for(; twos > 0 && x % 2 == 0; x /= 2) twos--;
      r = (1ll * r * x) % M;
    }

    i += j;
  }

  cout << r << endl;
}