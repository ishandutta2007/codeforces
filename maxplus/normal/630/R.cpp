#include <iostream>

using namespace std;

int main()
{
    int64_t n;
    cin >> n;
    cout << 2 - (n & 1);
    return 0;
}