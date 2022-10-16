#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << (1ll << ++n) - 2;
    return 0;
}