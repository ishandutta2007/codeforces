#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 4e6+5;

ll a, b, ans = 1;

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    if (b - a > 10)
        cout << 0;
    else
    {
        for (ll i = a +1; i <= b; i++)
            ans = (ans*(i%10)%10);
        cout << ans;
    }
    return 0;
}