#include <bits/stdc++.h>
using namespace std;

int t, n, a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> n;
        if (n % 3 == 0)
            cout << a << '\n';
        else if (n % 3 == 1)
            cout << b << '\n';
        else
            cout << (a ^ b) << '\n';
    }
}