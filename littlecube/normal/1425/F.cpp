#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int n, f[1001];
    cin >> n;

    int a, b;
    cout << "? 1 3" << endl;
    cin >> a;
    cout << "? 2 3" << endl;
    cin >> b;
    f[1] = a - b;
    cout << "? 1 2" << endl;
    cin >> f[2];
    f[2] -= f[1];
    f[3] = a - f[1] - f[2];
    for (int i = 4; i <= n; i++)
    {
        cout << "? " << i - 1 << " " << i << endl;
        cin >> f[i];
        f[i] -= f[i - 1];
    }
    cout << "!";
    for (int i = 1; i <= n; i++)
        cout << " " << f[i];
    cout << endl;
}