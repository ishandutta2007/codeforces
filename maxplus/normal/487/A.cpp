#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int h1, a1, d1, h2, a2, d2, h, a, d, hg = 1, ag, dg, hitsAm, sum = 1000000000;
    cin >> h1 >> a1 >> d1 >> h2 >> a2 >> d2 >> h >> a >> d;
    for (ag = max(0, -a1 + d2 + 1); (hg != 0 || dg != 1) && hitsAm != 1; ++ag)
    {
        hitsAm = ceil((long double)h2 / (a1 + ag - d2));
        hg = 1;
        for (dg = 0; hg != 0; ++dg)
        {
            hg = max(hitsAm * (a2 - d1 - dg) + 1 - h1, 0);
            sum = min(sum, ag * a + dg * d + hg * h);
        }
    }
    cout << sum;
    return 0;
}