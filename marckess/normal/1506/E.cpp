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
int n, q[MX], mn[MX], mx[MX];
set<int> s1, s2;

void solve () {
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		s1.insert(i);
		s2.insert(i);
	}
	
	forn (i, n) {
		cin >> q[i];
		
		if (!i || q[i] != q[i - 1]) {
			mx[i] = mn[i] = q[i];
			s1.erase(q[i]);
			s2.erase(q[i]);
		} else {
			mn[i] = *s1.begin();
			s1.erase(s1.begin());
			
			auto it = s2.lower_bound(q[i]);
			it--;
			mx[i] = *it;
			s2.erase(it);
		}
	}
	
	forn (i, n) cout << mn[i] << " "; cout << endl;
	forn (i, n) cout << mx[i] << " "; cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}