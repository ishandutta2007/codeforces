#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 2000005, mod = 1000000007;
int n, m, k, acu[MX], ant[256];
ll res = 1;
string t;

int query (int a, int b) {
	if (a) return acu[b] - acu[a - 1];
	return acu[b];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k >> t;
	t = "*" + t;
	m = t.size();
	n += m;

	acu[0] = 1;

	for (int i = 1; i < m; i++) {
		int d = query(ant[t[i]], i - 1);
		if (d < 0) d += mod;
		
		res += d;
		if (res >= mod) res -= mod;
		
		ant[t[i]] = i;
		
		acu[i] = d + acu[i - 1]; 
		if (acu[i] >= mod) acu[i] -= mod;
	}

	for (int i = m; i < n; i++) {
		int ind = 'a';

		for (int j = 'b'; j < 'a' + k; j++)
			if (ant[j] < ant[ind])
				ind = j;

		int d = query(ant[ind], i - 1);
		if (d < 0) d += mod;

		res += d;
		if (res >= mod) res -= mod;

		ant[ind] = i;

		acu[i] = d + acu[i - 1];	
		if (acu[i] >= mod) acu[i] -= mod;
	}

	cout << res << endl;
	
	return 0;
}