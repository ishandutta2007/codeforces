#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define INF 2147483647
#define MOD 1000000007
#define MAX 100000

typedef long long ll;
typedef pair<int, int> pii;
typedef set<pii>::iterator spit;

int n, gx, gy, x, y, s;
set<pii> pts;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    cin >> n >> gx >> gy;
    while (n-- > 0) {
        cin >> x >> y;
        x -= gx;
        y -= gy;

        bool used = false;
        for (spit it = pts.begin(); it != pts.end(); ++it) {
//            cerr << it->first << ',' << it->second << ", " << x << "-" << y << endl;
            if (it->first * y == it->second * x) {
                used = true;
                break;
            }
        }
        if (!used) {
            s++;
            pts.insert(make_pair(x, y));
        }
    }
    cout << s << endl;
    return 0;
}