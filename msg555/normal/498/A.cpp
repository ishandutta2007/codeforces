#include <iostream>
#include <vector>

using namespace std;

int sgn(long long x) {
  if (x < 0) return -1;
  if (x > 0) return 1;
  return 0;
}

int main() {
  long long x1, y1;
  long long x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int result = 0;
  int N; cin >> N;
  for (int i = 0; i < N; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    if (sgn(a * x1 + b * y1 + c) != sgn(a * x2 + b * y2 + c)) {
      result++;
    }
  }
  cout << result << endl;

  return 0;
}