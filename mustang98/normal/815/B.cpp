#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222, mod = 1000000007;;

vector<ll > v;

ll f[max_n];
ll rf[max_n];

ll norm(ll a) {
    if (a < 0) {
        a *= -1;
        a %= mod;
        a *= -1;
        a += mod;
    }
    a %= mod;
    return a;
}

ll getC(int n, int k) {
    ll ans = f[n] * rf[k];
    ans %= mod;
    ans *= rf[n - k];
    ans %= mod;
    return ans;
}

ll power(ll a, ll b) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a;
    }
    ll ans = 1;
    while (b) {
        if (b % 2 == 0) {
            a *= a;
            a %= mod;
            b /= 2;
        } else {
            ans *= a;
            b--;
            ans %= mod;
        }
    }
    return ans;
}

void precalc() {
    f[0] = rf[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        f[i] = f[i - 1] * i;
        f[i] = norm(f[i]);
        rf[i] = power(f[i], mod - 2);
    }
}
int sign = 1;
void dumb(int cnt) {
    vector<ll> v1;
    for (int i = 0; i < cnt; ++i) {
        v1.clear();
        for (int i = 0; i < v.size() - 1; ++i) {
            v1.PB(v[i] + sign * v[i + 1]);
            sign *= -1;
        }
        v = v1;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    precalc();
    int n, a;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        v.PB(a);
    }
    while (v.size() % 4 != 1) {
        dumb(1);
    }
    n = v.size();
    //cout << v[0] << endl;
    vector<ll> coef;
    for (int i = 0; i <= n / 2; ++i) {
        coef.PB(getC(n / 2, i));
        coef.PB(0);
    }
    coef.pop_back();
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += v[i] * coef[i];
        ans = norm(ans);
    }
    cout << ans;
    return 0;
}