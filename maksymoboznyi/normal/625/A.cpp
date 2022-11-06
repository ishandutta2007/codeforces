#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

ll n, a, b, c;

int main()
{
    cin >> n >> a >> b >> c;
    if (b - c >= a)
    {
        cout << n / a;
        return 0;
    }
    if (n < b)
    {
        cout << n / a;
        return 0;
    }
    ll ans = 1;
    n -= b;
    ans += n / (b-c);
    ll ost = c + n % (b-c);
    ans += ost / a;
    cout << ans;
    return 0;
}