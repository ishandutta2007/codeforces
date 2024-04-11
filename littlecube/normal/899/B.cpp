#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int p[36] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, t[24], n;
    bool b = false;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> t[i];
    for (int i = 0; i < 36; i++)
        for (int j = 0; j < n; j++)
        {
            if (t[j] != p[(i + j) % 36])
                break;
            if (j == n - 1)
                b = true;
        }

    if (b)
        cout << "Yes\n";
    else
        cout << "No\n";
}