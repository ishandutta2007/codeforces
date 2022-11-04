#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, a, b, k, acu = 0;
vi v, ini;
char c;

bool esPos (int m, int f) {
	int r = 0;

	for (int i = 0; i < v.size(); i++) {
		int x = v[i];
		
		if (m) {
			int d = min(m, x / b);
			m -= d;
			x -= b * d;
			
			if (f) {
				while (d--) {
					cout << ini[i]+b-1 << " ";
					ini[i] += b;
				}
			}
		}

		if (!m)
			r += x / b;
	}

	return r < a;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> a >> b >> k;
	
	for (int i = 1; i <= n; i++) {
		cin >> c;
		if (c == '1') {
			if (acu) v.pb(acu);
			acu = 0;
		} else {
			if (!acu) ini.pb(i);
			acu++;
		}
	}
	if (acu) v.pb(acu);

	int i = 1, j = n+1, rep = 20;
	while (rep--) {
		int m = (i+j)/2;
		if (esPos(m, 0)) j = m;
		else i = m;
	}

	cout << j << endl;
	esPos(j, 1);
	cout << endl;

	return 0;
}