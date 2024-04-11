#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        if (abs(n - m) <= 1)
            cout << n + m << '\n';
        else
            cout << max(n, m) * 2 - 1 << '\n';
    }
}