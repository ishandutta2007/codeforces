#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;


int main()
{
    int t, n, a[55];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            a[i] = pow(2, (int)(log(a[i]) / log(2)));
        }
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " \n"[i == n - 1];
        }
    }
}