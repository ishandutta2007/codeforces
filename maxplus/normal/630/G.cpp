#include <iostream>

using namespace std;

int main()
{
    uint64_t n;
    cin >> n;--n;
    cout << (n + 1) * (n + 2) / 2 * (n + 3) / 3 * (n + 4) / 4 * (n + 5) / 5 *
            (n + 1) * (n + 2) / 2 * (n + 3) / 3;
    return 0;
}