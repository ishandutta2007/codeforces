#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main() {
  int N; cin >> N;

  vector<int> A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());

  int j = 1;
  int result = 0;
  for(int i = 0; i < N; i++) {
    while(j < N && A[i] * 2 > A[j]) j++;
    if(j < N) {
      result = min(result + 1, max(N - i - 1, result));
      j++;
    }
  }

  cout << N - result << endl;
  return 0;
}