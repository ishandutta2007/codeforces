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

const int MX = 300005;
int n, x, y;
ii a[MX];

int obtRes (int ini, int s) {
	int i = 1, j = ini;

	while (i <= n) {
		while (j < n && a[j].fi >= (s + i - 1) / i)
			j++;
		if (j - ini >= i) return i;
		i++;
	}

	return -1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> x >> y;
	for (int i = 0; i < n; i++) {
		cin >> a[i].fi;
		a[i].se = i+1;
	}
	sort(a, a+n, greater<ii>());

	int i, j;

	i = obtRes(0, x);
	if (i != -1) {
		j = obtRes(i, y);
		
		if (j != -1) {
			cout << "Yes" << endl;
			cout << i << " " << j << endl;

			for (int k = 0; k < i; k++)
				cout << a[k].se << " ";
			cout << endl;

			for (int k = 0; k < j; k++)
				cout << a[k+i].se << " ";
			cout << endl;

			return 0;
		}
	}

	j = obtRes(0, y);
	if (j != -1) {
		i = obtRes(j, x);

		if (i != -1) {
			cout << "Yes" << endl;
			cout << i << " " << j << endl;

			for (int k = 0; k < i; k++)
				cout << a[k+j].se << " ";
			cout << endl;

			for (int k = 0; k < j; k++)
				cout << a[k].se << " ";
			cout << endl;

			return 0;
		}
	}

	cout << "No" << endl;

	return 0;
}