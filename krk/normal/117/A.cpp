#include <iostream>
using namespace std;

int n, m;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n >> m;
    while (n--) {
          int s, f, t; cin >> s >> f >> t;
          if (s == f) cout << t << endl;
          else if (s < f) {
               int tim = t / (2 * m - 2) * (2 * m - 2);
               if (tim + s - 1 < t) tim += 2 * m - 2;
               tim += f - 1;
               cout << tim << endl;
          } else {
                 int tim = t / (2 * m - 2) * (2 * m - 2);
                 tim += m - 1;
                 if (tim + m - s < t) tim += 2 * m - 2;
                 tim += m - f;
                 cout << tim << endl;
          }
    }
    return 0;
}