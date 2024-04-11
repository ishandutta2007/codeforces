#include <iostream>

using namespace std;

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int sx, sy;
  cin >> sx >> sy;

  int dx = abs(x1 - x2);
  int dy = abs(y1 - y2);
  if (dx % sx != 0 || dy % sy != 0 || (dx / sx + dy / sy) % 2 != 0) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }

  return 0;
}