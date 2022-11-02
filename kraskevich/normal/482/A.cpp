#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  int low = 1;
  int high = n;
  int last = high + 1;
  for (int i = 0; i < k; i++) {
    if (i % 2 == 0) {
      cout << low << " ";
      last = low;
      low++;
    }
    else {
      cout << high << " ";
      last = high;
      high--;
    }
  }
  if (k % 2 == 1)
    for (int i = 0; i < n - k; i++) {
      last++;
      cout << last << " ";
      //last++;
    }
  else 
    for (int i = 0; i < n - k; i++) {
      last--;
      cout << last << " ";
      //last--;
    }
  return 0;
}