#include <iostream>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
      cin >> n;
      cout << n * 3 << '\n';
      for (int i = 0; i < n; i += 2) {
        int a, b;
        cin >> a >> b;
        for (int type: {1, 2, 1, 1, 2, 1}) {
          cout << type << ' ' << i + 1 << ' ' << i + 2 << '\n';
        }
      }
    }
    return 0;
}