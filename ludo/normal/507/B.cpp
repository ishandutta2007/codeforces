#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <utility>

using namespace std;

typedef long long ll;

int main()
{
 #ifdef LOCAL
    freopen("input.txt", "r", stdin);
 #endif // LOCAL

    ll r, x1, y1, x2, y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;

    // return ceil(sqrt(dist) / r)
    ll distSq = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

    // cerr << r << " - " << x1 << " - " << y1 << " - " << x2 << " - " << y2 << endl;
    // cerr << distSq << endl;

    cout << ceil(sqrt(distSq) / ((double) 2 * r));
    return 0;
}