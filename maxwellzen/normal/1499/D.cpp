#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pi> vpi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define mp make_pair
#define F first
#define S second

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll MOD = 1e9+7;// 998244353;

vector<int> primes, factor;

void sieve2(int n) {
    factor.clear(); factor.resize(n+1, 0);
    primes.clear();
    for (int i = 2; i <= n; i++) {
        if (factor[i]==0) {
            primes.push_back(i);
            for (int j = i; j <= n; j += i) factor[j]=i;
        }
    }
}

int t;
ll c, d, x, cp;

void solve() {
    cin >> c >> d >> x;
    vi f;
    f.pb(1);
    cp=x;
    while (cp>1) {
        int p = factor[cp], exp=0;
        while (cp%p==0) {exp++; cp /= p;}
        int n = f.size();
        F0R(i, n) {
            int temp = f[i];
            F0R(j, exp) {
                temp *= p;
                f.pb(temp);
            }
        }
    }
    ll ans = 0;
    for (int g : f) {
        ll q = x/g;
        if ((q+d)%c != 0) continue;
        ll e = (q+d)/c, add=1;
        while (e>1) {
            int p = factor[e];
            add *= 2;
            while (e%p==0) e /= p;
        }
        ans += add;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve2(20000001);
    cin >> t;
    while (t--) {
        solve();
    }
}