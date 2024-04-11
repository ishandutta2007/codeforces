#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n, S, a[100005];

ll cal(ll k)
{
    ll cal_a[100005], sum = 0;
    for (int i = 0; i < n; i++)
        cal_a[i] = a[i] + k * (i + 1);
    sort(cal_a, cal_a + n);
    for (int i = 0; i < k; i++)
        sum += cal_a[i];
    return sum;
}

ll bs(int l, int r)
{
    if (r == l)
        return l;
    else if (r - l == 1)
    {
        ll sum = cal(r);
        if (sum <= S)
            return r;
        else
            return l;
    }
    else
    {
        ll sum = cal((l + r) / 2);
        if (sum <= S)
            return bs(((l + r) / 2), r);
        else
            return bs(l, ((l + r) / 2) - 1);
    }
}

int main()
{
    cin >> n >> S;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll k = bs(0, n);
    cout << k << ' ' << (ll)cal(k) << '\n';
}