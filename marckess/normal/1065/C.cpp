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
int n, k;
ll h[MX], acu[MX], res = 0, mn = 1e9;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		mn = min(mn, h[i]);
	}

	sort(h, h+n, greater<int>());

	for (int i = MX-2, j = 0; i >= 0; i--) {
		acu[i] = acu[i+1];
		while (j < n && h[j] == i)
			acu[i]++, j++;
	}

	ll cn = 0;
	for (int i = MX-2; i > mn; i--) {
		if (cn + acu[i] <= k) {
			cn += acu[i];
		} else {
			cn = acu[i];
			res++;
		}
	}
	if (cn) res++;

	cout << res << endl;

	return 0;
}