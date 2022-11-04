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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000005;
int n, m, t, /*p[MX],*/ dis[MX], f = 1;
char a[1005][1005];
int mx[] = {1, -1, 0, 0};
int my[] = {0, 0, 1, -1};
bitset<MX> ini;
queue<int> q;

#define num(i,j) ((i) * m + (j))

/*int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

void join (int a, int b) {
	p[parent(a)] = parent(b);
}*/

bool valid (int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dis, -1, sizeof(dis));
	
	cin >> n >> m >> t;
	forn (i, n) cin >> a[i];

	//iota(p, p + n * m, 0);

	forn (i, n) forn (j, m) forn (l, 4) {
		int x = i + mx[l];
		int y = j + my[l];

		if (valid(x, y) && a[i][j] == a[x][y]) {
			//join(num(i, j), num(x, y));
			ini[num(i, j)] = 1;
			ini[num(x, y)] = 1;
			f = 0;
		}
	}

	forn (i, n) forn (j, m) if (ini[num(i, j)]) {
		q.push(num(i, j));
		dis[num(i, j)] = 0;
	}

	while (q.size()) {
		int i = q.front() / m;
		int j = q.front() % m;
		q.pop();

		forn (l, 4) {
			int x = i + mx[l];
			int y = j + my[l];

			if (valid(x, y) && dis[num(x, y)] == -1) {
				dis[num(x, y)] = dis[num(i, j)] + 1;
				q.push(num(x, y));
			}
		}
	}

	while (t--) {
		int i, j;
		ll p;

		cin >> i >> j >> p;
		i--, j--;

		if (f || dis[num(i, j)] >= p) cout << a[i][j] << endl;
		else {
			int res = a[i][j] - '0';
			p -= dis[num(i, j)];
			cout << (res ^ (p % 2)) << endl;
		}
	}

	return 0;
}