#include <iostream>

using namespace std;

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    int n, d, h;
    cin >> n >> d >> h;
    if (2 * h < d || h > d || (d == 1 && n > 2))
        return cout << -1, 0;
    if (h == 1)
    {
        for (int i = 1; i < n; ++i)
            cout << i + 1 << " 1\n";
        return 0;
    }
    for (int i = 0; i < h; ++i)
        cout << i + 2 << ' ' << i + 1 << '\n';
    for (int i = h; i < d; ++i)
        cout << i + 2 << ' ' << (i == h? 1: i + 1) << '\n';
    for (int i = d + 1; i < n; ++i)
        cout << i + 1 << " 2\n";
    return 0;
}