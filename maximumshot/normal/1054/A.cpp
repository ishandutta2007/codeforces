#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int x, y, z, t1, t2, t3;

    cin >> x >> y >> z >> t1 >> t2 >> t3;

    int r1 = abs(x - y) * t1;
    int r2 = abs(z - x) * t2 + t3 + t3 + abs(x - y) * t2 + t3;

    cout << (r1 >= r2 ? "YES" : "NO") << "\n";

    return 0;
}