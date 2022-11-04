#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) emplace_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;
int n, p[MX], f[MX];
vii res;

void sw (int i, int j) {
	res.emplace_back(i, j);
	swap(f[p[i]], f[p[j]]);
	swap(p[i], p[j]);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		f[p[i]] = i;
	}

	for (int kk = 0, i = n / 2, j = i + 1; kk < n; kk += 2, i--, j++) {
		if (p[i] != i) {
			if (f[i] > n / 2) sw(f[i], 1);
			sw(f[i], n);
			sw(n, i);
		}

		if (p[j] != j) {
			if (f[j] < n / 2) sw(f[j], n);
			sw(1, f[j]);
			sw(1, j);
		}
	}

	cout << res.size() << endl;
	for (ii &r : res) 
		cout << r.fi << " " << r.se << endl;

	return 0;
}