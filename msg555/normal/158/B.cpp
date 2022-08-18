#include <iostream>
#include <vector>

using namespace std;

int A[5];

int main() {
  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    int x; cin >> x;
    A[x]++;
  }
  A[1] -= min(A[1], A[3]);
  cout << A[4] + A[3] + (3 + 2 * A[2] + A[1]) / 4 << endl;
}