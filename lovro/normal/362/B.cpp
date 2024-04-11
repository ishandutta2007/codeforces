#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define ALL(x) (x).begin(), (x).end()

int main() {
  cin.sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  vector<int> dirty(m);
  for (int &x : dirty) {
    cin >> x;
  }
  sort(ALL(dirty));

  bool ans = true;

  if (m > 0 && (dirty.front() == 1 || dirty.back() == n)) {
    ans = false;
  }

  for (int i=0; i+2<m; ++i) {
    if (dirty[i+1] == dirty[i] + 1 &&
        dirty[i+2] == dirty[i] + 2) {
      ans = false;
    }
  }
  cout << (ans ? "YES" : "NO") << '\n';
  return 0;
}