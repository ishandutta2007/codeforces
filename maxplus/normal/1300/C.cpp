#include <iostream>
#include <algorithm>

using namespace std;

int a[100000];
int b[32];
pair<int, int> c[100000];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    for (int td = 0; td < 32; ++td) {
      if (a[i] & (1 << td)) {
        ++b[td];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    int rd = -1;
    for (int td = 0; td < 32; ++td) {
      if ((a[i] & (1 << td)) && b[td] == 1) {
        rd = td;
      }
    }
    c[i] = {-rd, a[i]};
  }
  sort(c, c + n);
  for (int i = 0; i < n; ++i) {
    cout << c[i].second << '\n';
  }
}