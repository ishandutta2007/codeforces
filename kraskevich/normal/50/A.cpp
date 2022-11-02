#include <iostream>
using namespace std;

int main() {
   int m, n, res;
   
   cin >> m >> n;
   
   res = max(m / 2 * n + m % 2 * n / 2, n / 2 * m + n % 2 * m / 2);
   
   cout << res;
   
   return 0;
}