#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
  long long A, B, N;
  cin >> A >> B >> N;

  for (int i = 0; i < N; i++) {
    long long L, T, M;
    cin >> L >> T >> M;

    if (A + (L - 1) * B > T) {
      cout << "-1\n";
    } else {
      long long lo = L;
      long long hi = T;
      long long base = T * M + (L - 1) * A + (L - 1) * (L - 2) * B / 2;
      while (lo < hi) {
        long long md = (lo + hi + 1) / 2;
        if (A + (md - 1) * B > T ||
            md * A + md * (md - 1) * B / 2 > base) {
          hi = md - 1;
        } else {
          lo = md;
        }
      }
      cout << lo << '\n';
    }
  }

  return 0;
}