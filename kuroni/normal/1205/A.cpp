#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, a[2 * N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    if (n % 2 == 0)
        return cout << "NO", 0;
    cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
        a[i] = i * 2 + 1;
        a[i + n] = i * 2 + 2;
        if (i & 1)
            swap(a[i], a[i + n]);
    }
    for (int i = 0; i < 2 * n; i++)
        cout << a[i] << " ";
}