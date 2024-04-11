#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;

  int r = 0;
  for (int i = 0; i < N; i++) {
    int ai; cin >> ai;
    if (ai == 1) {
      r ^= 1;
    } else if (ai == 2) {
      r ^= K % 2 ? 0 : 2;
    } else if (ai == 3) {
      r ^= K % 2;
    } else {
      int b = __builtin_ctz(ai);
      if (b == 0) {
        r ^= 0;
      } else if (K % 2) {
        if ((ai >> b) == 3) {
          b++;
        }
        r ^= 2 - b % 2;
      } else {
        r ^= 1;
      }
    }
  }
  cout << (r ? "Kevin" : "Nicky") << endl;

  return 0;
}