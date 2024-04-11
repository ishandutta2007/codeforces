#include <iostream>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, W, H, x, y, xx, yy, ww, hh;
  cin >> t;
  while (t--) {
    cin >> W >> H >> x >> y >> xx >> yy >> ww >> hh;
    int ans = 1e9;
    if (xx - x + ww <= W) {
      ans = min(ans, min(ww - (W - xx), ww - x));
    }
    if (yy - y + hh <= H) {
      ans = min(ans, min(hh - (H - yy), hh - y));
    }
    cout << (ans == 1e9? -1: max(ans, 0)) << '\n';
  }
  return 0;
}