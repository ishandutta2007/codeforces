#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  cin.sync_with_stdio(0);

  int S, A, B, C;
  cin >> S >> A >> B >> C;

  if (A + B + C == 0) {
    printf("0 0 0\n");
    return 0;
  }

  double x = double(A) / (A+B+C) * S;
  double y = double(B) / (A+B+C) * S;
  double z = double(C) / (A+B+C) * S;
  printf("%.10f %.10f %.10f\n", x, y, z);
  return 0;
}