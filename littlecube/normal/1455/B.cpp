#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n;
        m = (sqrt(n * 2) + 0.5);
        if (n == m * (m + 1) / 2 - 1)
            cout << m + 1 << '\n';
            else
            cout << m  << '\n';
    }
}