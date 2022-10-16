#include <iostream>

using namespace std;

int main()
{
    int n, m;
    int a[100], b[100];
    cin >> n >> m;
    if (n == 1)
        a[0] = 1;
    else if (n == 2)
    {
        a[0] = 3;
        a[1] = 4;
    }
    else
    {
        for (int i = 0; i < n - 1; ++i)
            a[i] = 2;
        a[n - 1] = n - 2;
    }
    if (m == 1)
        b[0] = 1;
    else if (m == 2)
    {
        b[0] = 3;
        b[1] = 4;
    }
    else
    {
        for (int i = 0; i < m - 1; ++i)
            b[i] = 2;
        b[m - 1] = m - 2;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cout << a[i] * b[j] * 9761 << ' ';
        cout << '\n';
    }
    return 0;
}