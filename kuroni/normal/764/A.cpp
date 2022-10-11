#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << c / (a * b / gcd(a, b));
}