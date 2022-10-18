#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int n, a, b, c;
    cin >> n;
    while (n--)
    {
        cin >> a >> b >> c;
        if ((a + b + c) % 9 == 0 && a >= (a + b + c) / 9 && b >= (a + b + c) / 9 && c >= (a + b + c) / 9)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}