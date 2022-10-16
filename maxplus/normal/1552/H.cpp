#include <iostream>

using namespace std;

constexpr int N = 200;

int query(int d) {
  cout << "? " << N / d * N << '\n';
  for (int i = d; i <= N; i += d)
  for (int j = 1; j <= N; ++j) {
    cout << i << ' ' << j << ' ';
  }
  cout << '\n';
  int res;
  cin >> res;
  return res;
}

int main()
{
  int l = 0, r = 8, mid, fp, s = query(1), fr = 0, fl = s;
  while (r - l > 1) {
    mid = (r + l) / 2;
    fp = query(1 << mid);
    if ((fp << mid) == s) {
      l = mid;
      fl = fp;
    } else {
      r = mid;
      fr = fp;
    }
  }
  int dj = abs(2 * fr - fl), di = s / dj;
  cout << "! " << (di + dj - 2) * 2 << '\n';
  return 0;
}