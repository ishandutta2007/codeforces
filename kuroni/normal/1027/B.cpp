#include <iostream>
#include <cstdio>
using namespace std;

int n, q, a, b;

int main()
{
    cin >> n >> q;
    while (q--)
    {
        cin >> a >> b;
        if (!((a + b) & 1))
            cout << 1LL * (a - 1) / 2 * n + (b + 1) / 2 + ((a & 1) ? 0 : (n + 1) / 2) << '\n'; 
        else
            cout << (1LL * n * n + 1) / 2 + 1LL * (a - 1) / 2 * n + (b + 1) / 2 + ((a & 1) ? 0 : n / 2) << '\n';
    }
}