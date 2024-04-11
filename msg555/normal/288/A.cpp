#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K; cin >> N >> K;
  if(N < K) {
    cout << -1 << endl;
    return 0;
  }
  if(K == 1) {
    cout << (N == 1 ? "a" : "-1") << endl;
    return 0;
  }
  int i;
  for(i = 0; i < N - (K - 2); i++) {
    cout << (i % 2 ? 'b' : 'a');
  }
  for(char ch = 'c'; i < N; i++, ch++) {
    cout << ch;
  }
  cout << endl;
  return 0;
}