#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

ll n, m;

ll sump(ll a) {
    return a * (a + 1) / 2;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    ll sum = 0;
    ll sumpl = sump(n - 1);
    ll summin = 0;
    ll n1 = n - 1;
    summin = 2 * sump(n1 / 2);
    if (n1 % 2 == 1) {
        summin += n1 / 2 + 1;
    }

    for (int i = 0; i < m; ++i) {
        ll x, d;
        cin >> x >> d;
        //x = 1000;
        //d = 1000;
        sum += n * x;
        if (d > 0) {
            sum += d * sumpl;
        } else {
            sum += d * summin;
        }
    }
    //cout << sum << endl;
    ld ans = (ld)sum / n;
    cout << fixed << setprecision(10) << ans;
    return 0;
}