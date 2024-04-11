#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <utility>

using namespace std;

map<string,string> M;

typedef long long int64;

int64 a1, b1, c1;

bool check(int64 num, int64 den, int64 b, int64 e)
{
    if (den == 0) return false;
    if (den < 0) den *= -1, num *= -1;
    return b * den <= num && num <= e * den;
}

int main()
{
    int64 x1, y1; cin >> x1 >> y1;
    int64 x2, y2; cin >> x2 >> y2;

    a1 = y1 - y2;
    b1 = x2 - x1;
    c1 = y2 * x1 - y1 * x2;

    int64 n; cin >> n;
    int64 ans = 0;

    if (y1 > y2) swap(y1, y2);
    if (x1 > x2) swap(x1, x2);

    for (int64 i = 0; i < n; ++i)
    {
        int64 a2, b2, c2; cin >> a2 >> b2 >> c2;
        int64 den = a2 * b1 - a1 * b2;
        if ( check( a1 * c2 - a2 * c1, den, y1, y2) &&
             check( b1 * c2 - b2 * c1, -den, x1, x2)) ans++;
    }

    cout << ans << endl;

}