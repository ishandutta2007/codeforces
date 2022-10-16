#include <iostream>
#include <cstring>
#define N 100001

using namespace std;

bool U1 = 1, u[N], U2 = 1;

int a[N], n, k;

int main()
{
    memset(u, 1, sizeof(u));
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        u[i] = 0;
    for (int i = 0; i < n; ++i)
        if (i < k)
            if (i & 1)
                u[a[i] = n - i / 2 - 1] = 1;
            else
                u[a[i] = i / 2] = 1;
        else
            if (u[a[i - 1] + 1])
                u[a[i] = a[i - 1] - 1] = 1;
            else
                u[a[i] = a[i - 1] + 1] = 1;
    for (int i = 0; i < n; ++i)
        cout << a[i] + 1 << ' ';
    return 0;
}