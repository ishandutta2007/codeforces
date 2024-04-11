#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, R, r;
int mx;

int main()
{
    cin >> n >> R >> r;
    if (r > R) mx = 0;
    else if (2 * r > R) mx = 1;
    else mx = int(acos(-1.0) / asin(double(r) / double(R - r)) + 1e-6);
    if (n <= mx) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}