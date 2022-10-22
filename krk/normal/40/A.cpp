#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x, y, rs, r;
    cin >> x >> y;
    rs = x*x + y*y;
    r = int(sqrt(rs));
    if (r * r == rs) cout << "black\n";
    else if (x > 0 == y > 0)
            if (r % 2 == 0) cout << "black\n";
            else cout << "white\n";
         else if (r % 2 == 0) cout << "white\n";
              else cout << "black\n";
    return 0;
}