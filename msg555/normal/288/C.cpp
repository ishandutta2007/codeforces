#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007

void solve(int* A, int* B, int x) {
  int N = B - A;

  if(x == -1) return;
  if(N <= (1 << x)) {
    solve(A, B, x - 1);
    return;
  }

  for(int i = 1 << x; i < N; i++) {
    swap(A[i - (1 << x)], A[i]);
  }
  solve(A, A + (1 << x), x - 1);
  solve(A + (1 << x), B, x - 1);
}

int A[1000010];

int main() {
  int N; cin >> N; N++;
  for(int i = 0; i < N; i++) {
    A[i] = i;
  }

  solve(A, A + N, 20);

  cout << 1ll * N * (N - 1) << endl;
  for(int i = 0; i < N; i++) {
    if(i) cout << ' ';
    cout << A[i];
  }
  cout << endl;

  return 0;
}