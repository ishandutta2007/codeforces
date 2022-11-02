#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    long long t1, t2, t0, x1, x2;
    cin >> t1 >> t2 >> x1 >> x2 >> t0;
    if(t1 > t2)
          swap(t1, t2);
    if(t1 == t2) 
          cout << x1 << " " << x2;
    else {
         double res = -1;
         long long r1, r2;
         for(long long i = 0; i <= x1; ++i) {
                  long long l = (i ? 0 : 1), r = x2;
                  double cur;
                  if(i) {
                      while(l < r - 1) {
                              long long m = (l + r) / 2;
                              if(double(t1 * i + t2 * m) / double(m + i) < t0)
                                           l = m;
                              else
                                  r = m;
                      }
                      cur = double(t1 * i + t2 * l) / double(l + i);
                      if(cur <  t0)
                             ++l;
                  }
                  else
                      l = x2;
                  cur = double(t1 * i + t2 * l) / double(l + i);
                  if(cur >= t0 && (res < 0 || res >= cur))
                         if(cur < res || res < 0) {
                                res = cur;
                                r1 = i;
                                r2 = l;
                         } 
                         else
                             if(i + l > r1 + r2)
                                  r1 = i, r2 = l;
         }
         cout << r1 << " " << r2 << endl;
    }
    cin >> x1;
    return 0;
}