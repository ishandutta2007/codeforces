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
        int n, s[300], r[300];
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> s[i];
        for (int i = 0; i < n; i += 2)
            r[i] = s[i / 2];
        for (int i = 1; i < n; i += 2)
            r[i] = s[n - i / 2 - 1];
        for (int i = 0; i < n; i++)
            cout << r[i] << " \n"[i == n - 1];
    }
}