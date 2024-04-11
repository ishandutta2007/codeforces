#include <iostream>
using namespace std;

int main()
{
    int n, tmp, l = 0, r = 0, i;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> tmp;
        if (tmp != i) break;
    }
    if (i <= n) {
          l = i;
          r = tmp;
          for (i = r - 1; i >= l; i--) {
              cin >> tmp;
              if (tmp != i) break;
          }
          if (i == l - 1) {
                for (i = r + 1; i <= n; i++) {
                    cin >> tmp;
                    if (tmp != i) break;
                }
                if (i <= n) l = r = 0;
          } else l = r = 0;
    }
    cout << l << " " << r << endl;
    return 0;
}