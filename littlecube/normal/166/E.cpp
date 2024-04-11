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
    ll a[4] = {0, 0, 0, 1}, b[4] = {0, 0, 0, 0};
    ll *now = a, *next = b;
    int n;
    cin >> n;
    while (n--)
    {
        next[0] = (now[1] + now[2] + now[3]) % MOD;
        next[1] = (now[0] + now[2] + now[3]) % MOD;
        next[2] = (now[1] + now[0] + now[3]) % MOD;
        next[3] = (now[1] + now[2] + now[0]) % MOD;
        swap(now, next);
    }
    cout << now[3] << '\n';
}