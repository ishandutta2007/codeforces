#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (a * m <= b)
        cout << n * a << '\n';
    else
        cout << min((b * (n / m) + a * (n % m)), (b * (n / m + 1))) << '\n';
}