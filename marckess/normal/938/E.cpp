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

const int MX = 1000005, mod = 1e9+7;
int n;
ll a[MX], fac[MX], inv[MX], mn = 0, acu, act, res = 0;

void precal () {
	fac[0] = 1;
	inv[0] = inv[1] = 1;

	for (int i = 1; i < MX; i++) 
		fac[i] = (fac[i-1] * i) % mod;

	for (int i = 2; i < MX; i++)
		inv[i] = inv[mod % i] * (mod - mod / i) % mod;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    precal();

    cin >> n;
    for (int i = 0; i < n; i++)
    	cin >> a[i];
    sort(a, a+n);

    int i = 0;
    while (i < n) {
    	acu = 0;
    	act = a[i];

    	while (i < n && a[i] == act) {
    		i++;
    		acu++;
    	}

    	if (i < n) {
    		res += act * acu % mod
    			 * fac[n] % mod
    			 * inv[n-mn] % mod;
    		res %= mod;
    	}

    	mn += acu;
    }

    cout << MOD(res, mod) << endl;

    return 0;
}