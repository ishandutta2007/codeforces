#include <iostream>

using namespace std;

int main()
{
    int t, a, b;
    cin >> t;
    while (t--) {
      cin >> a >> b;
      if ((a + b) % 2 == 1) {
        cout << "-1\n";
      } else if (!a && !b) {
        cout << "0\n";
      } else if (a == b) {
        cout << "1\n";
      } else {
        cout << "2\n";
      }
    }
    return 0;
}