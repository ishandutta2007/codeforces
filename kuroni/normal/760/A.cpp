#include <iostream>

using namespace std;

main()
{
    int m, d;
    cin >> m >> d;
    d = 8 - d;
    if (m == 2) m = 28;
    else if ((m == 4) | (m == 6) || (m == 9) || (m == 11)) m = 30;
    else m = 31;
    m -= d;
    cout << 2 + (m - 1) / 7;
}