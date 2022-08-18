#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int result = A[0];
  for(int i = 0; i < N; i++) {
    for(int j = i + 1; j <= N; j++) {
      int sm = 0;
      multiset<int> ist;
      multiset<int> ost;
      for(int k = 0; k < N; k++) {
        if(i <= k && k < j) {
          ist.insert(A[k]);
          sm += A[k];
        } else {
          ost.insert(A[k]);
        }
      }

      result = max(sm, result);
      for(int k = 0; k < K && !ost.empty(); k++) {
        int iv = *ist.begin();
        int ov = *--ost.end();
        if(iv >= ov) break;
        sm += ov - iv;
        ist.insert(ov);
        ost.insert(iv);
        ist.erase(ist.find(iv));
        ost.erase(ost.find(ov));
        result = max(sm, result);
      }
    }
  }

  cout << result << endl;
  return 0;
}