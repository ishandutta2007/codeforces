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
const ll mod = 1000000009;

ll powa[max_n];
ll powb[max_n];

ll poww(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a % mod;
    if (b % 2 == 0) {
        return poww((a * a) % mod, b / 2);
    } else {
        return (a * poww(a, b - 1)) % mod;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ll n, a, b, k_s, k;
    cin >> n >> a >> b >> k_s;
    string s;
    cin >> s;
    k = k_s;
    while ((k + k_s) < max_n && (k + k_s) <= n + 1) {
        k += k_s;
    }
   // cout << k << endl;
    ll cur_s = 0;
    powa[0] = 1;
    powb[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        powa[i] = powa[i - 1] * a;
        powa[i] %= mod;
        powb[i] = powb[i - 1] * b;
        powb[i] %= mod;
    }

    for (int i = 0; i < k; ++i) {
        ll cur_val = powa[k - i - 1] * powb[i];
        cur_val %= mod;
        if (s[i % k_s] == '-') {
            cur_val = -cur_val;
        }
       // if (cur_val != 1) {
        //    cout << "AAA" << endl;
        //}
        cur_s += cur_val;
        while (cur_s < 0) {
            cur_s += mod;
        }
        cur_s %= mod;
    }
    int fst_a = n, fst_b = 0;
    //cout << cur_s << endl;

    ll cnt = (n + 1) / k;
    ll RES = 0;
    int cur_pa = n - k + 1;
    int cur_pb = 0;
    for (int i = 0; i < cnt; ++i) {
        ll cur_v = poww(a, cur_pa) * poww(b, cur_pb);
        cur_v %= mod;
       // cout << "#" << cur_v << endl;
        RES += cur_s * cur_v;
        RES %= mod;
        cur_pa -= k;
        cur_pb += k;
        fst_a -= k;
        fst_b += k;
    }
    int i = 0;
    while (fst_a > -1) {
        ll cur_val = poww(a, fst_a) * poww(b, fst_b);
        cur_val %= mod;
        if (s[i % k_s] == '-') {
            cur_val = -cur_val;
        }
        RES += cur_val;
        while (RES < 0) {
            RES += mod;
        }
        RES %= mod;
        ++i;
        --fst_a;
        ++fst_b;
    }
    cout << RES;

    return 0;
}
/*
19999997 1 1 9
+++++++++
*/