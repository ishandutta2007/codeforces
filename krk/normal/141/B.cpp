#include <iostream>
using namespace std;

int a, x, y;

int main()
{
    cin >> a >> x >> y;
    if (y % a == 0) cout << "-1\n";
    else {
         int lvl = y / a;
         int sum = 0, cur = 1, nxt = 1;
         for (int i = 1; i <= lvl; i++) {
             sum += cur;
             cur = nxt;
             nxt = 3 - nxt;
         }
         if (cur == 1) if (-a < 2 * x && 2 * x < a) cout << sum + 1 << endl;
                       else cout << "-1\n";
         else if (cur == 2) if (-a < x && x < 0) cout << sum + 1 << endl;
                         else if (x > 0 && x < a) cout << sum + 2 << endl;
                         else cout << "-1\n";
    }
    return 0;
}