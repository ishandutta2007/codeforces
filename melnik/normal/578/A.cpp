#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

typedef long double ld;

int main()
{
    int x, y, k;
    ld t = 2e9;
    cin >> x >> y;
    if ( y > x) {
        cout << -1;
        return 0;
    }
    k = (ld) ( x + y ) / 2.0 /(ld) y - 1.0 ;
    t = min( t, (ld) ( x + y ) / 2.0 / (ld) (k+1) );
    k = (ld) ( x - y ) / 2.0 /(ld) y;
    t = min( t, (ld) ( x - y ) / 2.0 / (ld) k) ;
    cout << setprecision(25) << t;
    return 0;
}