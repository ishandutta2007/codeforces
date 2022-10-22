#include <bits/stdc++.h>
using namespace std;

vector<int> v = {1200, 1400, 1600, 1900, 2100, 2300, 2400, 2600, 3000};

int main() {
  int n;
  cin >> n;
  for (int x : v) {
    if (n < x) {
      cout << x << endl;
      return 0;
    }
  }
}