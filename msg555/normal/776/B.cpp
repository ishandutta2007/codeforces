#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  int N; cin >> N;

  vector<bool> isp(N + 2, true);
  for (int i = 2; i < N + 2; i++) {
    if (!isp[i]) continue;
    for (int j = 2 * i; j < N + 2; j += i) {
      isp[j] = false;
    }
  }

  cout << (N <= 2 ? 1 : 2) << "\n";
  for (int i = 0; i < N; i++) {
    if (i) cout << ' ';
    if (isp[2 + i]) {
      cout << '1';
    } else {
      cout << '2';
    }
  }
  cout << '\n';

  return 0;
}