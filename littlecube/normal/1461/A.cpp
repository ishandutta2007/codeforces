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
        int n, k;
        cin >> n >> k;
        for (int i = 3; i <= n; i += 3)
            cout << "abc";
        if (n % 3 == 0)
            cout << '\n';
        if (n % 3 == 1)
            cout << "a\n";
        if (n % 3 == 2)
            cout << "ab\n";
    }
}