#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

struct st {
	int x, y, k, f;
	ii d;
	st (int x, int y, int k, int f, ii d) : x(x), y(y), k(k), f(f), d(d) {}
	bool operator < (const st &ot) const { return d > ot.d; }
};

ii operator + (ii a, ii b) { return {a.fi + b.fi, a.se + b.se}; }

int n, a[12][12], sx, sy;
ii dp[12][12][105][3];
priority_queue<st> pq;
int mx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int my[] = {1, -1, 1, -1, 2, -2, 2, -2};

void valid (int i, int j, int k, int f, ii d) {
	if (0 <= i && i < n && 0 <= j && j < n && (dp[i][j][k][f].fi == -1 || dp[i][j][k][f] > d))
		pq.emplace(i, j, k, f, dp[i][j][k][f] = d);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	forn(i,12)forn(j,12)forn(k,105)forn(f,3) dp[i][j][k][f] = {-1, -1};

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) sx = i, sy = j;
		}

	for (int i = 0; i < 3; i++)
		pq.emplace(sx, sy, 1, i, dp[sx][sy][1][i] = {0, 0});

	while (pq.size()) {
		st s = pq.top();
		pq.pop();

		if (s.k > n * n) {
			cout << s.d.fi << " " << s.d.se << endl;
			break;
		}

		if (dp[s.x][s.y][s.k][s.f] < s.d) continue;

		if (a[s.x][s.y] == s.k) {
			valid(s.x, s.y, s.k+1, s.f, s.d);
			continue;
		}

		if (!s.f)
			for (int l = 0; l < 8; l++)
				valid(s.x+mx[l], s.y+my[l], s.k, s.f, s.d + ii(1, 0));
		else if (s.f == 1)
			for (int l = 0; l < n; l++) {
				valid(s.x, l, s.k, s.f, s.d + ii(1, 0));
				valid(l, s.y, s.k, s.f, s.d + ii(1, 0));
			}
		else
			for (int l = -n; l < n; l++) {
				valid(s.x+l, s.y+l, s.k, s.f, s.d + ii(1, 0));
				valid(s.x+l, s.y-l, s.k, s.f, s.d + ii(1, 0));
			}

		for (int i = 0; i < 3; i++)
			valid(s.x, s.y, s.k, i, s.d + ii(1, 1));
	}

	return 0;
}