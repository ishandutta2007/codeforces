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

const int MX = 100005;
int n, x, y, k, no, b[MX], res[MX];
vi pos[MX];
priority_queue<ii> pq;

void reset () {
	for (int i = 1; i <= n + 1; i++)
		pos[i].clear();
	no = 1;
	while (pq.size()) pq.pop();
	forn (i, n) res[i] = -1;
}

void solve () {
	cin >> n >> x >> y;
	k = y - x;
	reset();

	forn (i, n) {
		cin >> b[i];
		pos[b[i]].pb(i);

		while (pos[no].size())
			no++;
	}

	for (int i = 1; i <= n + 1; i++)
		pq.emplace(pos[i].size(), i);

	while (x) {
		ii p = pq.top();
		pq.pop();

		res[pos[p.se].back()] = p.se;
		pos[p.se].pop_back();
		
		p.fi--;
		pq.push(p);
		x--;
	}

	priority_queue<ii, vii, greater<ii>> pq;

	vii v;
	vi ot;
	for (int i = 1; i <= n + 1; i++) {
		for (int x : pos[i])
			v.emplace_back(i, x);
		pq.emplace(pos[i].size(), i);
	}

	while (pq.size()) {
		ii p = pq.top();
		pq.pop();

		int d = min(k, (int)pos[p.se].size());
		k -= d;

		forn (i, d) ot.pb(p.se);
	}

	while (ot.size() < v.size())
		ot.pb(no);

	sort(all(v));
	sort(all(ot));
	reverse(all(ot));

	int j = -1;
	forn (i, v.size()) if (v[i].fi == ot[i]) {
		j = i;
		break;
	}

	int i = 0;
	while (i < v.size() && j != -1 && j < v.size() && v[j].fi == ot[j]) {
		while (i < v.size() && (v[i].fi == v[j].fi || ot[i] == ot[j])) i++;
		if (i == v.size()) break;

		swap(ot[i], ot[j]);
		i++, j++;
	}

	forn (i, v.size()) if (v[i].fi == ot[i]) {
		cout << "NO" << endl;
		return;
	}

	forn (i, v.size()) res[v[i].se] = ot[i];

	cout << "YES" << endl;
	forn (i, n) cout << res[i] << " ";
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}