#include <iostream>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

ll mx, my, ax[Maxn], ay[Maxn], n, j, resx, resy;

int main()
{
    cin >> n >> j;
    cin >> mx >> my;
    for (int i = 0; i < n; i++) cin >> ax[i] >> ay[i];
    j %= 2 * n;
    bool plius = true;
    while (j) {
          if (plius) {
                     resx += 2 * ax[(j-1)%n];
                     resy += 2 * ay[(j-1)%n];
          } else {
                 resx -= 2 * ax[(j-1)%n];
                 resy -= 2 * ay[(j-1)%n];
          }
          plius = !plius;
          j--;
    }
    if (plius) {
               resx += mx;
               resy += my;
    } else {
           resx -= mx;
           resy -= my;
    }
    cout << resx << " " << resy << endl;
    return 0;
}