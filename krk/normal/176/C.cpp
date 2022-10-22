#include <iostream>
#include <algorithm>
using namespace std;

int n, m, x1, y1, x2, y2;
int dx, dy;

int main()
{
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    dx = abs(x1 - x2), dy = abs(y1 - y2);
    if (dx >= 5 || dy >= 5) cout << "Second\n";
    else if (max(dx, dy) <= 3) cout << "First\n";
    else if (min(dx, dy) <= 2) cout << "First\n";
    else cout << "Second\n";
    return 0;
}