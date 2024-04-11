#include <iostream>
void eat() {
  int n;
  std::cin >> n;
  bool aaa = 0;
  int arr[n + 1];
  for (int i = 1; i <= n; i++) std::cin >> arr[i];
  for (int i = 1; i < (1 << n); i++) {
    for (int j = 0; j < (1 << n); j++) {
      int zz = 0;
      for (int k = 0; k < n; k++) {
        int pp = arr[k + 1] * ((i >> k) & 1);
        if ((j >> k) & 1) zz += pp;
        else zz -= pp;
      }
      if (!zz) aaa = 1;
    }
  }
  std::cout << (aaa ? "YES\n" : "NO\n");
}
int32_t main() {
  int t = 1;
  std::cin >> t;
  while (t--) eat();
}