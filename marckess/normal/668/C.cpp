#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n;
ld mx[MX], mn[MX], a[MX], b[MX], sa, sb;

ld f (ld a, ld b, ld c) {
	return (-b + sqrt(max(0.0l, b * b - 4.0l * a * c))) / (2.0l * a); 
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);
	
	cin >> n;
	forn (i, n) cin >> mx[i];
	forn (i, n) cin >> mn[i];

	forn (i, n) {
		ld x = mx[i] + mn[i];
		ld y = mx[i];

		a[i] = f(1, sa - x - sb, y - sa * x);
		b[i] = x - a[i];

		sa += a[i];
		sb += b[i];
	}

	forn (i, n) cout << a[i] << " "; cout << endl;
	forn (i, n) cout << b[i] << " "; cout << endl;

	return 0;
}