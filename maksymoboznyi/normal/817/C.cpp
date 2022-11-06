#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

ll ans, s, n, a, x, sum;
int main()
{
    cin >> n >> s;
    for (ll i = s; i <= s+9*18; i++)
    {
        x = i, sum = 0;
        while (x > 0)
        {
            sum += x % 10;
            x /= 10;
        }
        if (i - sum >= s && i <= n)
            ans++;
  //      cout << sum << ' ' << i << ' ' << ans<<endl;

    }
//    cout << ans << endl;
    ll j = 0;
    ans += max(j, n - s-9*18);
    cout << ans;
    return 0;
}