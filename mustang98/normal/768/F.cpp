#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, mod = 1000000007;

void gcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    ll x1, y1;
    gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
}

ll inv[2 * max_n];
ll ifact[2 * max_n];
ll fact[2 * max_n];

void precalc()
{
    inv[1] = 1;
    for (int i = 2; i < 2 * max_n; ++i) {
        ll x, z;
        gcd(i, mod, x, z);
        while (x < 0) x += mod;
        inv[i] = x;
    }
    ifact[0] = ifact[1] = 1;
    fact[0] = fact[1] = 1;
    for (int i = 2; i < 2 * max_n; ++i) {
        ifact[i] = ifact[i - 1] * inv[i];
        fact[i] = fact[i - 1] * i;
        ifact[i] %= mod;
        fact[i] %= mod;
    }
}

// Combination
ll C(int n, int k)
{
    ll ans = fact[n] * ifact[k];
    ans %= mod;
    ans *= ifact[n - k];
    ans %= mod;
    return ans;
}

// Number of ways to put n boxes in i stacks. Empty stacks are NOT allowed.
ll F(int n, int i)
{
    if (i < 0 || i > n) return 0;
    if (i == 0) {
        return n == 0 ? 1 : 0;
    }
    return C(n - 1, i - 1);
}

// Number of ways to put n boxes in i stacks. Empty stacks are allowed.
ll F1(int n, int i)
{
    if (i < 0 || n < 0) return 0;
    if (n == 0) return 1;
    if (i == 0) return 0;
    return C(n + i - 1, i - 1);
}


int main()
{
    int f, w, h;
    precalc();
    /*for (int i = 0; i < 10; ++i) {
        cout << "i = " << i << "; inv_i = " << inv[i] << "; fact = " << fact[i] << "; inv_fact = " << ifact[i] << ";\n";
    }*/

    cin >> f >> w >> h;
    if (w == 0) {
        cout << 1;
        return 0;
    }
    if (h >= w) {
        cout << 0;
        return 0;
    }
    if(f == 0) {
        cout << 1;
        return 0;
    }
    ++h;
    ll all = 0;
    for (int i = 1; i <= f; ++i) {
        all += F(f, i) * (F(w, i - 1) + 2 * F(w, i) + F(w, i + 1));
        all %= mod;
    }
    ll good = 0;
    for (int i = 1; i <= f; ++i) {
        good += F(f, i) * (F1(w - h * (i - 1), i - 1) + 2 * F1(w - h * i, i) + F1(w - h * (i + 1), i + 1));
        good %= mod;
    }
    ll invall, z;
    gcd(all, mod, invall, z);
    while (invall < 0) {
        invall += mod;
    }
    ll ans = good * invall;
    ans %= mod;
    cout << ans;
    return 0;
}