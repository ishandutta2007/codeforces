#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, l, r, a[MX];

void solve () {
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++)
		a[i] = 0;
	
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		
		if (i <= l)
			a[x]++;
		else
			a[x]--;
	}
	
	int x = 0, y = 0;
	for (int i = 1; i <= n; i++) {
		x += max(a[i], 0);
		y += min(a[i], 0);
	}
	y = abs(y);
	
	int res = 0;
	if (x > y) {
		for (int i = 1; i <= n; i++)
			while (a[i] >= 2 && x > y) {
				a[i] -= 2;
				x -= 2;
				res++;
			}
	} else {
		for (int i = 1; i <= n; i++)
			while (a[i] <= -2 && x < y) {
				a[i] += 2;
				y -= 2;
				res++;
			}
	}
	
	res += min(x, y);
	res += abs(x - y);
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}