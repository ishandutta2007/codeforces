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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 2000005;
int n, a[MX], d;
ll x, y, acu[MX], s[MX], res;

ii sum (int i, int j) {
	if (i > j) return {0, 0};
	return {acu[j] - acu[i - 1], s[j] - s[i - 1]};
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> x >> y;

	forn (i, n) {
		cin >> a[i];
		acu[a[i]]++;
		s[a[i]] += a[i];
	}

	for (int i = 1; i < MX; i++) {
		acu[i] += acu[i - 1];
		s[i] += s[i - 1];
	}

	d = x / y;
	res = x * n;

	for (int i = 2; i < MX; i++) {
		ll p = 0;
		
		for (int j = i, k = 0; j < MX; j += i, k += i) {
			p += x * sum(k + 1, j - d - 1).fi;
			p += y * (j * sum(max(j - d, k + 1), j - 1).fi - sum(max(j - d, k + 1), j - 1).se);
		}

		res = min(res, p);
	}

	cout << res << endl;

	return 0;
}