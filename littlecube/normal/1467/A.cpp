#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n && i < 2; i++)
            cout << "9876543210"[i % 10];
        for (int i = 0; i < n - 2; i++)
            cout << "9012345678"[i % 10];
        cout << '\n';
    }
}