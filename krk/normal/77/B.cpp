#include <iostream>
#include <iomanip>
using namespace std;

int t, a, b;

int main()
{
    cin >> t;
    while (t--) {
          cin >> a >> b;
          if (a == 0 && b == 0) cout << "1.0000000000\n";
          else if (4 * b <= a) cout << fixed << setprecision(10) 
                                    << 1 - double(b) / double(a) + 1e-11 << endl;
          else cout << fixed << setprecision(10) << 0.5 + double(a) / double(16 * b) + 1e-11 << endl;
    }
    return 0;
}