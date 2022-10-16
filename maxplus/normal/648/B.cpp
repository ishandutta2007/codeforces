#include <iostream>

using namespace std;

int n, x, a[1000001], s;

int main()
{
    cin >> n;
    for (int i = 0; i / 2 < n; ++i)
        cin >> x, a[x]++, s += x;
    s /= n;
    for (int i = 0; i < s; ++i)
        while (a[i])
            cout << i << ' ' << s - i << '\n', --a[i], --a[s - i];
    return 0;
}