#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>

using namespace std;

#define MAXN 100010

int N;
string A[MAXN][2];

int main() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i][0] >> A[i][1];
  }
  string L;
  for(int ii = 0; ii < N; ii++) {
    int i; cin >> i; i--;
    if (A[i][0] <= L && A[i][1] <= L) {
      cout << "NO" << endl;
      return 0;
    } else if (A[i][0] <= L || A[i][1] <= L) {
      L = max(A[i][0], A[i][1]);
    } else {
      L = min(A[i][0], A[i][1]);
    }
  }
  cout << "YES" << endl;
  return 0;
}