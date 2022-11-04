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

const int MX = 200005, inf = 1e9;
int n, m;
string a[MX];
vi dis[MX];
vii par[MX];

int mx[] = {1, -1, 0, 0};
int my[] = {0, 0, 1, -1};

bool valid (int i, int j) {
	if (i < 0 || i >= n) return 0;
	if (j < 0 || j >= m) return 0;
	
	forn (l, 4) {
		int x = i + mx[l];
		int y = j + my[l];
		
		if (0 <= x && x < n)
		if (0 <= y && y < m)
		if (a[x][y] == '#')
			return 0;
	}
	
	return 1;
}

void main_() {
	cin >> n >> m;
	
	forn (i, n) {
		cin >> a[i];
		
		dis[i] = vi(m, inf);
		par[i] = vii(m, {-1, -1});
	}
	
	priority_queue<vi, vvi, greater<vi>> q;
	forn (i, n)
		if (valid(i, m - 1)) {
			dis[i][m - 1] = a[i][m - 1] == '.';
			q.push({dis[i][m - 1], i, m - 1});
		}
	
	while (q.size()) {
		int d = q.top()[0];
		int i = q.top()[1];
		int j = q.top()[2];
		q.pop();
		
		if (d != dis[i][j]) continue;
		
		for (int x = i - 1; x <= i + 1; x += 2)
		for (int y = j - 1; y <= j + 1; y += 2) {
			if (valid(x, y)) {
				int w = dis[i][j] + int(a[x][y] == '.');
				
				if (dis[x][y] > w) {
					dis[x][y] = w;
					par[x][y] = {i, j};
					q.push({w, x, y});
				}
			}
		}
	}
	
	int mn = inf, ri, rj;
	forn (i, n) {
		if (dis[i][0] < mn) {
			mn = dis[i][0];
			ri = i;
			rj = 0;
		}
	}
	
	if (mn == inf) {
		cout << "NO" << endl;
		return;
	}
	
	while (ri != -1) {
		a[ri][rj] = '#';
		tie(ri, rj) = par[ri][rj];
	}
	
	cout << "YES" << endl;
	forn (i, n)
		cout << a[i] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}