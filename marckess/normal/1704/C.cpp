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
int n, m, a[MX];

void main_() {
	cin >> n >> m;
	forn (i, m) {
		cin >> a[i];
		a[i]--;
	}
	sort(a, a + m);
	
	vi v;
	forn (i, m) {
		int x = MOD(a[(i + 1) % m] - a[i] - 1, n);
		if (x) v.pb(x);
	}
	
	sort(all(v), greater<int>());
	int res = 0, off = 0;
	for (int x : v) {
		if (x - 2 * off <= 0) break;
		if (x - 2 * off == 1) {
			res++;
			break;
		}
		
		res += x - 2 * off - 1;
		off += 2;
	}
	
	cout << n - res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}