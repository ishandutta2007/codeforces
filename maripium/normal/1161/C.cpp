#include <bits/stdc++.h>

using namespace std;

int n;
int cnt[55];

int main() {
   cin >> n;
   for (int i = 1; i <= n; ++i) {
      int x; cin >> x;
      cnt[x]++;
   }
   for (int i = 1; i <= 50; ++i) if (cnt[i]) {
      puts(cnt[i] > n / 2 ? "Bob" : "Alice"); 
      return 0;
   }
}