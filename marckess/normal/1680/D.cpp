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

const int MX = 3005;
ll n, a[MX], no, k, s, l, r;

ll solve (int x, int f) {
	ll mn = 0, mx = 0, act = 0, p = 0;
	
	l = s - k * no;
	r = s + k * no;
	
	forn (i, n) {
		if (a[i]) {
			act += a[i];
		} else {
			if (p == x) {
				f *= -1;
			}
			
			l += k;
			r -= k;
			
			if (f == 1) {
				if (l + k > 0) {
					ll d = -l;
					
					act += d;
					l += d;
					r += d;
				} else {
					act += k;
					l += k;
					r += k;
				}
			} else if (f == -1) {
				if (r - k < 0) {
					ll d = -r;
					
					act += d;
					l += d;
					r += d;
				} else {
					act += -k;
					l += -k;
					r += -k;
				}
			}
			
			p++;
		}
		
		mn = min(mn, act);
		mx = max(mx, act);
	}
	
	if (act) return -1;
	return mx - mn + 1;
}

void main_() {
	cin >> n >> k;
	
	forn (i, n) {
		cin >> a[i];
		s += a[i];
		no += !a[i];
	}
	
	l = s - k * no;
	r = s + k * no;
	
	if (0 < l || r < 0) {
		cout << -1 << endl;
		return;
	}
	
	ll res = -1;
	forn (i, no + 1)
		res = max({res, solve(i, 1), solve(i, -1)});
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}