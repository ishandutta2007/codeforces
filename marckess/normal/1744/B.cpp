#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, q;
ll a[MX], ix, iy, tot;

void main_() {
	cin >> n >> q;
	ix = iy = tot = 0;
	forn (i, n) {
		cin >> a[i];
		if (a[i] % 2 == 0) ix++;
		else iy++;
		tot += a[i];
	}
	
	ll x = 0, y = 0;
	while (q--) {
		int op, k;
		cin >> op >> k;
		
		if (op == 0) {
			if (x % 2 == 0) x += k;
			if (y % 2 == 1) y += k;
		} else {
			if (x % 2 == 1) x += k;
			if (y % 2 == 0) y += k;
		}
		
		cout << tot + ix * x + iy * y << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}