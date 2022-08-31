#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> R;
  for (int i = 2; i <= N; i++) {
    bool isp = true;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        isp = false;
      }
    }
    if (!isp) continue;
    for (int k = i; k <= N; k *= i) {
      R.push_back(k);
    }
  }

  cout << R.size() << endl;
  for (int i = 0; i < R.size(); i++) {
    if (i) cout << ' ';
    cout << R[i];
  }
  cout << endl;

  return 0;
}