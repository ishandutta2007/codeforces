#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, h, a, b, k;
  cin >> n >> h >> a >> b >> k;
  for (int i=0; i<k; ++i) {
    int ta, fa, tb, fb;
    cin >> ta >> fa >> tb >> fb;
    int ans = 0;
    if (ta == tb) {
      ans = abs(fb-fa);
    } else {
      if (fa > b) {
        ans += fa-b;
        fa = b;
      } else if (fa < a) {
        ans += a-fa;
        fa = a;
      }
      
      if (fb > b) {
        ans += fb-b;
        fb = b;
      } else if (fb < a) {
        ans += a-fb;
        fb = a;
      }
      
      ans += abs(fa-fb)+abs(ta-tb);
    }
    cout << ans << endl;
  }
}