#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    if (n < 30)
        cout << m % (1 << n);
    else
        cout << m;
    return 0;
}