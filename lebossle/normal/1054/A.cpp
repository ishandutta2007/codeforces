#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  int st = abs(y-x)*t1;
  int el = abs(z-x)*t2 + abs(y-x)*t2 + 3*t3;
  if (el > st)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}