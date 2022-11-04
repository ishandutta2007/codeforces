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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 255;
int n, m, a[MX][MX], res[MX][MX], vis[MX * MX];
vi col, fil;
set<int> st;
set<pair<int, ii>> pq; 
int mx[] = {1, -1, 0, 0};
int my[] = {0, 0, 1, -1};

int valid (int i, int j) {
	if (i < 0 || n <= i || j < 0 || m <= j || !res[i][j]) return -1;
	return res[i][j];
}

void candi (int i, int j) {
	if (i < 0 || n <= i || j < 0 || m <= j || res[i][j]) return;
	int cn = 0, mn = MX * MX;

	forn (l, 4) {
		int t = valid(i + mx[l], j + my[l]);
		if (t != -1) mn = min(mn, t), cn++;
	}

	if (cn == 2) pq.emplace(mn, ii(i, j));
}

void solve () {
	cin >> n >> m;
	forn (i, n) forn (j, m) cin >> a[i][j];

	forn (i, n * m) st.insert(i + 1);

	forn (i, n) {
		int mx = 0;
		forn (j, m) mx = max(mx, a[i][j]);
		col.pb(mx);
		st.erase(mx);
	}

	forn (j, m) {
		int mx = 0;
		forn (i, n) mx = max(mx, a[i][j]);
		fil.pb(mx);
		st.erase(mx);
	}

	sort(all(col), greater<int>());
	sort(all(fil), greater<int>());

	int x = 0, y = 0, ax = 0, ay = 0;
	for (int i = 0, j = 0; i < col.size() || j < fil.size();) {
		if (i < col.size() && j < fil.size() && col[i] == fil[j]) {
			res[x][y] = col[i];
			ax = x, ay = y;
			x++, y++;
			i++, j++;
		} else if (i < col.size() && (j == fil.size() || col[i] > fil[j])) {
			res[x][ay] = col[i];
			x++;
			i++;
		} else {
			res[ax][y] = fil[j];
			y++;
			j++;
		}
	}

	forn (i, n) forn (j, m) candi(i, j);

	while (st.size()) {
		int k = *st.rbegin(), i, j;
		auto it = *pq.rbegin();
		tie(i, j) = it.se;

		res[i][j] = k;

		forn (l, 4) candi(i + mx[l], j + my[l]);
		
		st.erase(k);
		pq.erase(it);
	}

	forn (i, n) {
		forn (j, m) cout << res[i][j] << " ";
		cout << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();

	return 0;
}