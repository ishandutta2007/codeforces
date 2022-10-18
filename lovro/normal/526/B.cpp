#define NDEBUG
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

#define ALL(x) (x).begin(), (x).end()

int main() {
  ios_base::sync_with_stdio(0);

  int depth;
  cin >> depth;
  int n = (1 << (depth+1)) - 1;
  vector<int> pre(n+1, 0), add(n+1, 0);
  for (int i=2; i<=n; ++i) {
    cin >> pre[i];
  }

  vector<int> way(n+1, 0);
  for (int i=2; i<=n; ++i) {
    way[i] = way[i/2] + pre[i];
  }
  int target = *max_element(ALL(way));
  for (int i=n/2+1; i<=n; ++i) {
    add[i] = target - way[i];
  }
  for (int i=n/2; i>=2; --i) {
    add[i] = min(add[2*i], add[2*i+1]);
    add[2*i] -= add[i];
    add[2*i+1] -= add[i];
  }
  cout << accumulate(ALL(add), 0) << '\n';
}