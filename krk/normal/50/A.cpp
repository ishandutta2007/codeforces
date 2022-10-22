#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    if (n * m % 2) cout << (n * m - 1) / 2 << endl;
    else cout << n * m / 2 << endl;
    return 0;
}