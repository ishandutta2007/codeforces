#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int N = 1e6+6;
const ll inf = 2e18;
ll a, b, x, y, z, na, nb;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    cin >> x >> y >> z;
    na = x*2 + y;
    nb = z*3 + y;
    ll q = 0;
    cout << max(q, na-a) + max(q, nb-b);
    return 0;
}