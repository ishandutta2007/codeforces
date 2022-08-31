#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

int main()
{
    //freopen("input.txt", "r", stdin);
    ll t, s, a, b, c;
    cin >> t;
    while (t--) {
        cin >> s >> a >> b >> c;
        ll cnt = s / c;
        ll ans = cnt + (cnt / a) * b;
        cout << ans << endl;
    }

    return 0;
}