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
int n, q, a[MX], acu[MX];
vi pos;
map<int, vi> in[MX];

void main_() {
	cin >> n >> q;
	
	forr (i, 1, n) {
		cin >> a[i];
		acu[i] = a[i] ^ acu[i - 1];
		
		if (a[i]) pos.pb(i);
		in[i % 2][acu[i]].pb(i);
	}
	
	while (q--) {
		int l, r;
		cin >> l >> r;
		
		auto lb = lower_bound(all(pos), l) - pos.begin();
		if (lb == pos.size() || pos[lb] > r) {
			cout << 0 << endl;
			continue;
		}
		
		if (acu[r] ^ acu[l - 1]) {
			cout << -1 << endl;
			continue;
		}
		
		if ((r - l + 1) % 2 || !a[l] || !a[r]) {
			cout << 1 << endl;
			continue;
		}
		
		vi &v = in[1 - r % 2][acu[r]];
		lb = lower_bound(all(v), l) - v.begin();
		if (lb < v.size() && v[lb] <= r) {
			cout << 2 << endl;
			continue;
		}
		
		cout << -1 << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}