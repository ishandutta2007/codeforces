#include <iostream>
using namespace std;

typedef long long ll;

ll xa, ya, xb, yb, xc, yc;

bool canGet(ll xd, ll yd)
{
    if (xc == 0 && yc == 0) return xd == 0 && yd == 0;
    if (xc && yc) {
           ll expr1 = yd * xc - xd * yc;
           ll expr2 = yc * yc + xc * xc;
           ll b = expr1 / expr2;
           if (b * expr2 != expr1) return false;
           expr1 = xd + b * yc;
           ll a = expr1 / xc;
           return a * xc == expr1;
    } else if (xc) return xd % xc == 0 && yd % xc == 0;
           else return xd % yc == 0 && yd % yc == 0; 
}

int main()
{
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    if (canGet(xb - xa, yb - ya) || canGet(xb + xa, yb + ya) ||
        canGet(xb + ya, yb - xa) || canGet(xb - ya, yb + xa)) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}