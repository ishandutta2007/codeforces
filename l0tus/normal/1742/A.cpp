#include <bits/stdc++.h>

using namespace std;

#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

// 998244353;

int main()
{
    FAST_IO;
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a + b + c == 2 * max(a, max(b, c)))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}