#include <iostream>
#include <cstdio>
using namespace std;

int n, m, c, u, a[1005];

int main()
{
    cin >> n >> m >> c;
    while (m--)
    {
        cin >> u;
        if (u <= c / 2)
        {
            for (int i = 1; i <= n; i++)
                if (a[i] == 0 || a[i] > u)
                {
                    a[i] = u;
                    cout << i << '\n';
                    fflush(stdout);
                    break;
                }
        }
        else
        {
            for (int i = n; i >= 1; i--)
                if (a[i] == 0 || a[i] < u)
                {
                    a[i] = u;
                    cout << i << '\n';
                    fflush(stdout);
                    break;
                }
        }
    }
}