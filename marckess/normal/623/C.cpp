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
typedef vector<ii> vii;

const int MX = 100005;
int n, pmx[MX], pmn[MX], smx[MX], smn[MX];
ll res;
ii p[MX];

#define sq(n) (ll(n)*(n))

bool esPos (ll m) {
	for (int i = 1, j = 1, k = n; i <= n && p[i].fi <= 0; i++) {
		while (j < n && sq(p[j + 1].fi - p[i].fi) <= m) j++;
		while (abs(p[i].fi) < abs(p[k].fi)) k--;

		int r = min(k, j);
		ll a = min(pmn[i - 1], smn[r + 1]);
		ll b = max(pmx[i - 1], smx[r + 1]);

		if (a > b || (sq(p[i].fi) + max(sq(a), sq(b)) <= m) && sq(a - b) <= m) return 1;
	}

	for (int i = n, j = n, k = 1; i && p[i].fi > 0; i--) {
		while (j > 1 && sq(p[j - 1].fi - p[i].fi) <= m) j--;
		while (abs(p[i].fi) < abs(p[k].fi)) k++;

		int r = max(j, k);
		ll a = min(pmn[r - 1], smn[i + 1]);
		ll b = max(pmx[r - 1], smx[i + 1]);

		if (a > b || (sq(p[i].fi) + max(sq(a), sq(b)) <= m) && sq(a - b) <= m) return 1;
	}

	return 0;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i].fi >> p[i].se;
	sort(p + 1, p + n + 1);

	pmx[0] = -1e9, pmn[0] = 1e9;
	for (int i = 1; i <= n; i++) {
		pmx[i] = max(pmx[i - 1], p[i].se);
		pmn[i] = min(pmn[i - 1], p[i].se);
	}

	smx[n + 1] = -1e9, smn[n + 1] = 1e9;
	for (int i = n; i; i--) {
		smx[i] = max(smx[i + 1], p[i].se);
		smn[i] = min(smn[i + 1], p[i].se);
	}

	res = sq(pmx[n] - pmn[n]);

	ll i = 0, j = res, rep = 64;
	while (rep--) {
		ll m = (i + j) / 2;
		if (esPos(m)) j = m, res = min(res, m);
		else i = m;
	}

	cout << res << endl;

	return 0;
}