#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int n, mod = 1e9+7;
ll a[305], fac[1005], comb[1005][1005], dp[1005][1005];
bitset<305> bs;
vi v;
int acu = 1;

ll C (int n, int k) {
	if (n < 0 || k < 0 || k > n)
		return 0;

	if (n == k || k == 0)
		return 1;

	if (comb[n][k] != -1)
		return comb[n][k];

	return comb[n][k] = (C(n-1, k) + C(n-1, k-1)) % mod;
}

bool esCP (ll n) {
	ll d = sqrt(n);

	for (int i = -2; i <= 2; i++)
		if ((d + i) * (d + i) == n)
			return true;

	return false;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 1005; i++) {
    	fill(comb[i], comb[i]+1005, -1);
    	fac[i] = (i ? fac[i-1] * i : 1) % mod;
    }

    cin >> n;
    for (int i = 0; i < n; i++)
    	cin >> a[i];

    for (int i = 0; i < n; i++) {
    	if (!bs[i]) {
    		v.push_back(1);
    		for (int j = i+1; j < n; j++) {
    			if (esCP(a[i] * a[j])) {
    				v.back()++;
    				bs[j] = 1;
    			}
    		}
    	}
    }

    dp[0][0] = 1;
    for (int i = 0; i < v.size(); i++) {
    	for (int b = 0; b <= acu; b++) {
    		for (int s = 1; s <= min(acu, v[i]); s++) {
    			for (int e = 0; e <= min(s, b); e++) {
    				int f = s - e;
    				int g = acu - b;

    				ll res = fac[v[i]];
    				
    				res *= dp[i][b];
    				res %= mod;

    				res *= C(v[i]-1, s-1);
    				res %= mod;

    				res *= C(b, e);
    				res %= mod;

    				res *= C(g, f);
    				res %= mod;

    				dp[i+1][b - e + v[i] - s] += res;
    				dp[i+1][b - e + v[i] - s] %= mod;
    			}
    		}
    	}
    	acu += v[i];
    }

    cout << dp[v.size()][0] << endl;

    return 0;
}