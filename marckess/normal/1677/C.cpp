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

const int MX = 100005;
int n, a[MX], b[MX], p[MX], sz[MX];

int parent (int a) {
	return p[a] == a ? a : p[a] = parent(p[a]);
}

void main_() {
	cin >> n;
	
	forr (i, 1, n) {
		p[i] = i;
		sz[i] = 0;
	}
	
	forr (i, 1, n) cin >> a[i];
	forr (i, 1, n) {
		cin >> b[i];
		p[parent(a[i])] = parent(b[i]);
	}
	
	forr (i, 1, n)
		sz[parent(i)]++;
		
	vi s;
	forr (i, 1, n)
		s.pb(sz[i] - (sz[i] & 1));
	
	sort(all(s), [&] (int x, int y) {
		if (x % 2 != y % 2) return x % 2 < y % 2;
		return x > y;
	});
	
	ll res = 0;
	int x = 1, y = n;
	for (int k : s)
		if (k) {
			vi v;
			int f = 0;
			
			while (k--) {
				if (f) v.pb(y--);
				else v.pb(x++);
				f ^= 1;
			}
			
			forn (i, v.size())
				res += abs(v[i] - v[(i + 1) % v.size()]);
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