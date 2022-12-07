#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef long long int64;

int64 sqr(int64 n){
      return n * n;
}

int64 find(int64 a, int64 b)
{
      int64 lo = 0, hi = 1;
      while (hi * hi * a < b) hi *= 2;
      while (lo + 1 < hi)
      {
            int64 mid = (lo + hi) >> 1;
            if (mid * mid * a >= b) hi = mid;
            else lo = mid;
      }
      return hi;
}


int main()
{
    int64 n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    int64 dist = sqr(x1 - x2) + sqr(y1 - y2);
    int64 part = sqr(2 * n);

    if (dist == 0) cout << 0 << endl;
    else cout << find( part, dist ) << endl;

    //system("pause");
}