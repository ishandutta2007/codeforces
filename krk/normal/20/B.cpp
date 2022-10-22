#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

ll a, b, c, d;

int main()
{
    cin >> a >> b >> c;
    if (a == 0)
       if (b != 0) {
             cout << "1\n";
             cout << fixed << setprecision(10) << (double) -c / b << endl;
       } else if (c == 0) cout << "-1\n";
         else cout << "0\n";
    else {
         d = b*b - 4LL*a*c;
         if (d < 0) cout << "0\n";
         else if (d == 0) {
              cout << "1\n";
              cout << fixed << setprecision(10) << (double) -b / (2LL * a) << endl;
         } else {
              cout << "2\n";
              double x1 = (double) (-b - sqrt(double(d))) / (2.0 * a);
              double x2 = (double) (-b + sqrt(double(d))) / (2.0 * a);
              cout << fixed << setprecision(10) << min(x1, x2) << endl;
              cout << fixed << setprecision(10) << max(x1, x2) << endl;
         }
    }
    return 0;
}