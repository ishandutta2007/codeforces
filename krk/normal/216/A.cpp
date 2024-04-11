#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c;
int res;

int main()
{
    cin >> a >> b >> c;
    while (a > 1 && b > 1 && c > 1) {
        res += 2 * (a + b + c) - 6;
        a--; b--; c--;
    }
    if (a == 1) res += b * c;
    else if (b == 1) res += a * c;
    else if (c == 1) res += a * b;
    cout << res << endl;
    return 0;
}