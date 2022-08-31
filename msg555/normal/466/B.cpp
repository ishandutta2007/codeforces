#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
  long long N, A, B;
  cin >> N >> A >> B;
  N *= 6;

  bool swp = B < A;
  if (swp) swap(A, B);

  long long rs = 0x7FFFFFFFFFFFFFFFLL, ra = -1, rb = -1;
  if (N <= A * B) {
    rs = A * B;
    ra = A;
    rb = B;
  }
  for (long long a0 = A; a0 * a0 <= N; a0++) {
    long long b0 = (N + a0 - 1) / a0;
    if (b0 < B) {
      break;
    }
    if (a0 * b0 < rs) {
      rs = a0 * b0;
      ra = a0;
      rb = b0;
    }
  }

  if (swp) swap(ra, rb);
  cout << rs << endl;
  cout << ra << ' ' << rb << endl;

  return 0;
}