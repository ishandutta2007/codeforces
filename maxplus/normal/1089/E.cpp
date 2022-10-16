#include <iostream>

using namespace std;

constexpr int N = 8;

bool vis[N][N];

int main() {
  int n; cin >> n; ++n;
  int r = 0, c = 0;
  auto jump = [&]() {
    cout << char('a' + c) << r + 1 << ' ';
    vis[r][c] = 1;
    --n;
  };
  jump();
  while ((n > 4 || c == 7) && (r != 5 || c)) {
    if (r % 2? !c: c == 7) {
      ++r;
    } else {
      c += 1 - r % 2 * 2;
    }
    jump();
  }
  if (r != 5 || c) {
    while (n > 1) {
      r = 7;
      jump();
      c = 0;
      while (vis[r][c]) ++c;
    }
  } else {
    if ((n + 1) % 4 <= 1 && n != 16) {
      r = 6;
    } else {
      r = 7;
    }
    jump();
    while (n > 1) {
      r ^= 1;
      jump();
      if (n > 1) {
        ++c;
        jump();
      }
    }
  }
  r = c = 7;
  jump();
}