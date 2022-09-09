#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n, a[3000], count = 0;
  string s;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    int curr = a[i], index = -1;
    for (int j = i + 1; j < n; j++) {
      if (a[j] < curr) {
        curr = a[j];
        index = j;
      }
    }
    if (curr < a[i]) {
      count++;
      s += to_string((long long)i);
      s += " ";
      s += to_string((long long)index);
      s += "\n";
      swap(a[i], a[index]);
    }
  }
  cout << count << '\n' << s;
  return 0;
}