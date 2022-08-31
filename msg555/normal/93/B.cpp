#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
  double w;
  int n, m; cin >> m >> w >> n;
  double cup = w * m / n;
  cout << fixed << setprecision(9);
  if(n <= m) {
    double cur = 0;
    cout << "YES" << endl;
    for(int i = 0; i < m; i++) {
      double hv = w;
      while(hv > 1e-9) {
        double amt = min(hv, cup - cur);
        if(cur != 0) cout << ' ';
        cout << i + 1 << ' ' << amt; 
        cur += amt;
        hv -= amt;

        if(cur + 1e-9 >= cup) {
          cur = 0;
          cout << endl;
        }
      }
    }
  } else {
    if(m % (n - m) == 0) {
      cout << "YES" << endl;
      double slp = w - cup;
      for(int i = 0; i < m; i++) {
        cout << i + 1 << ' ' << cup << endl;
      }
      for(int i = 0; i < m; ) {
        for(int j = 0; j < m / (n - m); j++, i++) {
          if(j) cout << ' ';
          cout << i + 1 << ' ' << slp;
        }
        cout << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  }
}