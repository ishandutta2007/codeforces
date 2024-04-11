#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int Maxk = 10005;
 
ll n, m;
int k;
ll a[Maxk];
ll seq[Maxk];
int slen;
ll need[Maxk];
ll val1 = 0, mod1 = 1;
 
ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }
 
void gcd(ll a, ll &x, ll b, ll &y)
{
    if (a == 0) { x = 0; y = 1; }
    else {
        ll xx, yy;
        gcd(b % a, xx, a, yy);
        x = yy - b / a * xx;
        y = xx;
    }
}
 
ll Inv(ll a, ll mod)
{
    ll x, y;
    gcd(a, x, mod, y);
    x %= mod;
    if (x < 0) x += mod;
    return x;
}
 
ll safeMult(ll a, ll b, ll mod)
{
    if (a == 0 || b == 0) return 0;
    ll res = 0;
    while (b) {
        if (b & 1) res = (res + a) % mod;
        b >>= 1; a = (a + a) % mod;
    }
    return res;
}
 
void Add(ll val2, ll mod2)
{
    ll mod3 = mod1 * mod2;
    ll tmp1 = safeMult(val2, mod1, mod3);
    ll tmp2 = safeMult(tmp1, Inv(mod1, mod2), mod3);
    ll tmp3 = safeMult(val1, mod2, mod3);
    ll tmp4 = safeMult(tmp3, Inv(mod2, mod1), mod3);
    val1 = (tmp2 + tmp4) % mod3;
    mod1 = mod3;
}
 
int main()
{
    scanf("%I64d %I64d %d", &n, &m, &k);
    ll row = 1;
    for (int i = 0; i < k; i++) {
        scanf("%I64d", &a[i]);
        row /= gcd(row, a[i]);
        if (row <= n / a[i]) row *= a[i];
        else {
            printf("NO\n");
            return 0;
        }
    }
    for (ll i = 1; i * i <= row; i++) if (row % i == 0) {
        seq[slen++] = i;
        if (i * i != row) seq[slen++] = row / i;
    }
    sort(seq, seq + slen);
    fill(need, need + slen, -1);
    for (int i = 0; i < k; i++) {
        int ind = lower_bound(seq, seq + slen, a[i]) - seq;
        for (int j = 0; j <= ind; j++) if (seq[ind] % seq[j] == 0) {
            ll got = (seq[j] - i % seq[j]) % seq[j];
            if (need[j] == -1) need[j] = got;
            else if (need[j] != got) {
                printf("NO\n");
                return 0;
            }
        }
    }
    ll num = row;
    for (ll i = 2; i * i <= num; i++) if (num % i == 0) {
        ll mod2 = 1;
        while (num % i == 0) {
            mod2 *= i;
            num /= i;
        }
        int ind = lower_bound(seq, seq + slen, mod2) - seq;
        Add(need[ind], mod2);
    }
    if (num > 1) {
        int ind = lower_bound(seq, seq + slen, num) - seq;
        Add(need[ind], num);
    }
    if (val1 == 0) val1 += mod1;
    if (val1 + k - 1 > m) {
        printf("NO\n");
        return 0;
    }
    for (int i = 0; i < k; i++)
        if (gcd(row, val1 + i) != a[i]) {
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
    return 0;
}