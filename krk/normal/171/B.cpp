#include <iostream>
using namespace std;

int a;

int main()
{
    cin >> a;
    cout << (2 * a - 1) * (2 * a - 1) + 4 * (a * (a - 1) / 2) << endl;
    return 0;
}