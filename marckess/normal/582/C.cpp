#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MX = 200005;
int n, a[2 * MX], mx[MX], acu[MX], cl[2 * MX], g[MX];
ll res;

void go (int d) {
	for (int i = 0; i < d; i++) {
		mx[i] = a[i];
		cl[i] = cl[i + n] = i;

		for (int j = i + d; j < n; j += d) {
			mx[i] = max(mx[i], a[j]);
			cl[j] = cl[j + n] = i;
		}
	}

	memset(acu, 0, sizeof(acu));
	for (int i = 1; i < n; i++) 
		acu[i] = acu[i - 1] + (g[i] == d);
	acu[n] = acu[n - 1];

	for (int i = 0, j = 0; i < n; i++, j = max(i, j)) {
		while (j - i < n && a[j] == mx[cl[j]]) j++;
		res += acu[j - i];
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i + n] = a[i];
	}

	for (int i = 1; i <= n; i++)
		g[i] = __gcd(i, n);

	for (int i = 1; i < n; i++) 
		if (n % i == 0)
			go(i);

	cout << res << endl;

	return 0;
}