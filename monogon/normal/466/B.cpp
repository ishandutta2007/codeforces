
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// (a + x)(b + y) >= 6n
// minimize (a + x)(b + y)
// smaller side at most sqrt(K), else area is >= K and we can subtract smaller side sqrt(K)

ll n, a, b;

void out(ll a1, ll b1) {
    if(a1 < a) swap(a1, b1);
    cout << a1 * b1 << '\n' << a1 << ' ' << b1 << '\n';
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b;
    if(a * b >= 6 * n) {
        out(a, b);
    }
    ll best = LLONG_MAX;
    ll a1 = 0, b1 = 0;
    for(ll x = 1; x <= 1e5; x++) {
        ll y = (6 * n + x - 1) / x;
        if(((x >= a && y >= b) || (x >= b && y >= a)) && x * y < best) {
            a1 = x;
            b1 = y;
            best = x * y;
        }
    }
    out(a1, b1);
}