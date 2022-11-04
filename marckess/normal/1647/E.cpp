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

const int MX = 100005, LG = 30;
int n, p[MX][LG], a[MX], b[MX], mx, nnw, nc, in[MX];
set<int> st;

int find (int u, int k) {
	forn (j, LG)
		if (k & (1 << j))
			u = p[u][j];
	return u;
}

void main_() {
	cin >> n;
	
	forr (i, 1, n) {
		cin >> p[i][0];
		st.insert(p[i][0]);
	}
	
	forr (i, 1, n) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	
	nnw = n - int(st.size());
	nc = (mx - n) / nnw;
	
	for (int j = 1; j < LG; j++)
		for (int i = 1; i <= n; i++)
			p[i][j] = p[p[i][j - 1]][j - 1];
	
	st.clear();
	forr (i, 1, n)
		st.insert(i);
	forr (i, 1, n)
		st.erase(a[i]);
	
	for (int i = 1; i <= n; i++) {
		int x = find(i, nc);
		
		if (!in[x]) {
			cout << a[x] << " ";
			in[x] = 1;
		} else {
			auto it = st.upper_bound(a[x]);
			cout << *it << " ";
			st.erase(it);
		}
	}
	
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}