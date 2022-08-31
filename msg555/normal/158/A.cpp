#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K; cin >> N >> K;

  int cnt = 0;
  int lst = -1;
  for(int i = 0; i < N; i++) {
    int x; cin >> x;
    if(x > 0) {
      if(i < K) lst = x;
      cnt += x == lst;
    }
  }
  cout << cnt << endl;
}