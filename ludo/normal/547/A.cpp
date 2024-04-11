#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

#ifdef LOCAL
#include <cassert>
#endif // LOCAL

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll m, h1, a1, x1, y1, h2, a2, x2, y2;

ll modulo(ll a, ll mod)
{
    a %= mod;
    return a < 0 ? (a + mod) : a;
}

ll gcd(ll a, ll b)
{
    while (b) {
        ll c = a % b;
        a = b;
        b = c;
    }
    return a;
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

ll inv(ll num, ll mod)
{
    ll a = num, lasta = mod;
    ll b = 0, lastb = 1;
    ll c = 1, lastc = 0;
    ll t;

    while (a != 0) {
        ll q = lasta / a;

        t = a;
        a = lasta - q * a;
        lasta = t;
        t = b;
        b = lastb - q * b;
        lastb = t;
        t = c;
        c = lastc - q * c;
        lastc = t;
    }

    return modulo(lastc, mod);
}

pll cycle_len(ll h, ll x, ll y, ll a)
{
    pll ret;

    ll len1 = 0, curh = h;
    do {
        curh = (curh * x + y) % m;
        len1++;
    } while (len1 <= m && curh != a);

    if (len1 > m) {
        ret.first = ret.second = -1;
        return ret;
    }

    ret.first = len1;

    ll len2 = 0;
    do {
        curh = (curh * x + y) % m;
        len2++;
    } while (len2 <= m && curh != a);

	if (len2 > m) {
		ret.second = -1;
		return ret;
	}
    ret.second = len2;

    return ret;
}

int main()
{
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
#else
    ios_base::sync_with_stdio(false);
#endif // LOCAL

    cin >> m;
    cin >> h1 >> a1;
    cin >> x1 >> y1;
    cin >> h2 >> a2;
    cin >> x2 >> y2;

    pll p1 = cycle_len(h1, x1, y1, a1);
    pll p2 = cycle_len(h2, x2, y2, a2);

    ll i1 = p1.first, c1 = p1.second;
    ll i2 = p2.first, c2 = p2.second;

    cerr << c1 << ", " << c2 << endl;
    cerr << i1 << ", " << i2 << endl;

//	assert(c1 >= 0 && c2 >= 0);

//	i1 = 3; c1 = 7;
//	i2 = 4; c2 = 11;

//    ll answer = -1;
//    if (i1 == -1 || i2 == -1) {
//        answer = -1;
//    } else if (i1 == i2) {
//        answer = i1;
//    } else if (gcd(c1, c2) != 1) {
//        answer = -1;
//    } else {
//        ll mid = modulo(inv(c1, c2) * (i2 - i1), c2);
//        answer = modulo(i1 + mid * c1, lcm(c1, c2));

    ll answer = -1;
    if (i1 == -1 || i2 == -1) {
        answer = -1;
    } else if (i1 == i2) {
        answer = i1;
    } else if (c1 == -1 && c2 == -1) {
        answer = -1;
    } else if (c1 == -1) {
        answer = (i1 >= i2 && i1 % c2 == i2 % c2) ? i1 : -1;
    } else if (c2 == -1) {
        answer = (i2 >= i1 && i2 % c1 == i1 % c1) ? i2 : -1;
    } else {
		for (ll cycles = 0; cycles <= c2 || cycles <= i2; cycles++) {
            if (i2 == (i1 + cycles * c1) % c2)
                cerr << (i1 + cycles * c1) % c2 << endl;

			if (i1 + cycles * c1 >= i2 && (i1 + cycles * c1) % c2 == i2 % c2) {
                cerr << "answer found" << endl;
				answer = i1 + cycles * c1;
				break;
			}
		}
    }
    cout << answer << endl;
    return 0;
}