#include <iostream>
#include <vector>

using namespace std;

long long A[100010];

int main() {
  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int M; cin >> M;

  long long h0 = 0;
  for(int i = 0; i < M; i++) {
    long long w, h; cin >> w >> h;
    h0 = max(h0, A[w - 1]) + h;
    cout << h0 - h << endl;
  }
}