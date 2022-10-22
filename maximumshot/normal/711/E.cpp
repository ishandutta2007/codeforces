#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const mod = 1e6 + 3;

inline int sum(ll a, ll b, int _mod = mod) { return ((a % _mod) + (b % _mod)) % _mod; }
inline int mul(ll a, ll b, int _mod = mod) { return (1ll * (a % _mod) * (b % _mod)) % _mod; }
inline int raz(ll a, ll b, int _mod = mod) { return (((a % _mod) - (b % _mod)) % _mod + _mod) % _mod; }
int binpow(ll n, ll p, int _mod = mod) {
    if(p == 0) return 1ll % _mod;
    int q = binpow(n, p / 2);
    q = mul(q, q, _mod);
    if(p % 2) q = mul(q, n, _mod);
    return q;
}
inline int del(ll a, ll b) { return mul(a, binpow(b, mod - 2)); }

bool solve() {

    ll n, k;

    cin >> n >> k;

    if(n <= 62 && (1ll << n) < k) {
        cout << "1 1\n";
        return true;
    }

    ll cnt = 0;
    ll st = 0;

    for(int i = 62;i >= 0;i--) {
        /*
         * val = 2 ** i
         * C = (k - 1) / val - cnt
         * cnt += C
         * st += C * i
         * */
        ll val = (1ll << i);
        ll C = (k - 1) / val - cnt;
        cnt += C;
        st = sum(st, mul(C, i, mod - 1), mod - 1);
    }

    st = sum(st, n, mod - 1);

    ll A = binpow(2, mul(k, n, mod - 1));
    ll B;

    if(k < mod) {
        B = 1;
        ll value = binpow(2, n % (mod - 1));
        for(ll i = 0;i < k;i++) {
            B = mul(B, raz(value, i));
        }
    }else B = 0;

    ll C = binpow(2, st);

    ll U, V;

    U = raz(del(A, C), del(B, C));
    V = del(A, C);

    cout << U << " " << V << "\n";

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}