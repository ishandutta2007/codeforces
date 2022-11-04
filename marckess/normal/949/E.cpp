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

const int MX = 200005;
int n, a[MX];
bitset<2*MX> bs[20];

int techo (int a, int b) {
	return (a + b - 1) / b;
}

void reset (int k) {
	int x = 1 << k;
	for (int i = -techo(MX,x); i <= techo(MX,x); i++)
		bs[k][i+MX] = 0;
}

vi go (int k) {
	bool f = 0;
	int x = 1 << k;

	if (k == 19) return vi(0);

	for (int i = -techo(MX,x); i <= techo(MX,x); i++)
		if (bs[k][i+MX])
			f |= i % 2;

	if (!f) {
		reset(k+1);
		for (int i = -techo(MX,x); i <= techo(MX,x); i++)
			if (bs[k][i+MX])
				bs[k+1][i/2+MX] = 1;
		return go(k+1);
	}

	vi pos, neg;

	reset(k+1);
	for (int i = -techo(MX,x); i <= techo(MX,x); i++)
		if (bs[k][i+MX]) {
			if (i % 2) bs[k+1][(i-1)/2+MX] = 1;
			else bs[k+1][i/2+MX] = 1;
		}
	pos = go(k+1);

	reset(k+1);
	for (int i = -techo(MX,x); i <= techo(MX,x); i++)
		if (bs[k][i+MX]) {
			if (i % 2) bs[k+1][(i+1)/2+MX] = 1;
			else bs[k+1][i/2+MX] = 1;
		}
	neg = go(k+1);

	if (pos.size() <= neg.size()) {
		pos.pb(x);
		return pos;
	}

	neg.pb(-x);
	return neg;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		bs[0][a[i]+MX] = 1;
	}

	vi res = go(0);
	
	cout << res.size() << endl;
	for (int x : res) cout << x << " ";
	cout << endl;

	return 0;
}