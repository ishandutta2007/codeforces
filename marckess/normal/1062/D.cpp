#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;

ll n, res = 0;
bitset<MX> bs;

ll f (ll n) {
    return n * (n + 1) / 2;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

    for (int i = 2; i <= n; i++) {
        int x = 1;
        for (int j = 2 * i; j <= n; j += i) {
            x++;
            bs[j] = 1;
        }
        res += 4 * (f(x) - 1);
    }

    cout << res << endl;

	return 0;
}