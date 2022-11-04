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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, d, b, a[MX], v[MX];

int techo (int a, int b) {
	return (a + b - 1) / b;
}

bool esPos (int m) {
	int i = m, j = n-1-m, l = 0, r = n-1;
	for (int i = 0; i < n; i++) v[i] = a[i];
	if (i >= j) return 1;

	int ned = b, c = m+1;
	while (i < (n + 1) / 2) {
		if (!v[l]) {
			l++;
			if (l == n) return 0;
			continue;
		}

		if (techo(abs(l-i), d) > c) {
			l++;
			if (l == n) return 0;
			continue;
		}

		int d = min(v[l], ned);
		v[l] -= d;
		ned -= d;

		if (!ned) {
			i++;
			c++;
			ned = b;
		}
	}

	ned = b, c = m+1;
	while (j >= i) {
		if (!v[r]) {
			r--;
			if (r == -1) return 0;
			continue;
		}

		if (techo(abs(r-j), d) > c) {
			r--;
			if (r == -1) return 0;
			continue;
		}

		int d = min(v[r], ned);
		v[r] -= d;
		ned -= d;

		if (!ned) {
			j--;
			c++;
			ned = b;
		}
	}

	return 1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> d >> b;
	for (int i = 0; i < n; i++) cin >> a[i];

	int i = 0, j = n / 2 + 1, rep = 20;
	while (rep--) {
		int m = (i+j)/2;
		if (esPos(m)) j = m;
		else i = m;
	}
	cout << j << endl;

	return 0;
}