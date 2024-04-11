#include <iostream>
#include <algorithm>
void eat() {
  int n, ans = 1;
  std::cin >> n;
  int arr[n + 1][6];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 5; j++) std::cin >> arr[i][j];
  }
  for (int i = 2; i <= n; i++) {
    int z = 0;
    for (int j = 1; j <= 5; j++) z += (arr[i][j] < arr[ans][j]);
    if (z > 2) ans = i;
  }
  bool aaa = 1;
  for (int i = 1; i <= n; i++) {
    if (ans == i) continue;
    int z = 0;
    for (int j = 1; j <= 5; j++) z += (arr[i][j] < arr[ans][j]);
    aaa &= (z < 3);
  }
  std::cout << (aaa ? ans : -1) << "\n";
}
int32_t main() {
  int t = 1;
  std::cin >> t;
  while (t--) eat();
}