#include <iostream>

using namespace std;

int n, p, a[51][51];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
        cin >> a[i][j];
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) if (a[i][j] == n - 1)
        p = i;
    for (int i = 0; i < n; ++i)
        cout << (p == i? n: a[p][i]) << ' ';
    return 0;
}