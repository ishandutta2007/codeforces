#include <iostream>

using namespace std;

int main()
{
    int k, a, b, p, f;
    cin >> k >> a >> b;
    p = a / k + b / k;
    f = !!(a % k) <= !!(b / k) && !!(b % k) <= !!(a / k);
    cout << (f? p: -1);
    return 0;
}