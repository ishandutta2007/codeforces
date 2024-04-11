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
	int a, b, c, d;
	st () {}
	st (ii a, ii b) :
		a(a.fi), b(a.se), c(b.fi), d(b.se) {}

	void pri () {
		cout << a+1 << " " << b+1 << " " << c+1 << " " << d+1 << endl;
	}
};

const int MX = 305;
int n, m;
string a[MX][MX], b[MX][MX];
ii o[MX];
vector<st> res;

void move (ii a, ii b) {
	if (a.fi != b.fi) res.emplace_back(a, ii(b.fi, a.se));
	if (a.se != b.se) res.emplace_back(ii(b.fi, a.se), b);
}

void move (ii a, ii b, ii c) {
	if (a != b) res.emplace_back(a, b);
	if (b != c) res.emplace_back(b, c);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	forn (i, n) forn (j, m) {
		cin >> a[i][j];
		reverse(all(a[i][j]));
	}

	forn (i, n) forn (j, m) {
		cin >> b[i][j];
		reverse(all(b[i][j]));
	}

	o['0'] = {0, 0};
	o['1'] = {n-1, m-1};

	//ini 1
	for (char h : a[0][0]) move({0, 0}, {n-1, 0});
	a[n-1][0] += a[0][0];
	a[0][0].clear();

	for (char h : a[n-1][m-1]) move({n-1, m-1}, {n-1, 0});
	a[n-1][0] += a[n-1][m-1];
	a[n-1][m-1].clear();

	//ini 2
	for (char h : a[n-1][0]) move({n-1, 0}, o[h]);
	a[n-1][0].clear();

	for (char h : a[0][m-1]) move({0, m-1}, o[h]);
	a[0][m-1].clear();
	
	//ini 3
	forn (i, n) {
		for (char h : a[i][0])
			if (h == '0') move({i, 0}, o[h]);
			else move({i, 0}, {n-1, 0}, o[h]);

		for (char h : a[i][m-1])
			if (h == '0') move({i, m-1}, {0, m-1}, o[h]);
			else move({i, m-1}, o[h]);
	}

	forn (i, m) {
		for (char h : a[0][i])
			if (h == '0') move({0, i}, o[h]);
			else move({0, i}, {0, m-1}, o[h]);

		for (char h : a[n-1][i])
			if (h == '0') move({n-1, i}, {n-1, 0}, o[h]);
			else move({n-1, i}, o[h]);
	}

	//ini 4
	forr (i, 1, n-2) forr (j, 1, m-2)
		for (char h : a[i][j]) move({i, j}, o[h]);

	//fin 1
	for (char h : b[0][0]) move(o[h], {n-1, 0}, {0, 0});
	for (char h : b[n-1][m-1]) move(o[h], {n-1, 0}, {n-1, m-1});

	//fin 4
	forr (i, 1, n-2) forr (j, 1, m-2)
		for (char h : b[i][j]) move(o[h], {i, j});

	//fin 3
	forn (i, n) {
		if (i && i < n-1) {
			for (char h : b[i][0])
				if (h == '0') move(o[h], {i, 0});
				else move(o[h], {n-1, 0}, {i, 0});
		}

		if (i && i < n-1) {
			for (char h : b[i][m-1])
				if (h == '0') move(o[h], {0, m-1}, {i, m-1});
				else move(o[h], {i, m-1});
		}
	}

	forn (i, m) {
		if (i && i < m-1)
			for (char h : b[0][i])
				if (h == '0') move(o[h], {0, i});
				else move(o[h], {0, m-1}, {0, i});

		if (i && i < m-1)
			for (char h : b[n-1][i])
				if (h == '0') move(o[h], {n-1, 0}, {n-1, i});
				else move(o[h], {n-1, i});
	}

	//fin 2
	for (char h : b[n-1][0]) move(o[h], {n-1, 0});
	for (char h : b[0][m-1]) move(o[h], {0, m-1});

	cout << res.size() << endl;
	for (auto r : res) r.pri();

	return 0;
}