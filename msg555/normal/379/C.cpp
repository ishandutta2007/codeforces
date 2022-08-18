#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
  int N; cin >> N;
  vector<pair<int, int> > A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i].first;
    A[i].second = i;
  }
  sort(A.begin(), A.end());

  int nxt = 0;
  vector<int> B(N, -1);
  for(int i = 0; i < A.size(); i++) {
    B[A[i].second] = max(nxt, A[i].first);
    nxt = B[A[i].second] + 1;
  }

  for(int i = 0; i < N; i++) {
    if(i) cout << ' ';
    cout << B[i];
  }
  cout << endl;
  return 0;
}