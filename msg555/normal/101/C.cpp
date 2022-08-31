#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int ddx[] = {1, 0, -1, 0};
int ddy[] = {0, -1, 0, 1};

int main() {
  int ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> cx >> cy;

  bool ok = false;
  for(int i = 0; !ok && i < 4; i++) {
    long long dx = bx - (ddx[i] * ax + ddy[i] * ay);
    long long dy = by - (ddx[(i+3) % 4] * ax + ddy[(i+3)%4] * ay);

    if(cx == 0 && cy == 0) {
      ok = dx == 0 && dy == 0;
      continue;
    }

    long long det = 1ll * cx * cx + 1ll * cy * cy;
    ok = (dx * cx + dy * cy) % det == 0 &&
         (dx * cy - dy * cx) % det == 0;
  }
  cout << (ok ? "YES" : "NO") << endl;
}