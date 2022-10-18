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
    ll t, k;
    ll a[100010] = {0};
    cin >> t >> k;

    int i = 0;
    for (; i < k; i++)
        a[i] = 1;
    for (; i <= 100005; i++)
        a[i] = (a[i - k] + a[i - 1]) % MOD;
    for (int i = 1; i <= 100005; i++)
        a[i] = (a[i] + a[i - 1]) % MOD;

    while(t--)
    {
        int x, y;
        cin >> x >> y;
        cout << (a[y] - a[x - 1] + MOD) % MOD << '\n';
    }
}