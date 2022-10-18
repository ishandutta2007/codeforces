#define NDEBUG
#include <iostream>
#include <vector>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (int& x : arr) {
    cin >> x;
  }
  const int maxk = n-1;

  vector<int> deltas(maxk+2, 0);
  for (int i=1; i<n; ++i) {
    int k1 = 1, k2, p;
    while (k1 <= maxk) {
      p = (i - 1) / k1;
      k2 = p != 0 ? (i - 1) / p : maxk;
      if (arr[i] < arr[p]) {
        ++deltas[k1];
        --deltas[k2+1];
      }
      k1 = k2 + 1;
    }
  }

  int ans = 0;
  for (int k=1; k<=maxk; ++k) {
    ans += deltas[k];
    cout << ans << " \n"[k == maxk];
  }
}