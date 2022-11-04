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

struct ST {
	int mx[4 * MX], lz[4 * MX];
	
	void init (int n) {
		forn (i, 4 * n + 5)
			mx[i] = lz[i] = -1;
	}
	
	void push (int i, int j, int pos) {
		if (i < j) {
			lz[pos * 2] = max(lz[pos], lz[pos * 2]);
			lz[pos * 2 + 1] = max(lz[pos], lz[pos * 2 + 1]);
		}
		
		mx[pos] = max(lz[pos], mx[pos]);
		lz[pos] = -1;
	}
	
	void update (int i, int j, int pos, int a, int b, ll k) {
		push(i, j, pos);
		
		if (b < i || j < a) return;
		
		if (a <= i && j <= b) {
			lz[pos] = k;
			push(i, j, pos);
			return;
		}
		
		int m = (i + j) / 2;
		update(i, m, pos * 2, a, b, k);
		update(m + 1, j, pos * 2 + 1, a, b, k);
		
		mx[pos] = max(mx[pos * 2], mx[pos * 2 + 1]);
	}
	
	int query (int i, int j, int pos, int a, int b) {
		push(i, j, pos);
		
		if (b < i || j < a) return -1;
		
		if (a <= i && j <= b) return mx[pos];
		
		int m = (i + j) / 2;
		int x = query(i, m, pos * 2, a, b);
		int y = query(m + 1, j, pos * 2 + 1, a, b);
		
		return max(x, y);
	}
}st;

int n, q, t[MX], x[MX], l[MX], r[MX], in[MX], res[MX];
set<int> ex;

void main_() {
	cin >> n >> q;
	
	forn (i, n) {
		ex.insert(i + 1);
		in[i + 1] = 1e9;
	}
	forn (i, q) {
		res[i] = -1;
	}
	st.init(n);
	
	forn (i, q) {
		cin >> t[i];
		
		if (t[i]) {
			cin >> x[i];
			
			if (!ex.count(x[i]))
				res[i] = 0;
		} else {
			cin >> l[i] >> r[i] >> x[i];
			
			if (!x[i]) {
				auto it = ex.lower_bound(l[i]);
				while (it != ex.end() && *it <= r[i]) {
					auto aux = it;
					it++;
					
					st.update(1, n, 1, *aux, *aux, i);
					ex.erase(aux);
				}
			}
		}
	}
	
	forn (i, q) if (!t[i] && x[i]) { 
		auto it = ex.lower_bound(l[i]);
		if (it == ex.end() || *it > r[i]) continue;
		
		auto jt = it; jt++;
		if (jt != ex.end() && *jt <= r[i]) continue;
		
		int t = st.query(1, n, 1, l[i], r[i]);
		in[*it] = min(in[*it], max(i, t));
	}
	
	forn (i, q) {
		if (t[i]) {
			if (!res[i]) cout << "NO" << endl;
			else {
				if (in[x[i]] < i) cout << "YES" << endl;
				else cout << "N/A" << endl;
			}
		}
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