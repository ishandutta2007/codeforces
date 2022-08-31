#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int A[100010];

int main() {
  int N, K;
  cin >> N >> K;
  for(int i = 0; i < N; i++) cin >> A[i];
  sort(A, A + N);

  vector<int> B;
  for(int i = 0; i < N; i++) {
    if(A[i] % K == 0 && binary_search(B.begin(), B.end(), A[i] / K)) {
      continue;
    }
    B.push_back(A[i]);
  }
  cout << B.size() << endl;

  return 0;
}