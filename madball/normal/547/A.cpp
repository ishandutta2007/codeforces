#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
typedef long long ll;

int main() {
    /*ifstream in("input.txt");
    ofstream out("output.txt");*/

    ll m, h1, a1, x1, y1, h2, a2, x2, y2, res = 0, i;
    cin >> m >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;

    for (i = 0; (h1 != a1) && (i <= m); i++, res++) {
        h1 = ((h1 * x1) + y1) % m;
        h2 = ((h2 * x2) + y2) % m;

    }

    if (h1 != a1) {
        cout << -1;
        return 0;
    }

    if (h2 == a2) {
        cout << res;
        return 0;
    }

    ll loop = 1;
    for (; loop <= m; loop++) {
        h1 = ((h1 * x1) + y1) % m;
        if (h1 == a1)
            break;
    }

    if (h1 != a1) {
        cout << -1;
        return 0;
    }

    ll x3 = 1, y3 = 0;
    for (i = 0; i < loop; i++) {
        x3 = (x3 * x2) % m;
        y3 = (y3 * x2 + y2) % m;
    }


    for (i = 0; (h2 != a2) && (i <= m); i++, res += loop)
        h2 = ((h2 * x3) + y3) % m;

    if (h2 != a2) {
        cout << -1;
        return 0;
    }

    cout << res;
    return 0;
}