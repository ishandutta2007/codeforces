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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 500005;
int n, m, k, p[MX], res, a[MX];
int mx[4 * MX], f[4 * MX], s[4 * MX];
set<ii> st;

void build (int i, int j, int pos) {
	s[pos] = -(j - i + 1);
	
	if (i == j) {
		p[i] = pos;
		return;
	}
	
	int m = (i + j) / 2;
	build(i, m, pos * 2);
	build(m + 1, j, pos * 2 + 1);
}

void update (int i, int k) {
	a[i] += k;

	int pos = p[i];
	mx[pos] = a[i] ? i + a[i] - 1 : 0;
	f[pos] = 0;
	s[pos] = a[i] - 1;
	
	pos /= 2;
	while (pos) {
		if (mx[pos * 2] && mx[pos * 2 + 1]) {
			mx[pos] = mx[pos * 2 + 1];
			f[pos] = f[pos * 2 + 1] - s[pos * 2];
			s[pos] = s[pos * 2 + 1];

			if (f[pos] < 0) {
				mx[pos] += abs(f[pos]);
				s[pos] += abs(f[pos]);
				f[pos] = 0;
			}

			f[pos] += f[pos * 2];
		} else if (mx[pos * 2]) {
			mx[pos] = mx[pos * 2];
			f[pos] = f[pos * 2];
			s[pos] = s[pos * 2] + s[pos * 2 + 1];
		} else if (mx[pos * 2 + 1]) {
			mx[pos] = mx[pos * 2 + 1];
			f[pos] = -s[pos * 2] + f[pos * 2 + 1];
			s[pos] = s[pos * 2 + 1];
		} else {
			mx[pos] = 0;
			f[pos] = 0;
			s[pos] = s[pos * 2] + s[pos * 2 + 1];
		}

		pos /= 2;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k >> m;

	res = n;
	n *= 2;

	build(1, n, 1);

	forn (i, m) {
		int x, y;
		cin >> x >> y;
		
		if (st.count(ii(x, y))) {
			update(abs(x - k) + y, -1);
			st.erase(ii(x, y));
		} else {
			update(abs(x - k) + y, 1);
			st.emplace(x, y);
		}

		cout << max(0, mx[1] - res) << endl;
	}

	return 0;
}