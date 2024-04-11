#include<iostream>

using namespace std;

int main() {
  string a, b, c;
  int q;
  cin >> q;
  while (q--) {
    cin >> a >> b >> c;
    int f = 1;
    for (int i = 0; i < a.size(); ++i) {
      f &= c[i] == a[i] || c[i] == b[i];
    }
    cout << (f? "YES\n": "NO\n");
  }
}