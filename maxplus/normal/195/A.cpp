#include <iostream>

using namespace std;

int main()
{
    long double a, b, c;
    cin >> a >> b >> c;
    cout << max(__builtin_iceill(c * a / b - c), 0);
    return 0;
}