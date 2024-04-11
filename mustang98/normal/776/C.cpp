#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111;
const ll maxsum = 100000LL * 1000000111LL;

ll m[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    ll n, k;
    vector<ll> pows;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &m[i]);
        //m[i] = i % 2 == 0 ? -2 : 2;
    }
    pows.pb(1);
    if (k == -1) {
        pows.pb(-1);
    }
    else if (k != 1 && k != -1) {
        ll curpow = k;
        while (abs(curpow) < maxsum) {
            pows.pb(curpow);
            curpow *= k;
        }
    }

    ll ans = 0;
    map<ll, int> ms;
    ll needadd = 0;
    for (int i = 0; i < n; ++i)
    {
        needadd += m[i];
        ms[m[i] - needadd]++;
        for (ll curp : pows) {
            ans += ms[curp - needadd];
        }
    }
    cout << ans;
    return 0;
}