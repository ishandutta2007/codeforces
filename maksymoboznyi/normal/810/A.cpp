#include <iostream>

using namespace std;

int main()
{
    int x, n, k, sum = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        sum += x;
    }
    x = 2*k*n-n-2*sum;
    if (x < 0)
        cout << 0;
    else
        cout << x;
    return 0;
}