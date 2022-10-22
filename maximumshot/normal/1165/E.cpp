#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

const int inf = 1e9;
const ll inf64 = 1e18;

const ll mod = 998244353;

const int N = 2e5 + 5;

int n;
ll a[N];
ll b[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	ll cnt = 1ll * (i + 1) * (n - i);
	    a[i] *= cnt;
    }

    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        a[i] %= mod;
    	cin >> b[i];
    }

    sort(b, b + n);
    reverse(b, b + n);

    ll res = 0;

    for (int i = 0; i < n; i++) {
	    res += a[i] * b[i] % mod;
	    res = (res % mod + mod) % mod;
    }

    cout << res << "\n";

    return 0;
}