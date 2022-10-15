#include <iostream>
#define int long long
#define double long double
#define ff first
#define ss second
void eat() {
  // do stuff here
  int n;
  std::cin >> n;
  int arr[n + 1], s = 0;
  for (int i = 1; i <= n; i++) std::cin >> arr[i];
  while (n && !arr[n]) n--;
  if (!n) {
    std::cout << "Yes\n";
    return;
  }
  for (int i = 1; i <= n; i++) {
    s += arr[i];
    if (i < n && s <= 0) {
      std::cout << "No\n";
      return;
    }
  }
  std::cout << (!s ? "Yes\n" : "No\n");
}
int32_t main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int t = 1;
  std::cin >> t;
  while (t--) eat();
  return 0;
}