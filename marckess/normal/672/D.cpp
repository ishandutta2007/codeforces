#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 500005;
int n, k;
int a[MX];
ll sum;

int obtMx () {
	int i = (sum + n - 1) / n, j = 1e9+5, rep = 31;

	while (rep--) {
		int m = (i+j)/2;
		ll acu = 0;

		for (int i = 0; i < n; i++)
			if (a[i] > m)
				acu += a[i] - m;

		if (acu <= k)
			j = m;
		else
			i = m;
	}

	return j;
}

int obtMn () {
	int i = 1, j = sum / n + 1, rep = 31;

	while (rep--) {
		int m = (i+j)/2;
		ll acu = 0;

		for (int i = 0; i < n; i++)
			if (a[i] < m)
				acu += m - a[i];

		if (acu <= k)
			i = m;
		else
			j = m;
	}

	return i;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	cout << obtMx() - obtMn() << endl;

	return 0;
}