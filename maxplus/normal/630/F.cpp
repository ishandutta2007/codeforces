#include <iostream>

using namespace std;

int main()
{
    int64_t n;
    cin >> n;
    cout << n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4 * (n - 4) / 5 * (n - 5) / 6 * (n - 6) / 7 +
            n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4 * (n - 4) / 5 * (n - 5) / 6               +
            n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4 * (n - 4) / 5                             ;
    return 0;
}