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
int n, a[MX], f[MX];

void main_() {
	cin >> n;
	forn (i, n) {
		cin >> a[i];
		f[i] = 0;
	}
	
	if (n % 2) {
		cout << -1 << endl;
		return;
	}
	
	int act = a[0];
	forn (i, n) {
		if (act != a[i]) {
			if (f[i - 1]) {
				f[i - 1] = f[i] = 0;
			} else {
				f[i] = 1;
			}
		}
		act *= -1;
	}
	
	vii res;
	forn (i, n) {
		if (f[i]) {
			res.back().se++;
		} else {
			res.pb({i, i});
		}
	}
	
	cout << res.size() << endl;
	for (ii p : res)
		cout << p.fi + 1 << " " << p.se + 1 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}