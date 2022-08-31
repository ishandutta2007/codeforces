#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  string A, B;
  cin >> A >> B;
  int N; cin >> N;

  for (int i = 0; i < N; i++) {
    cout << A << ' ' << B << "\n";

    string K, C;
    cin >> K >> C;
    (A == K ? A : B) = C;
  }
  cout << A << ' ' << B << "\n";

  return 0;
}