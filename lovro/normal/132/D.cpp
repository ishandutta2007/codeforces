#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;


int main() {
  cin.sync_with_stdio(0);

  string digits;
  cin >> digits;

  const int n = digits.size();
  vector<int> out(n+1, 0);

  int len = 0;
  for (int i=0; i<=n || len > 0; ++i) {
    int val = i < n ? digits[n-i-1] : '0';
    if (val == '1') {
      ++len;
    } else {
      if (len == 1) {
        ++out[i-len];
        len = 0;
      } else if (len > 1) {
        --out[i-len];
        len = 1;
      }
    }
  }

  int result = 0;
  for (int i=0; i<=n; ++i) {
    result += abs(out[i]);
  }

  printf("%d\n", result);
  for (int i=n; i>=0; --i) {
    if (out[i] != 0) {
      printf("%c2^%d\n", out[i] > 0 ? '+' : '-', i);
    }
  }

  return 0;
}