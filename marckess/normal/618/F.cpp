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
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 1000005;
int n;
ll a[MX], b[MX];
ii ex[MX];

void res (int i, int j) {
	int d = abs(a[i] - b[j]);

	cout << ex[d].fi - i << endl;
	for (int x = i + 1; x <= ex[d].fi; x++)
		cout << x << " ";
	cout << endl;
	
	cout << ex[d].se - j << endl;
	for (int x = j + 1; x <= ex[d].se; x++)
		cout << x << " ";
	cout << endl;

	exit(0);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	forn (i, n) {
		cin >> a[i+1];
		a[i+1] += a[i];
		ex[i].fi = ex[i].se = -1;
	}
	
	forn (i, n) {
		cin >> b[i+1];
		b[i+1] += b[i];
	}

	int i = n, j = n, f = a[n] < b[n];
	for (int kk = n; kk + 1; kk--) {
		if (f) {
			while (a[i] < b[j]) j--;

			int d = a[i] - b[j];
			if (ex[d].fi != -1) res(i, j);
			ex[d].fi = i, ex[d].se = j;
			i--;
		} else {
			while (a[i] > b[j]) i--;

			int d = b[j] - a[i];
			if (ex[d].fi != -1) res(i, j);
			ex[d].fi = i, ex[d].se = j;
			j--;
		}
	}

	cout << -1 << endl;

	return 0;
}