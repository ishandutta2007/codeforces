#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 5000005, mod = 1000000007;
int n, a[MX], acu[MX], t[MX];
int m, p[MX / 4], k[MX / 4], b[MX / 4], w[MX / 4];

int seed, base;

int rnd () {
	int res = seed;
	seed = (1ll * seed * base + 233) % mod;
	return res;
}

void gen () {
	for (int i = 1; i <= m; i++) {
		seed = b[i];
		base = w[i];
		
		for (int j = p[i - 1] + 1; j <= p[i]; j++) {
			t[j] = (rnd() % 2) + 1;
			a[j] = (rnd() % k[i]) + 1;
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> p[i] >> k[i] >> b[i] >> w[i];
	gen();
	
	ll cn[] = {0, 0, 0};
	
	for (int i = 1; i <= n; i++)
		cn[t[i]] += a[i];
	
	int x = cn[1] < cn[2] ? 1 : 2, ind = 1;
	
	if (t[1] != x) {
		a[1]--;
		acu[1]++;
		while (ind <= n && t[ind] != x)
			ind++;
	}
	
	if (ind <= n) {
		int rep = 0;
		ll cn = 0;
		
		while (rep < 3) {
			if (t[ind] == x) {
				cn += a[ind];
				acu[ind] += a[ind];
				a[ind] = 0;
			} else {
				ll d = min(1ll * a[ind], cn);
				cn -= d;
				a[ind] -= d;
				acu[ind] += d;
			}
			
			ind++;
			if (ind > n) {
				ind = 1;
				rep++;
			}
		}
	}
	
	ll res = 1;
	for (int i = 1; i <= n; i++)
		(res *= ((acu[i] ^ (1ll * i * i)) + 1) % mod) %= mod;
	cout << res << endl;
	
	return 0;
}