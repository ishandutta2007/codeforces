#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n)
    {
        cout << (32 - __builtin_clz(n)) << ' ';
        n ^= (1 << (31 - __builtin_clz(n)));
    }
    return 0;
}