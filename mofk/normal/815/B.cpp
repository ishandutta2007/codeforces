#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

const int mod = 1e9 + 7;
int N;
vi v;
vi vk;
int ft[200005], inv[200005];

int pw(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = 1ll * ret * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return ret;
}

int comb(int n, int k) { if (k < 0 || k > n) return 0; return 1ll * ft[n] * inv[k] % mod * inv[n-k] % mod; }

vi trans(vi a, int sign) {
    vi b;
    ff(i, 1, a.size() - 1) b.pb((a[i-1] + 1ll * sign * a[i]) % mod), sign = mod - sign;
    return b;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    int x;
    ff(i, 1, N) cin >> x, v.pb(x);
    ft[0] = 1; ff(i, 1, N) ft[i] = 1ll * i * ft[i-1] % mod;
    ff(i, 0, N) inv[i] = pw(ft[i], mod - 2);
    int sz = N % 4, n = N / 4 * 2;
    if (sz == 0) sz = 4, n -= 2;
    ff(i, 0, sz - 1) {
        x = 0;
        for (int k = 0; k <= n; ++k) x = (x + 1ll * v[i + 2*k] * comb(n, k)) % mod;
        vk.pb(x);
    }
    int sign = 1;
    while (vk.size() > 1) {
        vk = trans(vk, sign);
        if (vk.size() & 1) sign = mod - sign;
    }
    cout << vk[0] << endl;
    return 0;
}