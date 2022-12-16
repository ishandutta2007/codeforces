#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector <int> vi;
typedef pair <int, int> pii;
#define fir first
#define sec second
template <typename __Tp> void read(__Tp &x) {
    int f = 0; x = 0; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
    for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    if (f) x = -x;
}
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &...y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
void write(const char *s) { for (int i = 0; s[i]; ++i) putchar(s[i]); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ...y) { write(x), write(y...); }
template <int mod>
class mint {
public:
    int x;
    mint() : x(0) {}
    mint(int x) : x((x % mod + mod) % mod) {}
    mint(long long x) : x((x % mod + mod) % mod) {}
    mint(unsigned int x) : x((x % mod + mod) % mod) {}
    mint(unsigned long long x) : x((x % mod + mod) % mod) {}
    friend mint operator + (mint a, mint b) { return (a.x += b.x) >= mod ? a.x -= mod : 0, a; }
    friend mint operator - (mint a, mint b) { return (a.x -= b.x) < 0 ? a.x += mod : 0, a; }
    friend mint operator * (mint a, mint b) { return (ll) a.x * b.x % mod; }
    template <typename __Tp>
    friend mint operator ^ (mint a, __Tp b) {
        mint ans = 1;
        while (b) {
            if (b & 1) ans *= a;
            a *= a, b >>= 1;
        }
        return ans;
    }
    friend mint operator / (mint a, mint b) { return a * (b ^ (mod - 2)); }

    friend mint & operator += (mint &a, mint b) { return a = a + b; }
    friend mint & operator -= (mint &a, mint b) { return a = a - b; }
    friend mint & operator *= (mint &a, mint b) { return a = a * b; }
    friend mint & operator /= (mint &a, mint b) { return a = a / b; }
    template <typename __Tp>
    friend mint & operator ^= (mint &a, __Tp b) { return a = a ^ b; }
};

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
const ll N = 1e5, maxn = N + 10, mod = 1e9 + 7;
typedef mint <mod> mi;
ll n, v[maxn], pr[maxn], cntp, popcnt[1024], mul[1024], lg2[1024];
mi ans;

mi calc(ll n, ll x) {
    if (x == 1) return n;
    vector <ll> vec;
    while (x > 1) vec.push_back(v[x]), x /= v[x];
    sort(begin(vec), end(vec)), vec.erase(unique(begin(vec), end(vec)), end(vec));
    ll m = vec.size(); mi res = n;
    mul[0] = n;
    for (ll s = 1; s < (1 << m); ++s) {
        popcnt[s] = popcnt[s & (s - 1)] + 1;
        mul[s] = mul[s & (s - 1)] / vec[lg2[s & (-s)]];
        res += (popcnt[s] & 1 ? -1 : 1) * mul[s];
    }
    return res;
}

int main() {
    for (ll i = 0; i < 10; ++i) lg2[1 << i] = i;
    for (ll i = 2; i <= N; ++i) {
        if (!v[i]) v[i] = i, pr[++cntp] = i;
        for (ll j = 1; j <= cntp; ++j) {
            if (pr[j] > v[i] || i * pr[j] > N) break;
            v[i * pr[j]] = pr[j];
        }
    }
    read(n);
    for (ll d = 1; d <= n; ++d) {
        ll mul = d / gcd(n, d); mi sum = 0;
        for (ll i = d; i <= n; i += d) {
            mi c = calc((n - i) / d, i / d);
            sum += (n - 2 * i) * c;
        }
        ans += mul * sum;
    }
    write(ans.x, '\n');
	return 0;
}