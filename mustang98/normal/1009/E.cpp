#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000111, inf = 1000111222;

const ll mod = 998244353LL;

ll pow2[max_n];

ll powm(ll a, ll b) {
    return pow2[b];
    if (b == 0) return 1;
    if (b == 1) return (a % mod);
    if (b % 2 == 0) {
        return powm((a * a) % mod, b / 2);
    } else {
        return (a * powm(a, b - 1)) % mod;
    }

}

ll m[max_n];

int main()
{
    pow2[0] = 1;
    pow2[1] = 2;
    for (int i = 2; i < max_n; ++i) {
        pow2[i] = 2LL * pow2[i - 1];
        pow2[i] %= mod;
    }
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        //a = rand() % 1000000;
        m[i] = a;
    }

    ll ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        ll p2 = powm(2, n - 2 - i);
        ll sum = (p2 * m[i]) % mod;
        sum = (sum * (n - i - 1)) % mod;
        ans += sum;
        ans += (m[i] * powm(2, n - 1 - i)) % mod;
        ans %= mod;
    }
    ans += m[n - 1];
    ans %= mod;
    cout << ans;
    return 0;
}