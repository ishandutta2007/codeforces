#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int n, x = 0, y = 0, z = 0, a, b, c;
    cin >> n;
    while (n--)
    {
        cin >> a >> b >> c;
        x += a;
        y += b;
        z += c;
    }
    cout << ((x == 0 && y == 0 && z == 0) ? ("YES\n") :( "NO\n"));
}