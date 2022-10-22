#include <iostream>
using namespace std;

int a1, a2;

int Rev(int x)
{
    int res = 0;
    while (x) {
        res = 10 * res + x % 10;
        x /= 10;
    }
    return res;
}

int main()
{
    cin >> a1 >> a2;
    cout << a1 + Rev(a2) << endl;
    return 0;
}