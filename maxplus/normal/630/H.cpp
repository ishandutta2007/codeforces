#include <iostream>

using namespace std;

int main()
{
    int64_t n;
    cin >> n;
    cout << n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 120 *
            n * (n - 1) * (n - 2) * (n - 3) * (n - 4);
    return 0;
}