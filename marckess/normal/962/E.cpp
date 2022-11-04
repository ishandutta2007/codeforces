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

int n, x[200005], inf = 2e9;
char t[200005];
ll res = 0, ub = -inf, ur = -inf, up = -inf;

void extremo (int a) {
	ub = ur = -inf;

	for (int i = a; i < n; i++) {
		if (t[i] == 'B') {
			if (ub != -inf || up != -inf)
				res += x[i] - max(up, ub);
			ub = x[i];
		} else if (t[i] == 'R') {
			if (ur != -inf || up != -inf)
				res += x[i] - max(up, ur);
			ur = x[i];
		} else {
			if (ub != -inf)
				res += x[i] - max(up, ub);
			if (ur != -inf)
				res += x[i] - max(up, ur);
			break;
		}
	}
}

void unir (int a, int b) {
	ll mxb = 0, mxr = 0;
	ll e = 0;
	ub = ur = -inf;
	up = x[a];

	for (int i = a; i <= b; i++) {
		if (t[i] == 'B' || t[i] == 'P') {
			e += x[i] - max(ub, up);
			mxb = max(mxb, x[i] - max(ub, up));
		}
		
		if (t[i] == 'R' || t[i] == 'P') {
			e += x[i] - max(ur, up);
			mxr = max(mxr, x[i] - max(ur, up));
		}

		if (t[i] == 'R') ur = x[i];
		if (t[i] == 'P') up = x[i];
		if (t[i] == 'B') ub = x[i];
	}

	res += min(e, e + x[b] - x[a] - mxr - mxb);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> t[i];

	extremo(0);
	int ult = -1;
	for (int i = 0; i < n; i++) {
		if (t[i] == 'P') {
			if (ult != -1)
				unir(ult, i);
			ult = i;
		}
	}
	if (ult != -1) {
		up = x[ult];
		extremo(ult+1);
	}

	cout << res << endl;

	return 0;
}