#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max(max(a - c, c - a), max(b - d, d - b));
    return 0;
}