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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;
const ll inf = 1e18;
int n, m, p, q;
string s[MX];
vvi dis;

int mx[] = {1, 0, -1, 0};
int my[] = {0, 1, 0, -1};

bool valid (int i, int j) {
	if (i < 0 || n <= i) return 0;
	if (j < 0 || m <= j) return 0;
	if (s[i][j] == '#') return 0;
	return 1;
}

void dijk (int ps) {
	priority_queue<vi, vvi, greater<vi>> pq;
	forn (i, n)
	forn (j, m)
		if ((i + j) % 2 == ps)
		if (s[i][j] == '.') {
			pq.push({dis[i][j] = 0, i, j});
		}
	
	while (pq.size()) {
		ll d = pq.top()[0];
		int i = pq.top()[1];
		int j = pq.top()[2];
		pq.pop();
		
		if (dis[i][j] < d) continue;
		
		forn (l, 4) {
			int x = i + mx[l];
			int y = j + my[l];
			
			if (!valid(x, y)) continue;
			if (s[x][y] == '.') continue;
			
			ll cost;
			if (s[x][y] == 'L') {
				cost = l % 2 == 0 ? p : q;
				y++;
			} else if (s[x][y] == 'R') {
				cost = l % 2 == 0 ? p : q;
				y--;
			} else if (s[x][y] == 'U') {
				cost = l % 2 == 0 ? q : p;
				x++;
			} else if (s[x][y] == 'D') {
				cost = l % 2 == 0 ? q : p;
				x--;
			}
			
			if (d + cost < dis[x][y]) {
				pq.push({dis[x][y] = d + cost, x, y});
			}
		}
	}
}

void main_() {
	cin >> n >> m >> p >> q;
	forn (i, n)
		cin >> s[i];
	
	dis = vvi(n, vi(m, inf));
	
	dijk(0);
	dijk(1);
	
	ll res = inf;
	
	forn (i, n)
	forn (j, m)
		forn (l, 4) {
			int x = i + mx[l];
			int y = j + my[l];
			
			if (valid(x, y)) {
				res = min(res, dis[i][j] + dis[x][y]);
			}
		}
	
	if (res == inf) cout << -1 << endl;
	else cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}