// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
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
int n, a[MX], x;

void main_() {
	cin >> n >> x;
	forn (i, n)
		cin >> a[i];
	sort(a, a + n);
	
	ll res = 0, acu = 0;
	forn (i, n) {
		acu += a[i];
		
		int l = 0, r = 1e9, rep = 30;
		while (rep--) {
			int m = (l + r + 1) / 2;
			
			if (acu + 1ll * (i + 1) * max(0, m - 1) <= x) {
				l = m;
			} else {
				r = m;
			}
		}
		
		res += l;
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