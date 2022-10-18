#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;


int main() {
  cin.sync_with_stdio(0);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i=0; i<n; ++i) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  arr.back() = arr.back() > 1 ? 1 : 2;
  sort(arr.begin(), arr.end());
  for (int i=0; i<n; ++i) {
    if (i > 0) cout << ' ';
    cout << arr[i];
  }
  cout << endl;

  return 0;
}