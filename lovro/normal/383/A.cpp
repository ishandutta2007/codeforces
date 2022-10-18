#include <iostream>
using namespace std;

#define repeat(n) for (int repc = (n); repc > 0; --repc)
typedef long long int64;

int main() {
  cin.sync_with_stdio(0);

  int N;
  cin >> N;

  int64 right = 0, ans = 0;
  repeat (N) {
    int dir;
    cin >> dir;
    if (dir) {
      ++right;
    } else {
      ans += right;
    }
  }
  cout << ans << '\n';

  return 0;
}