#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  int N; cin >> N;

  int res = 0;
  for(int i = 0; i < N; i++) {
    int k, a; cin >> k >> a;
    res = max(res, k + 1);

    bool rsdue = false;
    while(a > (rsdue ? 0 : 1)) {
      k++;
      rsdue |= a % 4 != 0;
      a /= 4;
    }

    res = max(res, k);
  }
  cout << res << endl;

  return 0;
}