#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
  long long x, y, m;
  cin >> x >> y >> m;

  if(x >= m || y >= m) {
    cout << "0" << endl;
  } else if(x <= 0 && y <= 0) {
    cout << "-1" << endl;
  } else {
    if(y < x) swap(x, y);

    long long t = 0;
    if(x < 0) {
      t = (-x + y - 1) / y;
      x += t * y;
    }

    for(; x < m && y < m; t++) {
      if(y < x) swap(x, y);
      x += y;
    }

    cout << t << endl;
  }

  return 0;
}