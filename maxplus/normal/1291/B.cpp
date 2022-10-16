#include<iostream>

using namespace std;

int main() {
  int q;
  cin >> q;
  while (q--) {
    int n, a, ml = 0, mr = 0;
    cin >> n;
    ml = n;
    for (int i = 0; i < n; ++i) {
      cin >> a;
      if (a < i) {
        ml = min(ml, i - 1);
      }
      if (a < n - i - 1) {
        mr = max(mr, i + 1);
      }
    }
    cout << ((mr <= ml)? "Yes": "No") << '\n';
  }
}