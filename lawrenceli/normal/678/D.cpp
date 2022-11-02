#include <bits/stdc++.h>

using namespace std;

#define A first
#define B second

typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;

int A, B, x;

pii exp(ll n) {
    if (n == 0) return pii(1, 0);
    if (n & 1) {
        pii p = exp(n - 1);
        return pii(ll(A) * p.A % mod, (ll(A) * p.B + B) % mod);
    } else {
        pii p = exp(n >> 1);
        return pii(ll(p.A) * p.A % mod, (ll(p.A) * p.B + p.B) % mod);
    }
}

int main() {
    ll n;
    cin >> A >> B >> n >> x;

    pii p = exp(n);
    cout << (ll(x) * p.A + p.B) % mod << '\n';
}