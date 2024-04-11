#include <iostream>
#include <algorithm>
using namespace std;

int n, i, t, a[25], p[25];

int cmp(int u, int v)
{
    return a[u] < a[v];
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[p[i] = i];
    sort(p, p + n, cmp);
    for (int i = 0; i < n; i++)
        if (i)
            swap(a[p[i]], a[p[i - 1]]);
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
}