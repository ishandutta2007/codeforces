#include <iostream>
#include <cmath>
using namespace std;

int main() {
   int n, x, y;
   
   cin >> n >> x >> y;
   
   int t = ((x == n / 2  || x == n / 2 + 1) ? 1 : 0), t1 = ((y == n / 2 || y == n / 2 + 1) ? 1 : 0);
   
   cout << (t1 + t == 2 ? "NO" : "YES");
   
   cin >> n;
   
   return 0;
}