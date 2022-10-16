#include <iostream>

using namespace std;

int main()
{
  cin.tie(0), ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    cin.ignore();
    int a = 1, b = 1;
    while (cin.peek() != '\n') {
      swap(a = a * 10 + cin.get() - '9', b);
    }
    cout << a * b - 2 << '\n';
  }
  return 0;
}