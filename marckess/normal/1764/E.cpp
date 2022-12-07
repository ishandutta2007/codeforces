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
int n, k, a[MX], b[MX];

struct ST {
	ii mn[4 * MX];
	
	void update (int i, int j, int pos, int a, ll k) {
		if (a < i || j < a) return;
		
		if (i == j) {
			mn[pos] = {k, i};
			return;
		}
		
		int m = (i + j) / 2;
		update(i, m, pos * 2, a, k);
		update(m + 1, j, pos * 2 + 1, a, k);
		
		mn[pos] = min(mn[pos * 2], mn[pos * 2 + 1]);
	}
	
	ii query (int i, int j, int pos, int a, int b) {
		if (b < i || j < a) return {1e9, -1e9};
		
		if (a <= i && j <= b) return mn[pos];
		
		int m = (i + j) / 2;
		ii x = query(i, m, pos * 2, a, b);
		ii y = query(m + 1, j, pos * 2 + 1, a, b);
		
		return min(x, y);
	}
}st;

int in[MX];
vvi v;

void main_() {
	cin >> n >> k;
	
	v = {{int(-2e9), int(-2e9), int(-2e9)}};
	
	forr (i, 1, n) {
		cin >> a[i] >> b[i];
		v.pb({a[i] + b[i], a[i], i});
	}
	
	if (k <= a[1]) {
		cout << "YES" << endl;
		return;
	}
	
	if (k - b[1] > a[1]) {
		cout << "NO" << endl;
		return;
	}
	
	sort(all(v));
	multiset<int> mst;
	
	forr (i, 1, n) {
		in[v[i][2]] = i;
		
		if (v[i][2] != 1) {
			st.update(1, n, 1, i, v[i][1]);
			mst.insert(v[i][1]);
		} else {
			st.update(1, n, 1, i, 1e9);
		}
	}
	
	int to = k - b[1];
	while (1) {
		auto it = mst.lower_bound(to);
		if (it != mst.end()) {
			cout << "YES" << endl;
			return;
		}
		
		int j = lower_bound(all(v), vi{to, int(-2e9), int(-2e9)}) - v.begin();
		if (j <= n) {
			ii p = st.query(1, n, 1, j, n);
			if (p.fi == 1e9)
				break;
			
			int i = v[p.se][2];
			to -= b[i];
			mst.erase(mst.find(a[i]));
			
			st.update(1, n, 1, p.se, 1e9);
		} else {
			break;
		}
	}
	
	cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}