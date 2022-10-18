#define NDEBUG
#include <functional>
#include <iostream>
using namespace std;

typedef long long int64;

int main() {
  ios_base::sync_with_stdio(0); // caret here

  int n;
  cin >> n;
  bool ok = true;
  int64 ref;
  for (int i=0; i<n; ++i) {
    int64 x;
    cin >> x;
    while (x % 2 == 0) {
      x /= 2;
    }
    while (x % 3 == 0) {
      x /= 3;
    }
    if (i == 0) {
      ref = x;
    } else {
      ok &= ref == x;
    }
  }
  cout << (ok ? "Yes\n" : "No\n");
}