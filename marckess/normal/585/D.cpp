#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

map<ii, ii> mp;
int n, l[30], m[30], w[30];
ll mx = -1e18, res, off;

void obtMP (int i, int ab, int bc, int a, int mk) {
	if (i == -1) {
		ii k(ab, bc);
		if (mp.find(k) != mp.end() && mp[k].fi > a)
			return;
		mp[k] = {a, mk};
		return;
	}

	obtMP (i-1, 
		   ab - m[i], 
		   bc + m[i] - w[i],
		   a,
		   mk * 3);

	obtMP (i-1,
		   ab + l[i],
		   bc - w[i],
		   a + l[i],
		   mk * 3 + 1);

	obtMP (i-1,
		   ab + l[i] - m[i],
		   bc + m[i],
		   a + l[i],
		   mk * 3 + 2);
}

void obtRes (int i, int ba, int cb, int a, int mk) {
	if (i < n/2) {
		ii k(ba, cb);
		if (mp.find(k) != mp.end()) {
			ii &val = mp[k];
			if (val.fi + a > mx) {
				mx = val.fi + a;
				res = mk * off + val.se;
			}
		}
		return;
	}

	obtRes (i-1,
		    ba + m[i],
		    cb + w[i] - m[i],
		    a,
		    mk * 3);

	obtRes (i-1,
			ba - l[i],
			cb + w[i],
			a + l[i],
			mk * 3 + 1);

	obtRes (i-1,
			ba - l[i] + m[i],
			cb - m[i],
			a + l[i],
			mk * 3 + 2);
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> l[i] >> m[i] >> w[i];

	off = pow(3, n/2);
	mp[{0, 0}] = {0, 0};
	obtMP (n/2-1, 0, 0, 0, 0);
	obtRes (n-1, 0, 0, 0, 0);


	if (mx == -1e18) {
		cout << "Impossible" << endl;
	} else {
		for (int i = 0; i < n; i++) {
			int d = res % 3;
			if (!d)
				cout << "MW" << endl;
			else if (d == 1) 
				cout << "LW" << endl;
			else
				cout << "LM" << endl;
			res /= 3;
		}
	}

    return 0;
}