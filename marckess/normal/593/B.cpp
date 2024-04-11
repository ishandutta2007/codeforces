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

const int MX = 100005;

int n;
ll x1, x2;
vi x, y;
ll k[MX], b[MX];
ll izq[MX], der[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> x1 >> x2;
	for (int i = 0; i < n; i++) {
		cin >> k[i] >> b[i];
		izq[i] = x1 * k[i] + b[i];
		der[i] = x2 * k[i] + b[i];
	}

	x = y = vi(n);
	iota(ALL(x), 0);
	iota(ALL(y), 0);

	sort(ALL(x), [&] (int i, int j) { 
		if (izq[i] != izq[j])
			return izq[i] < izq[j];
		return der[i] < der[j];
	});

	sort(ALL(y), [&] (int i, int j) {
		if (der[i] != der[j])
			return der[i] < der[j];
		return izq[i] < izq[j];
	});

	if (x != y)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}