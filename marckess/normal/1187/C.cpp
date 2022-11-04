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

const int MX = 1005;
int n, m, p[MX], t[MX], l[MX], r[MX], a[MX];

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

void join (int a, int b) {
	p[parent(a)] = parent(b);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	iota(p, p+MX, 0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> t[i] >> l[i] >> r[i];
		if (t[i]) {
			for (int k = l[i]; k < r[i]; k++)
				join(k, k+1);
		}
	}

	for (int i = 1, f = MX; i <= n; i++) {
		if (parent(i) == parent(i-1)) {
			a[i] = a[i-1];
		} else {
			a[i] = f--;
		}
	}

	for (int i = 0; i < m; i++) {
		if (!t[i]) {
			int f = 0;
			for (int k = l[i]; k < r[i]; k++)
				if (a[k] > a[k+1])
					f = 1;
			if (!f) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	cout << "YES" << endl;
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
 
	return 0;
}