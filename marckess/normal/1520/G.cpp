#include <bits/stdc++.h>

//#define endl '\n'
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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 2005;
int n, m, t, a[MX][MX];
int mx[] = {1, -1, 0, 0};
int my[] = {0, 0, 1, -1};
ll dis[MX * MX];
priority_queue<ii, vii, greater<ii>> pq;

int num (int i, int j) {
	return i * m + j;
}

void upd (int v, ll w) {
	if (dis[v] == -1 || dis[v] > w)
		pq.emplace(dis[v] = w, v);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> t;
	forn (i, n)
		forn (j, m)
			cin >> a[i][j];
	
	memset(dis, -1, sizeof(dis));
	pq.emplace(dis[0] = 0, 0);
	
	while (pq.size()) {
		int u = pq.top().se;
		ll d = pq.top().fi;
		pq.pop();
		
		if (dis[u] < d) continue;
		
		if (u == MX * MX - 1) {
			forn (i, n)
				forn (j, m)
					if (a[i][j] > 0)
						upd(num(i, j), d + a[i][j]);
		} else {
			int i = u / m;
			int j = u % m;
			
			forn (l, 4) {
				int x = i + mx[l];
				int y = j + my[l];
				
				if (0 <= x && x < n && 0 <= y && y < m && a[x][y] != -1)
					upd(num(x, y), d + t);
			}
			
			if (a[i][j] > 0)
				upd(MX * MX - 1, d + a[i][j]);
		}
	}
	
	cout << dis[num(n - 1, m - 1)] << endl;
		
	return 0;
}