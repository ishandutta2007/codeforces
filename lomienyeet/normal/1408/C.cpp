#include <iostream>
#include <iomanip>
#include <algorithm>
void eat() {
  int n, l;
  std::cin >> n >> l;
  int arr[n + 1];
  for (int i = 1; i <= n; i++) std::cin >> arr[i];
  std::pair<double, double> tt = {0, 0}, pos = {0, l};
  std::pair<int, int> sp = {1, 1}, flag = {1, n};
  for (int i = 1; i <= n; i++) {
    if (tt.first + (arr[flag.first] - pos.first) / sp.first < tt.second + (pos.second - arr[flag.second]) / sp.second) {
      tt.first += (arr[flag.first] - pos.first) / sp.first;
      pos.first = arr[flag.first];
      flag.first++;
      sp.first++;
    }
    else {
      tt.second += (pos.second - arr[flag.second]) / sp.second;
      pos.second = arr[flag.second];
      flag.second--;
      sp.second++;
    }
  }
  if (tt.first > tt.second) pos.second -= (tt.first - tt.second) * sp.second;
  else pos.first += (tt.second - tt.first) * sp.first;
  std::cout << std::fixed << std::setprecision(15) << std::max(tt.first, tt.second) + (pos.second - pos.first) / (sp.first + sp.second) << "\n";
}
int32_t main() {
  int t = 1;
  std::cin >> t;
  while (t--) eat();
}