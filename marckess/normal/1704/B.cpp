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

const int MX = 200005;
int n, x, a[MX];

void main_() {
	cin >> n >> x;
	forn (i, n)
		cin >> a[i];
	
	int mn = 1e9, mx = -1e9, res = 0;
	forn (i, n) {
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
		
		if (mx - mn > 2 * x) {
			res++;
			mn = mx = a[i];
		}
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}