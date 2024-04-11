#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  if (N < 4) {
    cout << "NO" << endl;
  } else if (N % 2 == 0) {
    cout << "YES\n";
    cout << "2 * 3 = 6\n";
    cout << "6 * 4 = 24\n";
    cout << "1 * 24 = 24\n";
    for (int i = 5; i < N; i += 2) {
      cout << i + 1 << " - " << i << " = " << 1 << '\n';
      cout << "1 * 24 = 24\n";
    }
  } else {
    cout << "YES\n";
    cout << "5 * 4 = 20\n";
    cout << "20 + 3 = 23\n";
    cout << "23 + 2 = 25\n";
    cout << "25 - 1 = 24\n";
    for (int i = 6; i < N; i += 2) {
      cout << i + 1 << " - " << i << " = " << 1 << '\n';
      cout << "1 * 24 = 24\n";
    }
  }

  return 0;
}